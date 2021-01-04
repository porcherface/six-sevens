''' 
| - im2txt.py
'''

from matplotlib.pyplot import imread as imread

def _pixel_val(triplet, multi):
    return multi - (triplet[0] + triplet[1] + triplet[2]) * multi / 3

def im2txt(image, outfile, multi=9, printit=False):
    for row in image:
        for col in row:
            outfile.write(str(int(_pixel_val(col, multi)))+ " ")
            if printit:    
                print(str(int(_pixel_val(col, multi))) +  "" , end='')
        if printit:
            print(" ")
        outfile.write("\n")

if __name__ == "__main__":
    image = imread('dataset/spirals_1.png')
    outfile = open("dataset/test02.txt","w")
    im2txt(image, outfile, 9, "yes, please")
    outfile.close()    
