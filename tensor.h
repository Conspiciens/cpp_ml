#pragma once 

#ifndef TENSOR_H
#define TENSOR_H 

#include <iostream> 
#include <cmath> 
#include <vector> 
#include<algorithm> 

/* 
    Initially wanted to use pointers, however vector has memory allocations 
    that might change the order of memory, so switched over to idx
*/
struct Header {
    size_t idx; 
    size_t len;  
}; 

template<typename T> 
class Tensor {
    public: 
        std::vector<Header> header; 
        std::vector<T> data; 

        Tensor(std::vector<T> x); 
        Tensor(std::vector<T> x, std::vector<T> y); 
        
    private: 
}; 


template<typename T> 
Tensor<T>::Tensor(std::vector<T> x) {
        this->data = x; 
        this->header.push_back(
         Header { .ptr = &this->data, .len = x.size() }
        ); 
} 

/* 
    [xxxxxxx] [yyyyyyy] 
    x x x x 
    y y y y 
    Note: Must be homegenous (or the same type) 
    
*/ 

template<typename T> 
Tensor<T>::Tensor(std::vector<T> x, std::vector<T> y) {
        this->data = x; 
        this->header.push_back(
             Header { .idx = 0, .len = x.size() }
        ); 
        
        std::copy(y.begin(), y.end(), std::back_inserter(this->data));
        this->header.push_back(
            Header { .idx = x.size(), .len = y.size() } 
        );   
} 

// template<typename T>
// Tensor<T>::Tensor(int idx, Tensor<T> new_arr, int axis) {
// 
// }

#endif 
