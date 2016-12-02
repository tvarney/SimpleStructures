
#pragma once
#ifndef SIMPLE_STRUCTURES_PRINT_HPP
#define SIMPLE_STRUCTURES_PRINT_HPP

#include <stddef.h>
#include <iostream>
#include <vector>

namespace simple {
    template <typename T>
    void print_array(const T *array, size_t length) {
        std::cout << "[";
        if(length > 1) {
            for(size_t i = 0; i < length - 2; ++i) {
                std::cout << array[i] << ", ";
            }
            std::cout << array[length - 1];
        }else {
            std::cout << array[0];
        }
        std::cout << "]";
    }
    
    template <typename T>
    void print_vector(const std::vector<T> &vec) {
        print_array(vec.data(), vec.size());
    }
}

#endif
