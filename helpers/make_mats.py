#!/usr/bin/python
'''
This script converts images into a matrix format and saves the data to a file using the PIL library.
The first argument is the output file name and the second argument is the folder name containing the images.
The images are assumed to be:
1. 300x300 pixels in size.
2. in the PNG format.
3. in the RGB format.
4. in the 8-bit format.
4. in the sRGB color space.
5. square.
6. in the same folder.

'''

import numpy as np
from PIL import Image
import pylab
import sys
import os

dirname = 'input/'
#colored = ["airplane.png", "lena.png",  "fruits.png"] should be 300 * 300 * 3 = (300, 300, 3)
#gray = ["cloud.png", "horse.png", "moon.png", "view.png"] # should be 300 * 300 * 1 = (300, 300)

def append_matrix(filepath, outf):
    img = Image.open(filepath)
    im = np.asarray(img, dtype='float64')
    #print(im.shape)
    for i in range(im.shape[0]):
        for j in range(im.shape[1]):
            outf.write("%f,%f,%f " %(im[i][j][0], im[i][j][1], im[i][j][2]))
        outf.write('\n')
    outf.write('\n')

if __name__ == "__main__":
    f = open(sys.argv[1], "w")

    # 3 for color, 1 for grey
    #depth = 3   
    depth = 3

    foldername = dirname + 'grey/' # grey for grey folder(which actually contains colored images)

    filenames = os.listdir(foldername)
    f.write("%d 300 300 %d\n" % (len(filenames), depth)) # image tensor dimensions

    for filename in filenames:
        append_matrix(foldername + filename, f)
