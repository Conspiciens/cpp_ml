#pragma once 

#ifndef TENSOR_H
#define TENSOR_H 

#include <iostream> 
#include <cmath> 
#include <vector> 
#include <algorithm> 
#include <numeric> 
#include <functional>
#include <tuple> 

/* 
    Initially wanted to use pointers, however vector has memory allocations 
    that might change the order of memory, so switched over to idx
*/
struct Header {
    size_t idx; 
    std::vector<int> shape;  
    std::vector<int> strides; 
}; 

template<typename T> 
class Tensor {
    public: 
        Header header; 
        std::vector<T> data; 


        Tensor(std::vector<T> x); 
        Tensor(std::vector<T> x, std::vector<T> y); 

        void reshape(std::vector<int> shape); 
        void print(); 
        
    private: 
}; 


template<typename T> 
Tensor<T>::Tensor(std::vector<T> x) {
    this->data = x; 
    
    this->header.idx = 0; 
    this->header.shape.push_back(x.size());
    this->header.strides = {1};
} 

/* 
    [xxxxxxx] [yyyyyyy] 
    x x x x 
    y y y y 
    Note: Must be homegenous (or the same type) 
    
*/ 

template<typename T> 
Tensor<T>::Tensor(std::vector<T> x, std::vector<T> y) {
    /* TODO: Throw error if vectors are not the same length */
    this->data = x; 
    std::copy(y.begin(), y.end(), std::back_inserter(this->data));

    this->header.idx = 0; 
    this->header.shape = {2, x.size()}; 

    /* 
        2 and 3 

        xxx
        xxx
    
    */
    this->header.strides = {x.size(), 1}; 
} 

template<typename T>
void Tensor<T>::reshape(std::vector<int> shape) {
 
    int num_of_items = std::accumulate(shape.begin(), shape.end(), 1, std::multiplies<int>()); 
 
    if (this->data.size() != num_of_items) {
        throw std::runtime_error("Unable to shape"); 
    }
 
    this->header.shape = shape;  

    int size = shape.back(); 
    std::vector<int> new_stride = {1};
    for (size_t i = 0; i < header.shape.size(); i++) {
        new_stride.push_back(size);
        size *= 3; 
    }
    this->header.strides = new_stride; 
}

/* 
    1 2 
    1 2 



*/
template<typename T>
void Tensor<T>::print() {
    for (size_t idx = 0; idx < this->data.size(); idx++) {
        if (idx != 0) {
            for (auto& stride : this->header.strides) {
                if (idx % stride == 0 && stride != 1) 
                    std::cout << std::endl;
            }
        }
        std::cout << this->data[idx] << " "; 
    }
}

#endif 
