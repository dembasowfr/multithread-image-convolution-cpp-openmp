#ifndef CONVOLUTION_H
#define CONVOLUTION_H

#include <vector>
#include <tuple>
#include "Filter.hpp"

class Convolution {
  
  int in_width, in_height, in_depth, n_filters, window, stride, padding, out_width, out_height, out_depth;

public:

  // Constructor
  Convolution(int _width, int _height, int _depth, int _window, int _stride = 1, int _padding = 0, int n_filters = 1);

  // Applies convolutional filters in filters to input volume x
  // x treated as in_width * in_height * in_depth 
  // assumed n_filters elements in filters vector
  // returns shape of the output volume and pointer to the memory block
  std::tuple<int, int, int, double ***> conv2d(double ***x, const std::vector<Filter*> &filters);

  // Destructor
  ~Convolution();
};

#endif
