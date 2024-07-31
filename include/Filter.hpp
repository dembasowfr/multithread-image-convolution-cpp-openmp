#ifndef FILTER_HPP
#define FILTER_HPP  

#include <cmath>

// allocate memory for a tensor
double ***get_tensor(int x, int y, int z);

class Filter {

  public:

    double ***w, b;     // kernel matrix, bias term
    int window, depth;

    // Constructors
    Filter(int _window, int _depth);

    // constructor with kernel matrix and bias term
    Filter(double ***_w, int _window, int _depth, int _b = 0);


    // normalize the tensor
    void normalize();


    // Destructor
    ~Filter();

    


};

#endif