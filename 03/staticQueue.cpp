//
// Created by khanh on 9/29/2022.
//
#include <iostream>

#define STATIC_QUEUE_CAP 10

class StaticQueue {
public:
    int data[STATIC_QUEUE_CAP];
    int length;

    StaticQueue() {
        this->data;
        this->length = 0;
    }

    int enqueue(int item) {
        if (this->length >= STATIC_QUEUE_CAP) {
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
        return this->length == STATIC_QUEUE_CAP;
    }

    int dequeue() {
        if (this->length > 0) {
            int result = this->data[0];
            for (int i = 0; i < this->length - 1; i++) {
                this->data[i] = this->data[i + 1];
            }
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
        return this->data[0];
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
    auto queue = *(new StaticQueue());
    queue.enqueue(9);
    queue.enqueue(10);
    queue.enqueue(4);
    queue.enqueue(5);
    std::cout << queue.dequeue() << std::endl;
    std::cout << queue.dequeue() << std::endl;
    queue.display();
    std::cout << queue.top() << std::endl;
    std::cout << queue.size() << std::endl;
    return 0;
}