//
// Created by khanh on 9/22/2022.
//
#include <iostream>

typedef struct {
    int length;
    int capacity;
    int* data;
} DynamicList;

DynamicList createDynamicList(int maxSize) {
    DynamicList list;
    list.data = (int *) malloc(maxSize * sizeof (int));
    list.capacity = maxSize;
    list.length = 0;
    return list;
}

int length(DynamicList &l) {
    return l.length;
}

bool isEmpty(DynamicList &l) {
    return l.length == 0;
}

void display(DynamicList &l) {
    std::cout << "[";
    for (int i = 0; i < l.length; i++) {
        if (i == l.length - 1) {
            std::cout << l.data[i] << "]" << std::endl;
        } else {
            std::cout << l.data[i] << ", ";
        }
    }
}

void insert(DynamicList &l, int index, int val) {
    if (length(l) >= l.capacity) {
        std::cerr << "The static array is full!" << std::endl;
        return;
    }
    if (index < 0 || index > length(l)) {
        std::cerr << "Out of bounds!" << std::endl;
        return;
    }
    for (int i = length(l); i > index; i--) {
        l.data[i] = l.data[i - 1];
    }
    l.data[index] = val;
    l.length++;
}

void push(DynamicList &l, int value) {
    insert(l, length(l), value);
}

void remove(DynamicList &l, int index) {
    if (length(l) == 0) {
        std::cerr << "The static array is empty!" << std::endl;
        return;
    }
    if (index < 0 || index > length(l)) {
        std::cerr << "Out of bounds!" << std::endl;
        return;
    }
    for (int i = index; i < l.length; i++) {
        l.data[i] = l.data[i + 1];
    }
    l.length--;
}

int main() {
    DynamicList l1 = createDynamicList(10);
    for (int i = 0; i < 10; i++) {
        push(l1, i);
    }
    display(l1);
}