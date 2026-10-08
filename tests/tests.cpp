#include <cassert> 
#include "../tensor.h"

// void test_ptr_in_vector() {
//     std::vector<int> x = {11, 73, 10}; 
//     std::vector<int> y = {5, 9, 1}; 
//     
//     Tensor<int> tensor = Tensor<int>(x, y); 
// 
//     for (auto metadata : tensor.header) {
//         std::cout << metadata.idx << std::endl; 
//     }
// }

void test_reshape() {
    std::vector<int> x = {11, 73, 10, 8, 6, 1}; 
    // std::vector<int> y = {2, 3, 1, 9, 0, 3}; 

    Tensor<int> tensor = Tensor<int>(x); 
    tensor.print();
    std::cout << "\n\n"; 
    // auto t2 = std::make_tuple(2, 3);
    std::vector<int> t2 = {2, 3};

    tensor.reshape(t2); 
    tensor.print(); 
}


int main() {
    // test_ptr_in_vector();
    test_reshape();
    return 0; 
} 
