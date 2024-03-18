#pragma once
#include <list>
#include <iostream>
template<typename T>
class CircularBufferLinkedList {
private:
    size_t length = 0;
    std::list<T> linkedList;
    typename std::list<T>::iterator iterFront;
    typename std::list<T>::iterator iterBack;
public:
    CircularBufferLinkedList(const size_t& bufferSize) :linkedList(bufferSize){
        iterFront = linkedList.begin();
        iterBack = linkedList.begin();
    }
    bool empty() { return length == 0; }
    bool full() { return linkedList.size() == length; }
    void push(const T& element) {
        *iterFront = element;
        ++iterFront;
        if (iterFront == linkedList.end()) {
            iterFront = linkedList.begin();
        }
        if (!full()) {
            ++length;
        }
        else {
            ++iterBack;
            if (iterBack == linkedList.end()) {
                iterBack = linkedList.begin();
            }
        }
    }
    T pop() {
        if (empty()) throw std::runtime_error("Buffer is empty");
        T elem = *iterBack;
        ++iterBack;
        --length;
        if (iterBack == linkedList.end()) { 
            iterBack = linkedList.begin();
        }
        return elem;
    }
    T top() {
        if (empty()) throw std::runtime_error("Buffer is empty");
        return *iterBack;  
    }
    void print() { 
        if (empty()) return;
        auto start = iterBack;
        size_t count = 0;
        do {
            std::cout << *start << " ";
            ++count;
            ++start;
            if (start == linkedList.end()) {
                start = linkedList.begin();
            }
        } while (count < length);
    }
};
