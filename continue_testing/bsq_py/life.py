''' 
| - life.py
'''
import time
import numpy as np
import os

TIME = 0.03

def _neighbors(x,y, size_x, size_y):
    _neighs = []
    _neighs.append([(x+1)%size_x, y])
    _neighs.append([(x-1)%size_x, y])
    _neighs.append([x, (y+1)%size_y])
    _neighs.append([x, (y-1)%size_y])
    _neighs.append([(x+1)%size_x, (y+1)%size_y])
    _neighs.append([(x-1)%size_x, (y+1)%size_y])
    _neighs.append([(x+1)%size_x, (y-1)%size_y])
    _neighs.append([(x-1)%size_x, (y-1)%size_y])
    return _neighs

def life(prev,size_x, size_y):
    _curr = np.copy(prev)
    for ix, row in enumerate(prev):
        for iy, cel in enumerate(row):
            #find neighbors
            _neighs = _neighbors(ix,iy,size_x,size_y)  
            count = 0

            #neighbors count
            for neigh in _neighs:
                if prev[neigh[0]][neigh[1]] != 0:
                    count += 1

            #game of life rules
            if cel != 0: 
                if count == 2 or count == 3:
                    _curr[ix][iy] = 1
                else:
                    _curr[ix][iy] = 0
            else:
                if count == 3:
                    _curr[ix][iy] = 1
                else:    
                    _curr[ix][iy] = 0
    return _curr        

def _show_data(data, usechar):
        for row in data:
            for col in row:
                if col > 0:
                    if usechar:
                        print(usechar, end='')
                    else:
                        print(int(col), end='')
                else:
                    print(" ", end='')
            print("")

if __name__ == "__main__":
    
    
    columns, rows = os.get_terminal_size(0)
    data = np.zeros( (rows, columns))
    subdata = np.array([ "                                                 ",
                         "                                                 ",
                         "                                                 ",
                         "                                                 ",
                         "                                                 ",
                         "                                                 ",
                         "                         1                       ",
                         "                       1 1                       ",
                         "             11      11            11            ",
                         "            1   1    11            11            ",
                         " 11        1     1   11                          ",
                         " 11        1   1 11    1 1                       ",
                         "           1     1       1                       ",
                         "            1   1                                ",
                         "             11                                  ",
                         "                                                 ",] )

    #function for copying submatrices in data                  
    for ix, row in enumerate(subdata):
        for iy, char in enumerate(row):
            if char == " ":
                char = "0"

            data[ix][iy] = int(char)


    # ugly time evolution simulation
    _show_data(data, '+')
    time.sleep(TIME)
    while 1:

        columns, rows = os.get_terminal_size(0)
        while rows < len(subdata):
            print("screen is too small to play, ass")
        while columns < len(subdata[0]):
            print("screen is too small to play, ass")

        data = life(data, rows, columns)
        _show_data (data ,'+')
        time.sleep(TIME)
