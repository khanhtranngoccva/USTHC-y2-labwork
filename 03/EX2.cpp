//
// Created by khanh on 9/29/2022.
//
#include <iostream>
#include <string>

#define yeet throw

typedef class Node Node;
typedef class LinkedStack LinkedStack;

class Node {
public:
    std::string data;
    Node* upNext;

    Node(std::string data, Node* upNext) {
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

    std::string push(std::string value) {
        this->length++;
        auto *newNode = new Node(value, this->toUse);
        this->toUse = newNode;
        return value;
    }

    std::string pop() {
        if (this->length <= 0) {
            yeet std::exception();
        }
        this->length--;
        Node* poppedNode = this->toUse;
        std::string result = poppedNode->data;
        this->toUse = poppedNode->upNext;
        free(poppedNode);
        return result;
    }

    std::string top() {
        if (this->length <= 0) {
            yeet std::exception();
        }
        return this->toUse->data;
    }

    void empty() {
        Node* curNode = this->toUse;
        Node* toDelete;
        while (curNode != nullptr) {
            toDelete = curNode;
            curNode = curNode -> upNext;
            free(toDelete);
        }
        this->length = 0;
    }

    void display() {
        std::cout << "Start: [";
        Node* curNode = this->toUse;
        if (this->length != 0) {
            while (curNode != nullptr) {
                if (curNode -> upNext != nullptr) {
                    std::cout << curNode->data << ", ";
                } else {
                    std::cout << curNode->data << "]" << std::endl;
                }
                curNode = curNode -> upNext;
            }
        } else {
            std::cout << "]" << std::endl;
        }
    }
};

class UndoRedoStack {
private:
    LinkedStack* undoStack;
    LinkedStack* redoStack;
public:
    UndoRedoStack() {
        this->undoStack = new LinkedStack();
        this->redoStack = new LinkedStack();
    }

    std::string addAction(std::string action) {
        this->undoStack->push(action);
        this->redoStack->empty();
        return action;
    }

    std::string undoAction() {
        try {
            std::string action = this->undoStack->pop();
            this->redoStack->push(action);
            return action;
        } catch (const std::exception &ex) {
            std::cerr << "No action to undo!" << std::endl;
            return "";
        }
    }

    std::string redoAction() {
        try {
            std::string action = this->redoStack->pop();
            this->undoStack->push(action);
            return action;
        }
        catch (const std::exception &ex) {
            std::cerr << "No action to redo!" << std::endl;
            return "";
        }
    }

    void displayUndo() {
        undoStack->display();
    }

    void displayRedo() {
        redoStack->display();
    }
};


int main() {
    auto undoRedo = *(new UndoRedoStack());

    std::string a1 = undoRedo.addAction("Cut");
    undoRedo.addAction("Copy");
    undoRedo.addAction("Paste");
    std::cout << undoRedo.undoAction() << std::endl;
    std::cout << undoRedo.undoAction() << std::endl;
    std::cout << undoRedo.redoAction() << std::endl;
    undoRedo.displayUndo();
    undoRedo.displayRedo();
    std::cout << undoRedo.redoAction() << std::endl;
    std::cout << undoRedo.redoAction() << std::endl;

    return 0;
}