//
// Created by khanh on 11/3/2022.
//

#ifndef USTHC_Y2_LABWORK_REVIEW_E1_DYNAMICLIST_H
#define USTHC_Y2_LABWORK_REVIEW_E1_DYNAMICLIST_H

class DynamicList {
    int _length;
    int _capacity;
    int *_data;
public:
    [[nodiscard]] int length() const;

    [[nodiscard]] bool isEmpty() const;

    void display() const;

    void insert(int index, int val);

    void push(int value);

    int remove(int index);

    int pop();

    int get(int index);

    int set(int index, int data);
};

#endif //USTHC_Y2_LABWORK_REVIEW_E1_DYNAMICLIST_H
