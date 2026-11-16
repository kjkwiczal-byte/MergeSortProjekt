#include <iostream>
#include <vector>
#include "MergeSort.h"

template <typename T>
void printArray(const std::vector<T>& arr) {
    for (const T& val : arr) {
        std::cout << val << " ";
    }
    std::cout << "\n";
}

int main() {
    // 1. Instancja dla liczb całkowitych (int)
    std::vector<int> intArr = {38, 27, 43, 3, 9, 82, 10};
    MergeSort<int> intSorter;

    std::cout << "Tablica int przed sortowaniem: ";
    printArray(intArr);

    intSorter.sort(intArr);

    std::cout << "Tablica int po sortowaniu:     ";
    printArray(intArr);

    std::cout << "----------------------------------------\n";

    // 2. Instancja dla liczb zmiennoprzecinkowych (double)
    std::vector<double> doubleArr = {4.5, -1.2, 3.14, 0.0, 2.71, -9.8};
    MergeSort<double> doubleSorter;

    std::cout << "Tablica double przed sortowaniem: ";
    printArray(doubleArr);

    doubleSorter.sort(doubleArr);

    std::cout << "Tablica double po sortowaniu:     ";
    printArray(doubleArr);

    return 0;
}