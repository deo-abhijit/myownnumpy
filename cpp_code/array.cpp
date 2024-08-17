#include <vector>
#include <iostream>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h> 


using namespace std;
namespace py = pybind11;

class Array {
  vector<int> shape ;
  vector<int> stride;

  vector<float> data;
public:
  Array(vector<float> data_, vector<int> stride_, vector<int> shape_) : data(data_), stride(stride_), shape(shape_) {};
  
  void printData() {
    for (float val : data) {
      cout << val << " ";
    }
    cout << endl;
  }
  
};


int main() {
  vector<float> data = {1.0, 2.0, 3.0,4.0};
  vector<int> stride = {1};
  vector<int> shape = {3};

  Array array(data, stride, shape);
  array.printData();

  return 0;};



PYBIND11_MODULE(module_name, module_handle) {
  module_handle.doc() = "I'm a docstring hehe";
  py::class_<Array>(module_handle,"Array").def(
    py::init<vector<float>, vector<int>,vector<int>>()
  );

}