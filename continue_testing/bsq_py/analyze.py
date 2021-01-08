''' 
| - analyze.py
'''
import numpy as np
from bsq import bsq as bsq

class _parameters:
    def __init__(self, label):
        self.label = label 
        self.cells = 0
        self.center = [0, 0]

    def _show(self):
        print("general ", self.label)
        print("island contains ", str(self.cells), " cells")
        print("centroid x: ",str.format('{:.2f}', self.center[0]))
        print("centroid y: ",str.format('{:.2f}', self.center[1]))

# analysis module for islands
class analyze:
    def __init__(self, islands):

        self.copy = np.copy(islands)

        _map = {}
        for ix, row in enumerate(islands):
            for iy, cell in enumerate(row):
                if cell not in _map:
                    _map[cell] = _parameters(cell)

                # count
                _map[cell].cells += 1

                # centroid
                _map[cell].center[0] += ix
                _map[cell].center[1] += iy

        self.objects = []
        for key in _map.keys():
            _map[key].center[0] /= _map[key].cells
            _map[key].center[1] /= _map[key].cells
            self.objects.append(_map[key])
        self.bsq = bsq(islands)


    def show(self, specific = False):
        print("Hello there: ")
        print("- map contains {} islands".format(len(self.objects)))
        if specific:
            for item in self.objects:
                item._show()
        print("bsq is "+str(self.bsq))

    def __str__(self):
        return "- map contains {} islands, bsq @".format(len(self.objects))+str(self.bsq)

if __name__ == "__main__":
    from islands import islands
    from translator.im2mat import im2mat

    isles = islands(im2mat("dataset/vader.png", 9))
    isles.set_sea(6)
    isles.find_islands()
    isles.show_islands()
    analysis = analyze(isles.get_islands())
    analysis.show("yes yes")
    print(str(analysis))






