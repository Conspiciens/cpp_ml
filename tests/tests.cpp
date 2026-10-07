#include <cassert> 
#include "../tensor.h"

void test_ptr_in_vector() {
    std::vector<int> x = {11, 73, 10}; 
    std::vector<int> y = {5, 9, 1}; 
    
    Tensor<int> tensor = Tensor<int>(x, y); 

    for (auto metadata : tensor.header) {
        std::cout << metadata.idx << std::endl; 
    }
}



int main() {
    test_ptr_in_vector();
    return 0; 
} 
