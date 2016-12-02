
#pragma once
#ifndef SIMPLE_STRUCTURES_HEAPSORT_HPP
#define SIMPLE_STRUCTURES_HEAPSORT_HPP

#include <stddef.h>

namespace simple {
    namespace sort {
        template <typename T>
        struct Min {
            bool operator()(const T &lhs, const T &rhs) const {
                return lhs < rhs;
            }
        };

        template <typename T>
        struct Max {
            bool operator()(const T &lhs, const T &rhs) const {
                return lhs > rhs;
            }
        };
    }
    
    template <typename T, typename CmpType>
    void siftdown(T *array, size_t count, size_t start, CmpType cmp) {
        size_t child, swap;
        T temp;
        // While we have a left child
        while((child = (start * 2 + 1)) < count) {
            swap = start;
            // Check left child
            if(cmp(array[swap], array[child])) {
                swap = child;
            }
            // Check right child, if it exists
            if(((child + 1) < count) && cmp(array[swap], array[child + 1])) {
                swap = child + 1;
            }

            // If swap == start, then we are finished
            if(swap == start) {
                return;
            }else {
                // Otherwise, swap them and set start to our new child
                temp = array[swap];
                array[swap] = array[start];
                array[start] = temp;
                start = swap;
            }
        }
    }
    
    template <typename T, typename CmpType>
    void heapify(T *array, size_t count, CmpType cmp) {
        // Get last parent index; We use count - 2 because the last element is
        // at count - 1, so the formula ((index - 1) / 2) expands to
        // (((count - 1) - 1) / 2)
        size_t i = (count - 2) / 2;
        while(i > 0) {
            siftdown<T, CmpType>(array, count, i, cmp);
            i -= 1;
        }
        // Siftdown the first element (missed by the loop above)
        siftdown<T, CmpType>(array, count, 0, cmp);
    }
    
    template <typename T, typename CmpType>
    T & popheap(T *array, size_t count, CmpType cmp) {
        if(count > 1) {
            T temp = array[0];
            array[0] = array[count - 1];
            array[count - 1] = temp;
            
            // After the swap, restore heap property
            siftdown<T, CmpType>(array, count - 1, 0, cmp);
        }
        return array[count - 1];
    }
    
    template <typename T, typename CmpType>
    void heapsort(T *array, size_t count, CmpType cmp = sort::Min<T>()) {
        heapify<T, CmpType>(array, count, cmp);
        for(size_t i = 0; i < count; ++i) {
            // Pop the topmost element to the back, decrement count
            popheap<T, CmpType>(array, count - i, cmp);
        }
    }
}

#endif
