//
// Created by khanh on 9/29/2022.
//
#include <iostream>
#include <cstdlib>

class DynamicStack {
public:
    int *data;
    int length;
    int maxSize;

    DynamicStack(int maxSize) {
        this->data = (int *) calloc(maxSize, sizeof (int));
        this->maxSize = maxSize;
        this->length = 0;
    }

    int push(int item) {
        if (this->length >= this->maxSize) {
            std::throw_with_nested("Stack is full!");
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
        return this->length == this->maxSize;
    }

    int pop() {
        if (this->length <= 0) {
            std::throw_with_nested("Empty stack!");
        } else {
            int result = this->data[this->length - 1];
            this->length--;
            return result;
        }
    }

    int top() {
        if (this->length <= 0) {
            throw std::exception();
        }
        return this->data[this->length - 1];
    }

    void display() const {
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
    auto stack = *(new DynamicStack(20));
    stack.push(2);
    stack.pushpush3);
    stack.push(4);
    stack.push(5);
    std::cout << stack.pop() << std::endl;
    stack.display();
    std::cout << stack.top() << std::endl;
    std::cout << stack.size() << std::endl;
    return 0;
}