#include <iostream>
#include <cmath>
#include <random>

#define yeet throw
#define RESERVED_INT 2147483647

typedef class List List;
typedef class BinaryTree BinarySearchTree;

class List {
private:
    int _length;
    int _maxLength;
public:
    int *data;

    explicit List(int maxLength) {
        this->data = (int *) calloc(maxLength, sizeof(int));
        this->_length = 0;
        this->_maxLength = maxLength;
    }

    static List *generateList(int length, int minVal = 0, int maxVal = 50) {
        std::random_device rd;
        std::mt19937 mt(rd());
        std::uniform_int_distribution<int> dist(minVal, maxVal);

        auto list = new List(length);
        for (int i = 0; i < length; i++) {
            list->push(dist(mt));
        }

        return list;
    }

    [[nodiscard]] int length() const {
        return this->_length;
    }

    int push(int value) {
        if (this->_length >= this->_maxLength) {
            yeet std::out_of_range("The array is already full");
        }
        this->data[this->_length] = value;
        this->_length++;
        return this->_length;
    }

    int pop() {
        if (this->_length <= 0) {
            yeet std::out_of_range("The array is already emptied");
        }
        this->_length--;
        return this->data[this->_length];
    }

    int max() {
        if (this->_length < 0) {
            yeet std::range_error("The array is empty.");
        }
        int curMax = this->data[0];
        for (int i = 1; i < this->_length; i++) {
            if (curMax < this->data[i]) {
                curMax = this->data[i];
            }
        }
        return curMax;
    }

    void display() const {
        std::cout << "[";
        for (int i = 0; i < this->_length; i++) {
            if (i != this->_length - 1) {
                std::cout << this->data[i] << ", ";
            } else {
                std::cout << this->data[i];
            }
        }
        std::cout << "]" << std::endl;
    }
};

class BinaryTree {
private:
    void _populateTreeWithList(List *list, int* _index=nullptr) {
        // Create the index pointer so that the index can be shared across call frames.
        int origIndex;
        if (_index == nullptr) {
            origIndex = 0;
            _index = &origIndex;
        }
        if (this->left == nullptr && this->right == nullptr) {
            if (*_index < list->length()) {
                this->data = list->data[*_index];
            } else {
                this->data = RESERVED_INT;
            }
            (*_index)++;
        }
        if (this->left != nullptr) {
            this->left->_populateTreeWithList(list, _index);
        }
        if (this->right != nullptr) {
            this->right->_populateTreeWithList(list, _index);
        }
    }

    int _propagateTreeUp() {
        if (this->left == nullptr && this->right == nullptr) {
            return this->data;
        } else if (this->left == nullptr) {
            this->data = this->right->_propagateTreeUp();
        } else if (this->right == nullptr) {
            this->data = this->left->_propagateTreeUp();
        } else {
            int r = this->right->_propagateTreeUp();
            int l = this->left->_propagateTreeUp();
            if (r > l) {
                this->data = l;
            } else {
                this->data = r;
            }
        }
        return this->data;
    }

public:
    int data;
    BinaryTree *left;
    BinaryTree *right;

    explicit BinaryTree(int data, BinaryTree *left = nullptr, BinaryTree *right = nullptr) {
        this->data = data;
        this->left = left;
        this->right = right;
    }

    static BinaryTree *createEmptyBinaryTree(int depth) {
        if (depth == 0) {
            return new BinaryTree(0);
        }
        depth--;
        auto *node = new BinaryTree(0);
        node->left = createEmptyBinaryTree(depth);
        node->right = createEmptyBinaryTree(depth);
        return node;
    }

    [[nodiscard]] static BinaryTree *createBinaryTreeFromList(List *list) {
        // Create a new tree, and then pass the pointer recursively into the new tree.
        int depth = (int) ceil(log2(double(list->length())));
        auto curTree = createEmptyBinaryTree(depth);
        curTree->_populateTreeWithList(list);
        curTree->_propagateTreeUp();
        return curTree;
    }

    void prettyDisplayNLR(int _depth = 0) const {
        if (this->left != nullptr) {
            this->left->prettyDisplayNLR(_depth + 1);
        }
        std::string dString = std::string(4 * _depth, '-');
        if (this->data != RESERVED_INT) {
            std::cout << "|" << dString << " " << this->data << std::endl;
        } else {
            std::cout << "|" << dString << " null" << std::endl;
        }
        if (this->right != nullptr) {
            this->right->prettyDisplayNLR(_depth + 1);
        }
    };

    [[nodiscard]] int search(int value) const {
        if (value == RESERVED_INT) {
            throw std::invalid_argument("This value is reserved for null/empty.");
        }
        int successFlag = -1;
        if (this->data == value) {
            this->prettyDisplayNLR();
            successFlag = 0;
            std::cout << std::endl;
        }
        if (this->left != nullptr && this->left->search(value)) {
            successFlag = 0;
        }
        if (this->right != nullptr && this->right->search(value)) {
            successFlag = 0;
        }
        return successFlag;
    }

    bool insert(int value, bool _root=true) {
        bool success = false;
        if (this->left == nullptr && this->right == nullptr && this->data == RESERVED_INT) {
            this->data = value;
            success = true;
        } else if (this->left != nullptr && this->left->insert(value, false)) {
            success = true;
        } else if (this->right != nullptr && this->right->insert(value, false)) {
            success = true;
        }
        if (success && _root) {
            this->_propagateTreeUp();
        }
        return success;
    }

    bool remove(int value, bool _root=true, int _parent=RESERVED_INT) {
        bool success = false;
        if (this->left == nullptr && this->right == nullptr && this->data == value) {
            this->data = _parent;
            success = true;
        } else if (this->left != nullptr && this->left->remove(value, false, this->data)) {
            success = true;
        } else if (this->right != nullptr && this->right->remove(value, false, this->data)) {
            success = true;
        }
        if (success && _root) {
            this->_propagateTreeUp();
        }
        return success;
    }
};


int main() {
    auto list = List::generateList(128);

    auto tree = BinaryTree::createBinaryTreeFromList(list);
    tree->insert(5);
    tree->remove(2);
    tree->prettyDisplayNLR();
}