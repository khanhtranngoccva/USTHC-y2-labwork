//
// Created by khanh on 11/25/2022.
//

#include <iostream>

class Node {
public:
    int data;
    Node *upNext;

    Node(int data, Node *upNext) {
        this->data = data;
        this->upNext = upNext;
    }
};

class LinkedQueue {
public:
    int length;
    Node *firstInQueue;
    Node *lastInQueue;

    LinkedQueue() {
        this->length = 0;
        this->firstInQueue = nullptr;
        this->lastInQueue = nullptr;
    }

    int enqueue(int value) {
        this->length++;
        auto *newNode = new Node(value, nullptr);
        // Queue empty.
        if (this->firstInQueue == nullptr) {
            this->firstInQueue = newNode;
            this->lastInQueue = newNode;
        }
            // Queue already has at least one entity.
        else {
            this->lastInQueue->upNext = newNode;
            this->lastInQueue = newNode;
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
        Node *poppedNode = this->firstInQueue;
        int result = poppedNode->data;
        this->firstInQueue = poppedNode->upNext;
        free(poppedNode);
        return result;
    }

    [[nodiscard]] int top() const {
        if (this->length <= 0) {
            throw std::exception();
        }
        return this->firstInQueue->data;
    }

    void display() const {
        std::cout << "Start: [";
        Node *curNode = this->firstInQueue;
        while (curNode != nullptr) {
            if (curNode->upNext != nullptr) {
                std::cout << curNode->data << ", ";
            } else {
                std::cout << curNode->data << "]" << std::endl;
            }
            curNode = curNode->upNext;
        }
    }
};

void aSort(int arr[], int len) {
    for (int i = 0; i < len - 1; i++) {
        for (int j = i; j < len; j++) {
            if (arr[i] > arr[j]) {
                int tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}

bool isPrime(int n) {
    n = abs(n);
    if (n <= 1) return false;
    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

void searchTwinPrimes(int arr[], int len) {
    aSort(arr, len);
    auto queue = new LinkedQueue();
    for (int i = 0; i < len; i++) {
        queue->enqueue(arr[i]);
    }
    int current = queue->dequeue();
    int next;
    while (queue->length > 0) {
        next = queue->dequeue();
        if (isPrime(current) && isPrime(next) && current + 2 == next) {
            std::cout << current << " " << next << std::endl;
        }
        current = next;
    }
}

int main() {
    int initial[] = {3, 101, 96, 47, 41, 7, 65, 9, 13, 5, 79, 45, 39, 11, 43};
    searchTwinPrimes(initial, sizeof(initial) / sizeof(int));
}

/**
 * Proposition of a method to improve the time complexity of finding twin primes:
 *
 * 1. Merge sort the array instead of using bubble sort(complexity improved to O(n log n) instead of O(n ^ 2))
 * 2. Create a Eratosthenes' sieve that supports to the highest value(complexity is O (n log log n)).
 * 3. For each number in the linked list (do a linear loop of O(n) time complexity):
 *      * Check the primality of the numbers against the Eratosthenes' sieve, and whether their difference is 2. O(1) complexity.
 * - The total complexity of step 3 is O(n) * O(1) = O(n). The total complexity of step 2 and step 3 is O(n log log n), improved from O(n ^ 2).
 * - The total complexity of the function is now O(n log n) instead of O(n ^ 2).
 */
