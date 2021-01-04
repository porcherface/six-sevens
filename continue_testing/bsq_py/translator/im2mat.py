''' 
| - im2mat.py
'''

from matplotlib.pyplot import imread as imread
import numpy as np

def _pixel_val(triplet, multi):
    return multi - (triplet[0] + triplet[1] + triplet[2]) * multi / 3

def im2mat(imagepath, multi=256):

    #this should be something like:
    # if imagepath
    image = imread(imagepath)
    size_x = len(image)
    size_y = len(image[0])

    outdata = np.zeros([size_x, size_y], dtype=np.uint8)

    # if image 
    # image = imagepath
    
    for ix, row in enumerate(image):
        for iy, col in enumerate(row):
            outdata[ix][iy] = _pixel_val(col, multi)

    return np.copy(outdata)

if __name__ == "__main__":
    
    data = im2mat("dataset/cropdata.png")
    print(data)