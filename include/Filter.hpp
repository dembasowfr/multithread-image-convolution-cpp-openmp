#ifndef FILTER_HPP
#define FILTER_HPP  

#include <cmath>

// allocate memory for a tensor
double ***get_tensor(int x, int y, int z);

class Filter {
public:
  double ***w, b;     // kernel matrix, bias term
  int window, depth;

<<<<<<< HEAD
  Filter(int _window, int _depth);
  Filter(double ***_w, int _window, int _depth, int _b = 0);
=======
  Filter(int _window, int _depth); // Parametreless constructor
  Filter(double ***_w, int _window, int _depth, int _b = 0); // constructor with kernel matrix and bias term
>>>>>>> 3fd407e (Run the project on windows Powershell)
  ~Filter();

  // normalize the tensor
  void normalize();
};

#endif