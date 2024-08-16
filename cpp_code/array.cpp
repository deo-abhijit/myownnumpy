#include <vector>
#include <iostream>
using namespace std;

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

  return 0;}