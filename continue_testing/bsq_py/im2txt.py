''' 
| - im2txt.py
'''

from matplotlib.pyplot import imread as imread

def _pixel_val(triplet):
    norm =  1
    multi = 9
    return multi - (triplet[0] + triplet[1] + triplet[2]) * multi / 3

def im2txt(image, outfile, printit=False):
    for row in image:
        for col in row:
            outfile.write(str(int(_pixel_val(col)))+ " ")
            if printit:    
                print(str(int(_pixel_val(col))) +  "" , end='')
        if printit:
            print(" ")
        outfile.write("\n")

if __name__ == "__main__":

    image = imread('dataset/cropdata.png')
    outfile = open("dataset/test01.txt","w")
    im2txt(image, outfile, "yes, please")
    outfile.close()    
