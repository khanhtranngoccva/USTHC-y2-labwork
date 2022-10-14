#include <iostream>
#include <cstdlib>

void swap(int &x, int &y);

typedef class List List;

class List {
private:
    /**
     * Attempts to sort the list using insertion sort, but the function stops after 1 pass.
     *
     * Pseudocode:
     * curValue = this.data[start]
     * curIndex = start
     * for i = start + 1; i < end; i++
     *   if this.data[i] > curValue
     *     for j = curIndex; j < i - 1; j++
     *       this->data[j] = this->data[j + 1]
     *     this->data[i - 1] = curValue;
     *     curIndex = i
     *     curValue = this.data[value]
     * for j = curIndex; j < i - 1; j++
     *   this->data[j] = this->data[j + 1]
     * this->data[i - 1] = curValue;
     *
     * Complexity: Best case: O(n), Average case: O(n), Worst case: O(n)
     *
     * @param start The starting sorting index for the pass.
     * @param end The ending index for the current pass.
     */
    void _onePassInsertionSort(int start, int end) const {
        int curValue = this->data[start];
        int curIndex = start;
        int i;
        for (i = start + 1; i < end; i++) {
            if (this->data[i] > curValue) {
                for (int j = curIndex; j < i - 1; j++) {
                    this->data[j] = this->data[j + 1];
                }
                this->data[i - 1] = curValue;
                curIndex = i;
                curValue = this->data[i];
            }
        }
        for (int j = curIndex; j < i - 1; j++) {
            this->data[j] = this->data[j + 1];
        }
        this->data[i - 1] = curValue;
    }

    /**
     * Attempts to sort the list using reversed bubble sort, but the function stops after 1 pass.
     *
     * ** Best case, average case, worst case in order.
     *
     * Pseudocode:
     * for i = end - 1; i > start; i--
     *   if this.data[i] < this.data[i - 1]
     *     swap(this.data[i], this.data[i - 1])
     *
     * Total time complexity: O(n) in all cases.
     *
     * @param start The starting sorting index for the pass.
     * @param end The ending index for the current pass. the index at the end will not be affected.
     */
    void _onePassReverseBubble(int start, int end) const {
        for (int i = end - 1; i > start; i--) {
            if (this->data[i] < this->data[i - 1]) {
                swap(this->data[i], this->data[i - 1]);
            }
        }
    }

public:
    int *data;
    int length;
    int maxSize;

    explicit List(int maxSize) {
        this->data = (int *) calloc(maxSize, sizeof(int));
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

    int pop() {
        if (this->length > 0) {
            int result = this->data[this->length];
            this->length--;
            return result;
        } else {
            throw std::exception();
        }
    }

    [[nodiscard]] int size() const {
        return this->length;
    }

    [[nodiscard]] bool isFull() const {
        return this->length == this->maxSize;
    }

    void display() const {
        std::cout << "[";
        for (int i = 0; i < this->length; i++) {
            if (i == this->length - 1) {
                std::cout << this->data[i];
            } else {
                std::cout << this->data[i] << ", ";
            }
        }
        std::cout << "]" << std::endl;
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

    /**
     * Sorts the array using the custom sort function.
     *
     * Pseudocode:
     * start = 0, end = this.length
     * while start != end
     *   this._onePassInsertionSort(start, end)
     *   end--
     *   this._onePassReverseBubble(start, end)
     *   start++
     *
     * Complexity: Best case: O(n^2), average case: O(n^2), worst case: O(n^2)
     * */
    void customSort() const {
        int start = 0, end = this->length;
        while (start != end) {
            this->_onePassInsertionSort(start, end);
            end--;
            this->_onePassReverseBubble(start, end);
            start++;
        }
    }
};

void swap(int &x, int &y) {
    int t = y;
    y = x;
    x = t;
}

int main() {
    auto l1 = new List(8);
    l1->push(99);
    l1->push(55);
    l1->push(44);
    l1->push(22);
    l1->push(66);
    l1->push(88);
    l1->push(33);
    l1->push(11);
    l1->customSort();
    l1->customSort();
    l1->display();
}