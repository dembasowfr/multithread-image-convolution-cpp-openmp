#include "Filter.hpp"
 
// allocate memory for a tensor

// Explanation of the function get_tensor:
// This function takes in three integers x, y, and z, and returns a 3D tensor of size x*y*z.
// The tensor is a 3D array of doubles, and is allocated on the heap.
// The function first allocates memory for an array of pointers to pointers to pointers of doubles.
// Then, it allocates memory for each row of the tensor, which is an array of pointers to pointers of doubles.
// Finally, it allocates memory for each element of the tensor, which is an array of doubles.
// The function returns the 3D tensor.

// What does tensor mean?
// A tensor is a generalization of scalars, vectors, and matrices to higher dimensions.
// In this case, the tensor is a 3D array of doubles, which is used to store the weights of the filter.


double ***get_tensor(int x, int y, int z) {
  double ***ret = new double**[x];
  for (int i = 0; i < x; i++) {
    ret[i] = new double* [y];
    for (int j = 0; j < y; ++j) {
      ret[i][j] = new double[z];
    }
  }
  return ret;
}

// Constructor
Filter::Filter(int _window, int _depth) : window(_window), depth(_depth) {
  w = get_tensor(window, window, depth); 
}

// Constructor with initial weights
Filter::Filter(double ***_w, int _window, int _depth, int _b) : window(_window), depth(_depth), b(_b) {
  w = get_tensor(window, window, depth); 
  for (int i = 0; i < window; ++i) {
    for (int j = 0; j < window; ++j) {
      for (int k = 0; k < depth; ++k) {
        w[i][j][k] = _w[i][j][k];
      }
    }
  }
}

// Destructor
Filter::~Filter() {
  for (int i = 0; i < window; ++i) {
    for (int j = 0; j < window; ++j) {
      delete[] w[i][j];
    }
    delete[] w[i];
  }
  delete[] w;
}

// normalize the tensor - kernel (normalization factor = sum of absolute values of all elements): 273 in our case
void Filter::normalize() {
  double sum = 0;
  for (int i = 0; i < window; ++i) {
    for (int j = 0; j < window; ++j) {
      for (int k = 0; k < depth; ++k) {
        sum += std::abs(w[i][j][k]);
      }
    }
  }

  for (int i = 0; i < window; ++i) {
    for (int j = 0; j < window; ++j) {
      for (int k = 0; k < depth; ++k) {
        w[i][j][k] /= sum;
      }
    }
  }
}