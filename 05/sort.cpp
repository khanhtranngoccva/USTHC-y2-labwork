#include <iostream>
#include <cstdlib>

void swap(int &x, int &y);

class List {
public:
    int *data;
    int length;
    int maxSize;

    List(int maxSize) {
        this->data = (int *) calloc(maxSize, sizeof (int));
        this->maxSize = maxSize;
        this->length = 0;
    }

    int push(int item) {
        if (this->length >= this->maxSize) {
            std::throw_with_nested("List is full!");
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
        if (this->length > 0) {
            int result = this->data[this->length];
            this->length--;
            return result;
        } else {
            throw std::exception();
        }
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

    void selection() const {
        const int len = this->length;
        for (int i = 0; i < len - 1; i++) {
            int minIdx = i;
            for (int j = i + 1; j < len; j++) {
                if (this->data[minIdx] > this->data[j]) {
                    minIdx = j;
                }
            }
            swap(this->data[minIdx], this->data[i]);
        }
    }

    void bubble() const {
        const int len = this->length;
        for (int i = 0; i < len - 1; i++) {
            for (int j = i + 1; j < len; j++) {
                if (this->data[i] > this->data[j]) {
                    swap(this->data[i], this->data[j]);
                }
            }
        }
    }

    void insertion() const {
        // [1, 4, 8, 2, 5]
        const int len = this->length;
        for (int i = 1; i < len; i++) {
            int j;
            for (j = i - 1; j >= 0; j--) {
                if (this->data[j] < this->data[i]) {
                    break;
                }
            }
            j++;
            int tmp = this->data[i];
            for (int k = i; k > j; k--) {
                this->data[k] = this->data[k - 1];
            }
            this->data[j] = tmp;
        }
    }
};

void swap(int &x, int &y) {
    int t = y;
    y = x;
    x = t;
}

int main() {
    auto l1 = new List(30);
    l1->push(1);
    l1->push(4);
    l1->push(8);
    l1->push(2);
    l1->push(5);
    l1->insertion();
    l1->display();
}