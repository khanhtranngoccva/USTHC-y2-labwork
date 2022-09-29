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

class LinkedStack {
public:
    int length;
    Node* toUse;

    LinkedStack() {
        this->length = 0;
        this->toUse = nullptr;
    }

    int push(int value) {
        this->length++;
        auto *newNode = new Node(value, this->toUse);
        this->toUse = newNode;
        return this->length;
    }

    int pop() {
        if (this->length <= 0) {
            throw std::exception();
        }
        this->length--;
        Node* poppedNode = this->toUse;
        int result = poppedNode->data;
        this->toUse = poppedNode->upNext;
        free(poppedNode);
        return result;
    }

    int top() {
        if (this->length <= 0) {
            throw std::exception();
        }
        return this->toUse->data;
    }

    void display() {
        std::cout << "Start: [";
        Node* curNode = this->toUse;
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
    auto stack = *(new LinkedStack());

    stack.push(2);
    std::cout << stack.push(3) << std::endl;
    stack.pop();
    stack.push(4);
    stack.push(1);
    stack.display();

    return 0;
}