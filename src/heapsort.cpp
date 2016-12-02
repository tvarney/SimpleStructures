
#include <vector>
#include <cstdlib>
#include <cstdio>

#include "heapsort.hpp"
#include "print.hpp"

using namespace simple;

int main(int argc, char **argv) {
    std::vector<double> values;
    values.reserve(argc - 1);
    
    char *end;
    double temp;
    for(int i = 1; i < argc; ++i) {
        temp = std::strtod(argv[i], &end);
        if(*end != 0) {
            std::printf("Invalid value: %s\n", argv[i]);
        }else {
            values.push_back(temp);
        }
    }

    double *array = values.data();
    size_t len = values.size();
    std::cout << "Initial: ";
    print_vector(values);
    std::cout << std::endl;
    
    heapsort<double, sort::Min<double>>(array, len);
    //heapify<double, sort::Min<double>>(array, len, sort::Min<double>());
    
    std::cout << "Sorted: ";
    print_vector(values);
    std::cout << std::endl;
    
    return 0;
}
