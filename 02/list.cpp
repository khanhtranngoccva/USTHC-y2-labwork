//
// Created by khanh on 9/22/2022.
//
#include <iostream>

#define STATIC_CAPACITY 5

typedef struct {
    int length;
    int data[STATIC_CAPACITY];
} StaticList;

StaticList createStaticList() {
    StaticList list;
    list.length = 0;
    return list;
}

int length(StaticList &l) {
    return l.length;
}

bool isEmpty(StaticList &l) {
    return l.length == 0;
}

void display(StaticList &l) {
    std::cout << "[";
    for (int i = 0; i < l.length; i++) {
        if (i == l.length - 1) {
            std::cout << l.data[i] << "]" << std::endl;
        } else {
            std::cout << l.data[i] << ", ";
        }
    }
}

void insert(StaticList &l, int index, int val) {
    if (length(l) == STATIC_CAPACITY) {
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

void push(StaticList &l, int value) {
    insert(l, length(l), value);
}

void remove(StaticList &l, int index) {
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
    StaticList l1 = createStaticList();
    push(l1, 5);
    push(l1, 7);
    push(l1, 6);
    push(l1, 3);
    push(l1, 8);
    remove(l1, 2);
    display(l1);
    std::cout << l1.data[1] << std::endl;
}