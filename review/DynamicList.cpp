//
// Created by khanh on 11/3/2022.
//
#include <iostream>
#include <cstdarg>

#define INITIAL_DYNAMIC_LIST_SIZE 10

class DynamicList {
private:
    int _length;
    int _capacity;
    int *_data;
public:
    DynamicList() {
        this->_data = (int *) calloc(INITIAL_DYNAMIC_LIST_SIZE, sizeof(int));
        this->_capacity = INITIAL_DYNAMIC_LIST_SIZE;
        this->_length = 0;
    }

    [[nodiscard]] int length() const {
        return this->_length;
    }

    [[nodiscard]] bool isEmpty() const {
        return this->_length == 0;
    }

    void display() const {
        std::cout << "[";
        for (int i = 0; i < this->_length; i++) {
            if (i == this->_length - 1) {
                std::cout << this->_data[i] << "]" << std::endl;
            } else {
                std::cout << this->_data[i] << ", ";
            }
        }
    }

    void insert(int index, int val) {
        if (index < 0 || index > this->_length) {
            std::throw_with_nested("Out of bounds!");
            return;
        }
        if (this->_length >= this->_capacity) {
            this->_capacity *= 2;
            this->_data = (int *) realloc(this->_data, sizeof(int) * this->_capacity);
        }
        for (int i = this->_length; i > index; i--) {
            this->_data[i] = this->_data[i - 1];
        }
        this->_data[index] = val;
        this->_length++;
    }

    void push(int value) {
        this->insert(this->_length, value);
    }

    int remove(int index) {
        if (this->_length == 0) {
            std::throw_with_nested("The static array is empty!");
        }
        if (index < 0 || index > this->_length) {
            std::throw_with_nested("Out of bounds!");
        }
        int result = this->_data[index];
        for (int i = index; i < this->_length; i++) {
            this->_data[i] = this->_data[i + 1];
        }
        this->_length--;
        return result;
    }

    int pop() {
        return this->remove(this->_length);
    }

    int get(int index) {
        if (index < 0 || index >= this->_length) {
            std::throw_with_nested("Out of bounds!");
        }
        return this->_data[index];
    }

    int set(int index, int data) {
        if (index < 0 || index >= this->_length) {
            std::throw_with_nested("Out of bounds!");
        }
        this->_data[index] = data;
        return data;
    }
};