#include <vector>
#include <iostream>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h> 

using namespace std;
namespace py = pybind11;

class Array {
    vector<int> shape;
    vector<int> stride;
    vector<float> data;

public:
    // Parameterized constructor
    Array(vector<float> data_, vector<int> stride_, vector<int> shape_) : data(data_), stride(stride_), shape(shape_) {}

    // Default constructor
    Array() {}

    // Addition operator
    Array operator+(Array const& arr) {
        Array ans;
        if (arr.shape == shape) {
            ans.shape = shape;
            for (size_t i = 0; i < data.size(); i++) {
                ans.data.push_back(data[i] + arr.data[i]);
            }
        } else {
            cout << "Addition not possible" << endl;
        }
        return ans;
    }


    char pretty_print(){
      for (auto i:data){
        cout<<i<<" ";

      }
      cout <<endl;
      return '\n';
    }
};

PYBIND11_MODULE(abhijits_numpy, module_handle) {
    module_handle.doc() = "I'm a docstring hehe";
    py::class_<Array>(module_handle, "Array")
        .def(py::init<vector<float>, vector<int>, vector<int>>())  // Constructor binding
        .def("__add__", &Array::operator+
        ).def("__str__", &Array::pretty_print)
        
;  // Addition operator binding
}
