#pragma once
#include <vector>
#include <iostream>
template<typename T>
class CircularBufferVector {
private:
    size_t length = 0;
    std::vector<T> vector;
    size_t front = 0;
    size_t back = 0;
    size_t bufferSize = 0;
public:
    CircularBufferVector(const size_t& bufferSize) : vector(bufferSize), bufferSize(bufferSize) {}
    bool empty() { return length == 0; }
    bool full() { return length == bufferSize; }
    void push(const T& element) {
        vector[front] = element;
        front = (front + 1) % bufferSize;
        if (!full()) {
            ++length;
        }
        else {
            back = (back + 1) % bufferSize;
        }
    }
    T pop() {
        if (empty()) throw std::runtime_error("Buffer is empty");
        T elem = vector[back];
        back = (back + 1) % bufferSize;
        --length;
        return elem;
    }
    T top() {
        if (empty()) throw std::runtime_error("Buffer is empty");
        return vector[back];
    }
    void print() {
        if (empty()) return;
        size_t index = back;
        size_t count = 0;
        do {
            std::cout << vector[index] << " ";
            ++count;
            index = (index + 1) % bufferSize;
        } while (count < length);
    }
};