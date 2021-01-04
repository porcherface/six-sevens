''' 
| - process.py
'''
from islands import islands as islands
from analyze import analyze as analyze

from joblib import Parallel, delayed

import multiprocessing
import time
import numpy as np


def _estimate_ta(data_size, slices):
    num_cores = multiprocessing.cpu_count()
    print("detected {} cores".format(num_cores))

    reference_time = 22.07 * 4 # a 91x91 picture (cropdata.png), 256 slices on 4 cores
    ref_sliced = reference_time / 256
    ref_resized = ref_sliced / (91*91)
    print("estimated time awaiting is ", str( ref_resized * data_size * slices / num_cores )  )
    return num_cores

def _process_data(data, parameter):
    output = islands(np.copy(data))
    output.set_sea(parameter)
    output.find_islands()
    parsed_output = analyze(output.get_islands())
    return (output, parsed_output)

def parprocess(data, parameter, num_cores):
    return Parallel(n_jobs=num_cores)(delayed(_process_data)(data, i) for i in parameter)


if __name__ == "__main__":

    from translator.im2mat import im2mat
    #from translator.txt2mat import txt2mat

    slices = 10
    seas = range(slices) 
    data = im2mat("dataset/vader.png", slices)
    #data = im2mat("dataset/cropdata.png", slices)

    start = time.time()
    size = len(data[0])*len(data)
    num_cores = _estimate_ta(size, slices)

    # serial vs parallel resulted in parallel twice as fast for a 256 91x91 analysis
    result = parprocess(data, seas, num_cores)
    
    for item in result:
        item[1].show()

    end = time.time()
    print("Parallel: elapsed time is {}s ".format(end-start))
    

