''' 
| - islands.py
'''

import numpy as np

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

def _charmap(value):
    char_offset = 0x20
    char_top = 0x5e
    char_range = char_top - char_offset
    char_tgt = value % char_range + char_offset
    return chr(char_tgt)

def _load_raw(txtname="dataset/test01.txt"):
    with open(txtname) as file:
       data = file.read()
    return data

def _load_matrix(txtname="dataset/test02.txt"):
    return np.loadtxt(txtname, dtype=np.uint8)

def _find_sink(val, data):
    y = val;

    try:
        data[y] == y
    except:
        print(val)
        print(data)
        print("prot")

    while (data[y] != y):
        y = data[y];
    return y

class islands():
    def __init__(self, src):
        self.data = np.copy(src)
        self.sea = 0

    def set_sea(self, sea):
        self.sea = sea

    def get_sea(self):
        return self.sea
        
    def find_islands(self, data = None):
        if data == None:
            data = self.data
        
        isles = np.copy(data)

        #first pass: raster-labeling
        label = 1
        flag = 0
        for ix, row in enumerate(data):
            for iy, col in enumerate(row):
                if col > self.sea:
                    isles[ix][iy] = label 

        # second pass: union-find on rastered matrix
        label = 0
        _map = {}
        _map[0] = 0
        for ix,row in enumerate(data):
            for iy,col in enumerate(row):
                if col > self.sea:
                    
                    # check for oversea neighbors
                    left = 0
                    top = 0
                    if ix > 0:    
                        left = (data[ix][iy-1] > self.sea)
                    if iy > 0:                
                        top  = (data[ix-1][iy] > self.sea)
                    
                    # case 1, a new island
                    if (left == False) and (top == False):
                        label += 1
                        isles[ix][iy] = label
                        _map[label] = label

                    # case 2 left connection, copy from there
                    elif (top == False):
                        isles[ix][iy] = isles[ix][iy-1]
                        
                    # case 3 connection, copy from there
                    elif (left == False):
                        isles[ix][iy] = isles[ix-1][iy]

                    # case 4, double connection, must link two clusters
                    else:
                        _map[_find_sink(isles[ix][iy-1], _map)] = _find_sink(isles[ix-1][iy], _map)
                        isles[ix][iy] = isles[ix-1][iy]
                else:
                    isles[ix][iy] = 0
        
        # re-generate according to mapping
        for ix,row in enumerate(data):
            for iy,col in enumerate(row):
                if col > self.sea:
                    isles[ix][iy] = _find_sink(isles[ix][iy], _map)

        self.isles = np.copy(isles)

    def show_matrix(self, level = None):
        if level == None:
            level = self.sea
        _show_data(self.data, level, 0)

    def show_islands(self, level = None):
        if level == None:
            level = self.sea
        _show_data(self.isles, 0, 1)

    def get_islands(self):
        return np.copy(self.isles)


if __name__ == "__main__":
    mymap = islands(_load_matrix())
    mymap.set_sea(5)
    mymap.find_islands()
    mymap.show_matrix(-1)
    mymap.show_matrix()
    mymap.show_islands()    
    