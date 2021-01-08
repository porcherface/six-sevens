''' 
| - bsq.py
'''

import numpy as np
from islands import islands as islands

# bsq purpose: 
# find the biggest square inside a given
# islands map
#
# output will be a square given as (x,y,l)

# CAREFUL, BSQ WILL TREAT AS VALID ANY NONZERO
# PIXEL, DISREGARDING THE FLOODING LEVEL
# IF YOU WANT TO BSQ A FLOODED MAP, IT WILL BE YOUR
# DUTY TO PASS IT 

#a useful debug print (heavily replicated, maybe
#it's worth doing a translator

def _show_data(data, level, usechar):
        for row in data:
            for col in row:
                if col > level:
                    if usechar:
                        print(_charmap(col), end='')
                    else:
                        print(int(col), end='')
                else:
                    print(" ", end='')
            print("")

def bsq(in_data):

    # we make a copy
    # this may be slow but we dont give a single fuck
    isle = in_data

    # we can solve this with a double iteration 
    # over the image
    
    #oh shit this sucks...
    # but maybe we might need two single fors, only first row 
    # and first column have to be processed
    for ix, row in enumerate(isle):
        for iy, cell in enumerate(row):
            if cell != 0:
                isle[ix][iy] = 1
    
    #for for run 
    output =[0 ,0 ,0]

    for ix, row in enumerate(isle):
        for iy, cell in enumerate(row):
            if (ix != 0 or iy != 0) and cell != 0:
                neighs = [isle[ix-1][iy-1] ,isle[ix][iy-1] ,isle[ix-1][iy]]
                isle[ix][iy] = min(neighs) + 1 #top #left # toleft
                if output[0] <isle[ix][iy]: 
                    output[0] = isle[ix][iy]
                    output[2] = ix - output[0]+1
                    output[1] = iy - output[0]+1

    #a useful debug print
    #_show_data(isle,0,0)
    return output
    #now we have fourd the maximal element in this map, coordinates are 
    # x = ix - l
    # y = iy - l
    # l = isle[ix][iy]


#example driver code
if __name__ == "__main__":
    from translator.im2mat import im2mat as im2mat
    mymap = islands(im2mat("dataset/cropdata.png", 9))
    mymap.set_sea(5)
    mymap.find_islands()
    print(bsq(mymap.get_islands()))