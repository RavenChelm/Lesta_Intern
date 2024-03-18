#pragma once
#include <list>
#include <iostream>
template<typename T>
class CircularBufferLinkedListNotConstMemory {
private:
    size_t bufferSize;
    std::list<T> linkedList;
    typename std::list<T>::iterator old;
public:
    CircularBufferLinkedListNotConstMemory(const size_t& bufferSize) :bufferSize(bufferSize) { old = linkedList.begin(); }
    bool empty() { return linkedList.empty(); }
    bool full() { return linkedList.size() == bufferSize; }
    void push(const T& element) {
        if (empty()) {
            old = linkedList.insert(old, element);
            return;
        }
        else if (full()) {
            old = linkedList.erase(old);
            old = linkedList.insert(old, element);
            if (old != linkedList.begin())
                old = std::prev(old);
            else {
                old = prev(linkedList.end());
            }
        }
        else {
            linkedList.push_front(element);
        }
    }
    T pop() {
        if (empty()) throw std::runtime_error("Buffer is empty");
        T elem = *old;
        old = linkedList.erase(old);
        if (old != linkedList.begin())
            old = std::prev(old);
        else if(!empty() ){
            old = prev(linkedList.end());
        }
        return elem;
    }
    T top() {
        if (empty()) throw std::runtime_error("Buffer is empty");
        return *old;
    }
    void print() {
        auto iterOld = old;
        size_t size = linkedList.size();
        for (size_t i = 0; i != size; ++i) {
            std::cout << *iterOld << " ";
            if (iterOld != linkedList.begin())
                iterOld = std::prev(iterOld);
            else
                iterOld = prev(linkedList.end());
        }
    }
};