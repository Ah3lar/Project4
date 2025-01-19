#include <iostream>
#include "Array.h"

int main() {
    Array arr1(10);
    arr1.display();

    Array arr2(10, true);
    arr2.display();

    Array arr3(10, 1, 50);
    arr3.display();

    Array arr4 = arr3;
    arr4.display();

    arr1.fillRandom();
    arr1.display();

    arr1.resize(15);
    arr1.display();

    arr1.sort();
    arr1.display();

    std::cout << "Min value: " << arr1.min() << std::endl;
    std::cout << "Max value: " << arr1.max() << std::endl;

    return 0;
}