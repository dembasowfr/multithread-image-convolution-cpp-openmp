#!/usr/bin/python

from PIL import Image
import pylab
import sys
import numpy as np

if __name__ == "__main__":
    
    f = open(sys.argv[1] ,"r")
<<<<<<< HEAD
    shape = list(map(int, f.readline().split()))
    for idx in range(shape[0]):
        im = np.empty(shape=(shape[1], shape[2], shape[3]))
        for i in range(shape[1]):
=======
    # Read the number of images
    shape = list(map(int, f.readline().split()))

    
    for idx in range(shape[0]):
        # Get the image shape and create an empty image
        im = np.empty(shape=(shape[1], shape[2], shape[3]))

        # Read the image
        for i in range(shape[1]):
            
>>>>>>> 3fd407e (Run the project on windows Powershell)
            row = f.readline().split()
            assert(len(row) == shape[2])  # 300
            for j in range(shape[2]):
                im[i][j] = list(map(float, row[j].split(",")))
        result = Image.fromarray(im.astype(np.uint8))
        result.save(sys.argv[2] + "/" + str(idx) + ".bmp")
        f.readline()    # empty line