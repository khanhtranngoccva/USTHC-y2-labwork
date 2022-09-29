//
// Created by khanh on 9/29/2022.
//
//
// Created by khanh on 9/29/2022.
//
#include <iostream>

class Node {
public:
    int data;
    Node* upNext;

    Node(int data, Node* upNext) {
        this->data = data;
        this->upNext = upNext;
    }
};

class LinkedQueue {
public:
    int length;
    Node* firstInQueue;
    Node* lastInQueue;

    LinkedQueue() {
        this->length = 0;
        this->firstInQueue = nullptr;
        this->lastInQueue = nullptr;
    }

    int enqueue(int value) {
        this->length++;
        auto *newNode = new Node(value, nullptr);
        // Queue empty.
        if (this -> firstInQueue == nullptr) {
            this -> firstInQueue = newNode;
            this -> lastInQueue = newNode;
        }
        // Queue already has at least one entity.
        else {
            this -> lastInQueue -> upNext = newNode;
            this -> lastInQueue = newNode;
        }
        return this->length;
    }

    [[nodiscard]] int size() const {
        return this->length;
    }

    int dequeue() {
        if (this->length <= 0) {
            throw std::exception();
        }
        this->length--;
        Node* poppedNode = this->firstInQueue;
        int result = poppedNode->data;
        this->firstInQueue = poppedNode->upNext;
        free(poppedNode);
        return result;
    }

    int top() {
        if (this->length <= 0) {
            throw std::exception();
        }
        return this->firstInQueue->data;
    }

    void display() {
        std::cout << "Start: [";
        Node* curNode = this->firstInQueue;
        while (curNode != nullptr) {
            if (curNode -> upNext != nullptr) {
                std::cout << curNode->data << ", ";
            } else {
                std::cout << curNode->data << "]" << std::endl;
            }
            curNode = curNode -> upNext;
        }
    }
};


int main() {

    auto queue = *(new LinkedQueue());
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

    return 0;
}