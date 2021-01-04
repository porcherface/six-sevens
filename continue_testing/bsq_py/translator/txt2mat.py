''' 
| - txt2mat.py
'''

import numpy as np

def txt2mat(txtname="dataset/test01.txt"):
    return np.loadtxt(txtname, dtype=np.uint8)
