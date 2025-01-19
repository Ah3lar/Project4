#pragma once

#include <iostream>

class Array {
private:
    int* data;
    size_t size;

public:
    Array(size_t n) : size(n) {
        data = new int[size];
        for (size_t i = 0; i < size; ++i) {
            data[i] = 0;
        }
    }

    Array(size_t n, bool random) : size(n) {
        data = new int[size];
        if (random) {
            for (size_t i = 0; i < size; ++i) {
                data[i] = rand() % 100;
            }
        }
    }

    Array(size_t n, int min, int max) : size(n) {
        data = new int[size];
        for (size_t i = 0; i < size; ++i) {
            data[i] = min + rand() % (max - min + 1);
        }
    }

    Array(const Array& other) : size(other.size) {
        data = new int[size];
        for (size_t i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
    }

    ~Array() {
        delete[] data;
    }

    void display() const {
        for (size_t i = 0; i < size; ++i) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }

    void fillRandom() {
        for (size_t i = 0; i < size; ++i) {
            data[i] = rand() % 100;
        }
    }

    void resize(size_t newSize) {
        int* newData = new int[newSize];
        for (size_t i = 0; i < std::min(size, newSize); ++i) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        size = newSize;
    }

    void sort() {
        for (size_t i = 0; i < size - 1; ++i) {
            for (size_t j = 0; j < size - i - 1; ++j) {
                if (data[j] > data[j + 1]) {
                    std::swap(data[j], data[j + 1]);
                }
            }
        }
    }

    int min() const {
        if (size == 0) return 0;
        int minVal = data[0];
        for (size_t i = 1; i < size; ++i) {
            if (data[i] < minVal) {
                minVal = data[i];
            }
        }
        return minVal;
    }

    int max() const {
        if (size == 0) return 0;
        int maxVal = data[0];
        for (size_t i = 1; i < size; ++i) {
            if (data[i] > maxVal) {
                maxVal = data[i];
            }
        }
        return maxVal;
    }
};