#include <iostream>

class BinarySearchTree {
public:
    int data;
    BinarySearchTree *left;
    BinarySearchTree *right;

    explicit BinarySearchTree(int data, BinarySearchTree *left = nullptr, BinarySearchTree *right = nullptr) {
        this->data = data;
        this->left = left;
        this->right = right;
    }

    void displayLNR(bool _root = true, bool _isRightMost = false) const {
        if (_root) {
            std::cout << "[";
        }
        if (this->left != nullptr) {
            this->left->displayLNR(false);
        }
        std::cout << data;
        if ((_root || _isRightMost) && this->right == nullptr) {
            std::cout << "]" << std::endl;
        } else {
            std::cout << ", ";
        }
        if (this->right != nullptr) {
            this->right->displayLNR(false, _root || _isRightMost);
        }
    };

    void displayNLR(bool _root = true, bool _isRightMost = false) const {
        if (_root) {
            std::cout << "[";
        }
        std::cout << data;
        if ((_root || _isRightMost) && this->right == nullptr) {
            std::cout << "]" << std::endl;
        } else {
            std::cout << ", ";
        }
        if (this->left != nullptr) {
            this->left->displayLNR(false);
        }
        if (this->right != nullptr) {
            this->right->displayLNR(false, _root || _isRightMost);
        }
    };

    void displayLRN(bool _root = true) const {
        if (_root) {
            std::cout << "[";
        }
        if (this->left != nullptr) {
            this->left->displayLNR(false);
        }
        if (this->right != nullptr) {
            this->right->displayLNR(false);
        }
        std::cout << data;
        if (_root) {
            std::cout << "]" << std::endl;
        } else {
            std::cout << ", ";
        }
    };

    BinarySearchTree* insert(int value) {
        if (value == this->data) {
            std::cerr << "This value already exists~" << std::endl;
        }
        if (value < data) {
            if (this->left == nullptr) {
                this->left = new BinarySearchTree(value);
            } else {
                this->left->insert(value);
            }
        } else if (value > data) {
            if (this->right == nullptr) {
                this->right = new BinarySearchTree(value);
            } else {
                this->right->insert(value);
            }
        }

        return this;
    }
};

int main() {
    auto tree = new BinarySearchTree(8,
                                     new BinarySearchTree(4,
                                                          new BinarySearchTree(2,
                                                                               nullptr,
                                                                               new BinarySearchTree(3)),
                                                          new BinarySearchTree(5,
                                                                               nullptr,
                                                                               new BinarySearchTree(7))));
    tree->right = new BinarySearchTree(12,
                                       new BinarySearchTree(9, nullptr, new BinarySearchTree(10)),
                                       new BinarySearchTree(14, new BinarySearchTree(13)));
    tree->insert(20);
    tree->displayNLR();
    tree->displayLNR();
    tree->displayLRN();
    return 0;
}