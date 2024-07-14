# Convolutional filter(s) for images

* Images are stored in folder images/. All images should be of the same size.

* Python Imaging Library (PIL) was used to convert images into RGB matrices and to convert filtered matrices back to images. PIL was preferred over other C++ libraries due to ease of use.

## Code structure
  * filter.hpp defines a 3-D convolutinal kernel class with a bias term. It contains some helper functions to allocate memory to tensors and to normalize them.
  * Convolution.hpp defines a convolutional layer. One can set the stride and zero-padding of the filter in this. Also, dimensions of the output layer are calculated automatically.
  * conv2d method takes as argument a 3-D data volume and a list of filters (one filter generates one activation map). For example, applying a 3 x 3 x 3 filter on a 512 x 512 x 3 image (with 1 zero padding and 1 stride) will generate an 2-D output layer of 512 x 512. See example (taken from course [cs231n](http://cs231n.stanford.edu/syllabus.html)).
  ![One filter](./images/one_map.png)
  * List of filters would make the output layer. Shape of output layer as well as the data block is returned by the function conv2d.
  ![Many filter](./images/multi_map.png)
  * main.cpp runs some example filters on a batch of 3 images. It generates 3 filters, one as an edge detector for each color channel (see push\_filter). Then defines
    a convolution layer with given params and applies the layer to each of the images. It then writes the output to a different file.
  *Inside helpers directory, we have make\_mats.py and load\_img.py that are used to generate images\-matrices and vice versa.

```cpp
for (int id = 0; id < num_images; ++id) {
  ...
  auto output = clayer.conv2d(input, filters);
  ...
}
```

## Steps to run
* First and foremost install the required libraries:

```bash
sudo apt update
sudo apt install python3-pip
pip install -r requirements.txt
```

* Compile using make. Build file for convolutional filter demo program is 'main'. See run.sh for a complete run

* The ```run.sh``` file allows us to run both ```makefile``` and the rest of python commands that's going to execute the overall project.
To run the project:
1. First of all make sure that ```run.sh``` has excutable permissions:

```bash
chmod +x run.sh
```
2. Run the ```run.sh``` file:


```bash
./run.sh
```

```bash
rm *.o main
g++  -std=gnu++11 -O2 filter.hpp -o filter.o
g++  -std=gnu++11 -O2 conv2d_layer.hpp -o conv2d_layer.o
g++  -std=gnu++11 -O2 main.cpp -o main
```

* List of images to use is in file make\_mats.py. In the demo it uses a batch of 3  512 \* 512 \* 3 (color) images.

```bash
python3 make_mats.py img_mats/out.dat
```

* Run the convolutional filter (read from standard input)

```bash
./main img_mats/out.dat img_mats/filter_out.dat < filter.txt
```

* Make output images from matrices

```bash
python3 load_img.py img_mats/filter_out.dat out_mats
```

## Results

You can checkout the image results in the out_mats directory. The output images are generated by applying a filter to the input images. 
The filter is defined in filter.txt, which is the given kernel with 1/273 normalization factor. So the Matrix is stored on the file after normalization.

The output images are stored in out_mats inside output directory.

