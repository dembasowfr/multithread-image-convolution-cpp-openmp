#!/usr/bin/python
'''
This script reads the matrix format and converts it back to images using the PIL library.

'''
from PIL import Image
import pylab
import sys
import numpy as np

if __name__ == "__main__":
    
    f = open(sys.argv[1] ,"r")

    shape = list(map(int, f.readline().split()))
    
    for idx in range(shape[0]):
        # Get the image shape and create an empty image
        im = np.empty(shape=(shape[1], shape[2], shape[3]))

        for i in range(shape[1]):
            
            row = f.readline().split()
            assert(len(row) == shape[2])  # 300
            for j in range(shape[2]):
                im[i][j] = list(map(float, row[j].split(",")))


        result = Image.fromarray(im.astype(np.uint8))

        result.save(sys.argv[2] + "/" + "result"+str(idx) + ".bmp")
        
        f.readline()    # empty line