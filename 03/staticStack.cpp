//
// Created by khanh on 9/29/2022.
//
#include <iostream>

#define STATIC_STACK_CAP 10

class StaticStack {
public:
    int data[STATIC_STACK_CAP];
    int length;

    StaticStack() {
        this->data;
        this->length = 0;
    }

    int push(int item) {
        if (this->length >= STATIC_STACK_CAP) {
            throw std::exception();
        } else {
            this->data[this->length] = item;
            this->length++;
            return this->length;
        }
    }

    [[nodiscard]] int size() const {
        return this->length;
    }

    [[nodiscard]] bool isFull() const {
        return this->length == STATIC_STACK_CAP;
    }

    int pop() {
        if (this->length > 0) {
            int result = this->data[this->length - 1];
            this->length--;
            return result;
        } else {
            throw std::exception();
        }
    }

    int top() {
        if (this->length <= 0) {
            throw std::exception();
        }
        return this->data[this->length - 1];
    }

    void display() {
        std::cout << "[";
        for (int i = 0; i < this->length; i++) {
            if (i == this->length - 1) {
                std::cout << this->data[i] << "]" << std::endl;
            } else {
                std::cout << this->data[i] << ", ";
            }
        }
    }
};

int main() {
    auto stack = *(new StaticStack());
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);
    std::cout << stack.pop() << std::endl;
    stack.display();
    std::cout << stack.top() << std::endl;
    std::cout << stack.size() << std::endl;
    return 0;
}