''' 
| - gather.py
'''
from translator.im2mat import im2mat 
from islands import islands
from parprocess import parprocess
import json
import matplotlib.pyplot as plt

class gather():
    def __init__(self, imagepath, slices=100):

        #store original imagepath
        self.src = imagepath

        #store parameter 
        self.slices = slices

        #store processed image
        self.image = im2mat(imagepath, slices)

        #store analyzed islands
        self.processed = parprocess(self.image, range(slices), 4)

        #islands and analysis are lists
        self.isles    = []
        self.analysis = []

        #get images and analysis from processed data
        for item in self.processed:         
            self.isles   .append( item[0] )
            self.analysis.append( item[1] )



    def show_image(self):
        imgplot = plt.imshow(self.image)
        plt.show()

    def show_island(self, level = None):
        imgplot = plt.imshow(self.isles[level].isles)
        plt.show()
    
    def toJSON(self):
        return json.dumps(self, default=lambda o: o.__dict__, 
            sort_keys=True, indent=4)

if __name__ == "__main__":
    from translator.container2file import container2file
    container = gather("dataset/vader.png", 10)
    #container.show_image()
    container.show_island(5)
    container2file(container, "dataset/vader_container.bsqc")



