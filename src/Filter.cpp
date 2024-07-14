#include "Filter.hpp"
 
// allocate memory for a tensor
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
Filter::Filter(int _window, int _depth) 
  : window(_window), depth(_depth) {
  w = get_tensor(window, window, depth); 
}

// Constructor with initial weights
Filter::Filter(double ***_w, int _window, int _depth, int _b) 
  : window(_window), depth(_depth), b(_b) {
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

// normalize the tensor
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
