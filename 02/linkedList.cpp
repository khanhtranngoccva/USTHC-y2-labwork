#include <stdlib.h>
#include <iostream>

typedef struct LinkedList LinkedList;
typedef struct Node Node;

typedef struct Node {
    int data;
    LinkedList *_parent;
    struct Node *pNext;
} Node;

typedef struct LinkedList {
    int length;
    Node *pHead;
} LinkedList;


LinkedList createLinkedList() {
    LinkedList newList;
    newList.length = 0;
    newList.pHead = nullptr;
    return newList;
}

Node createNode(int val, LinkedList *parent) {
    Node newNode;
    newNode.data = val;
    newNode.pNext = nullptr;
    newNode._parent = parent;
    return newNode;
}

void appendToLinkedList(LinkedList *list, int val) {
    if (list->pHead == nullptr) {
        Node *newNodePtr = (Node *) malloc(sizeof(Node));
        *newNodePtr = createNode(val, list);
        list->pHead = newNodePtr;
        list->length++;
    } else {
        Node *curNode = list->pHead;
        while (curNode->pNext != nullptr) {
            curNode = curNode->pNext;
        }
        Node *newNodePtr = (Node *) malloc(sizeof(Node));
        // Create the node on the HEAP. If it's on the stack, it will be lost forever and... causes all the glitches. Oooof!
        *newNodePtr = createNode(val, list);
        curNode->pNext = newNodePtr;
        list->length++;
    }
}

void popFromLinkedList(LinkedList *list) {
    Node *curNode = list->pHead;
    if (curNode == nullptr) {
        return;
    } else {
        while (curNode->pNext->pNext != nullptr) {
            curNode = curNode->pNext;
        }
        free(curNode->pNext);
        curNode->pNext = nullptr;
        list->length--;
    }
}

void printLinkedList(LinkedList *list) {
    std::cout << "[";
    Node *curNode = list->pHead;
    while (curNode != nullptr) {
        if (curNode->pNext == nullptr) {
            std::cout << curNode->data;
        } else {
            std::cout << curNode->data << ", ";
        }
        curNode = curNode->pNext;
    }
    std::cout << "]" << std::endl;
}

void insertAfterNode(Node *prevNode, int val) {
    Node *newNodePtr = (Node *) malloc(sizeof(Node));
    *newNodePtr = createNode(val, prevNode->_parent);
    newNodePtr->pNext = prevNode->pNext;
    prevNode->pNext = newNodePtr;
    prevNode->_parent->length++;
}

void deleteNode(Node *targetNode) {
    LinkedList *targetList = targetNode->_parent;
    Node *curNode = targetList->pHead;
    while (curNode->pNext != targetNode) {
        curNode = curNode->pNext;
    }
    curNode->pNext = targetNode->pNext;
    free(targetNode);
    targetList->length--;
}

Node *getNode(LinkedList *list, int index) {
    Node *curNode = list->pHead;
    for (int i = 0; i < index; i++) {
        curNode = curNode->pNext;
    }
    return curNode;
}

int getNodeVal(LinkedList *list, int index) {
    Node *targetNode = getNode(list, index);
    return targetNode->data;
}

int main() {
    LinkedList l1 = createLinkedList();
    for (int i = 1; i < 20; i += 3) {
        appendToLinkedList(&l1, i);
    }
    printLinkedList(&l1);
    Node *n1 = getNode(&l1, 2);
    insertAfterNode(n1, 200);
    deleteNode(n1);
    printLinkedList(&l1);
    std::cout << getNodeVal(&l1, 3) << std::endl;
}