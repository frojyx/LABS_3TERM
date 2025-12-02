#pragma once

#include "../includes/array.h"

template <typename T>
class Algorithm {
public:
    bool find(const Array<T>& arr, const T& value) const;
    void sort(Array<T>& arr) const;
};

template <typename T>
void Algorithm<T>::sort(Array<T>& arr) const {
    size_t size = arr.Size();

    for (size_t i = 1; i < size; i++) {
        T keyValue = arr[i];
        size_t insertPos = i;

        while (insertPos > 0 && arr[insertPos - 1] > keyValue) {
            arr[insertPos] = arr[insertPos - 1];
            insertPos--;
        }
        arr[insertPos] = keyValue;
    }
}

template <typename T>
bool Algorithm<T>::find(const Array<T>& arr, const T& value) const {
    if (arr.empty()) {
        return false;
    }

    size_t left = 0;
    size_t right = arr.Size() - 1;

    while (left <= right) {
        size_t mid = (right + left) / 2;

        if (arr[mid] == value) {
            return true;
        }

        if (value > arr[mid]) {
            left = mid + 1;
        }
        else if (value < arr[mid]) {
            right = mid - 1;
        }
        else {
            break;
        }
    }

    return false;
}
