//
// Created by khanh on 9/30/2022.
//
#include <map>
#include <string>
#include <iostream>

typedef class Supermarket Supermarket;
typedef class Customer Customer;

class Customer {

public:
    static int i;
    std::map<std::string, int> itemList;
    Customer *upNext;
    Customer *previous;
    Supermarket *parent;
    int id;

    Customer() {
        this->id = Customer::i;
        Customer::i++;
        this->upNext = nullptr;
        this->previous = nullptr;
        this->parent = nullptr;
    }

    int setItem(const std::string &itemName, int itemQty) {
        if (itemQty < 0) {
            this->itemList.insert(std::make_pair(itemName, 0));
            return 0;
        }
        this->itemList.insert(std::make_pair(itemName, itemQty));
        return itemQty;
    }

    void display() {
        for (const auto &elem: this->itemList) {
            std::cout << elem.first << " " << elem.second << std::endl;
        }
    }

    int getItem(const std::string &itemName) {
        if (this->itemList.contains(itemName)) {
            auto result = this->itemList.find(itemName);
            return result->second;
        } else {
            return 0;
        }
    }
};

int Customer::i{1};

class Supermarket {
private:
    int queueLength;
    std::map<std::string, int> itemList;
    Customer *firstInQueue;
    Customer *lastInQueue;
public:
    Supermarket() {
        this->queueLength = 0;
        this->firstInQueue = nullptr;
        this->lastInQueue = nullptr;
    }

    int setItem(const std::string &itemName, int itemQty) {
        if (itemQty < 0) {
            this->itemList[itemName] = 0;
            return 0;
        }
        this->itemList[itemName] = itemQty;
        return itemQty;
    }

    int getItem(const std::string &itemName) {
        if (this->itemList.contains(itemName)) {
            return this->itemList[itemName];
        } else {
            return 0;
        }
    }

    int addItem(const std::string &itemName, int addQty) {
        int curQty = this->getItem(itemName);
        return this->setItem(itemName, curQty + addQty);
    }

    void displayStore() {
        std::cout << "--------------------" << std::endl;
        std::cout << "Supermarket storage:" << std::endl;
        for (const auto &elem: this->itemList) {
            std::cout << elem.first << " " << elem.second << std::endl;
        }
        std::cout << "--------------------" << std::endl;
    }

    void enqueue(Customer &customer) {
        // The customer is not in any supermarket.
        if (customer.parent == nullptr) {
            // Queue empty.
            if (this->firstInQueue == nullptr) {
                this->firstInQueue = &customer;
                this->lastInQueue = &customer;
            }
                // Queue already has at least one entity.
            else {
                this->lastInQueue->upNext = &customer;
                customer.previous = this->lastInQueue;
                this->lastInQueue = &customer;
            }
            customer.parent = this;
            this->queueLength++;
        }
            // The customer is in the current supermarket.
        else if (customer.parent == this) {
            // If the supermarket has only a single customer which is the current customer, nothing happens.
            // Otherwise: put the customer to the last queue position.
            if (this->queueLength != 1) {
                // If the customer is the first in the queue.
                if (this->firstInQueue == &customer) {
                    this->firstInQueue = customer.upNext;
                    customer.upNext = nullptr;
                    customer.previous = this->lastInQueue;
                    this->lastInQueue->upNext = &customer;
                    this->lastInQueue = &customer;
                }
                    // Not the first in the queue.
                else if (this->lastInQueue != &customer) {
                    customer.previous->upNext = customer.upNext;
                    customer.upNext->previous = customer.previous;
                    customer.upNext = nullptr;
                    customer.previous = this->lastInQueue;
                    this->lastInQueue->upNext = &customer;
                    this->lastInQueue = &customer;
                }
            }
        } else {
            std::cerr << "This customer is in another supermarket. That supermarket must dequeue them first."
                      << std::endl;
        }
    }

    void handleCustomer(Customer &customer) {
        // Dry run.
        for (const auto &elem: customer.itemList) {
            std::string demandType = elem.first;
            int demandQty = elem.second;
            if (demandQty > this->getItem(demandType)) {
                std::cerr << "This supermarket does not have enough items to serve." << std::endl;
                return;
            }
        }
        std::cout << "This customer can be served." << std::endl;
        // For real this time.
        for (const auto &elem: customer.itemList) {
            std::string demandType = elem.first;
            int demandQty = elem.second;
            int availableQty = this->getItem(demandType);
            this->setItem(demandType, availableQty - demandQty);
        }
    }

    void dequeue() {
        // Queue empty?
        if (this->queueLength <= 0) {
            std::cerr << "Queue empty!" << std::endl;
            return;
        }
        auto *customer = this->firstInQueue;
        if (this->queueLength == 1) {
            this->firstInQueue = nullptr;
            this->lastInQueue = nullptr;
        } else {
            this->firstInQueue = customer->upNext;
            this->firstInQueue->previous = nullptr;
        }
        this->queueLength--;
        // Cleanup!
        customer->previous = nullptr;
        customer->upNext = nullptr;
        customer->parent = nullptr;
        // Checkout~~
        this->handleCustomer(*customer);
    }

    [[nodiscard]] int size() const {
        return this->queueLength;
    }

    void displayQueue() const {
        std::cout << "Start: [";
        if (this->queueLength == 0) {
            std::cout << "]" << std::endl;
        } else {
            auto *curNode = this->firstInQueue;
            while (curNode != nullptr) {
                if (curNode->upNext != nullptr) {
                    std::cout << curNode->id << ", ";
                } else {
                    std::cout << curNode->id << "]" << std::endl;
                }
                curNode = curNode->upNext;
            }
        }
    }
};

int main() {
    auto supermarket = *(new Supermarket());
    supermarket.addItem("Bananas", 10);
    supermarket.addItem("Bananas", 20);
    supermarket.addItem("Apples", 5);

    auto supermarket2 = *(new Supermarket());
//    supermarket.displayStore();

    auto customer = *(new Customer());
    auto customer2 = *(new Customer());
    auto customer3 = *(new Customer());
    auto customer4 = *(new Customer());
    auto customer5 = *(new Customer());
    customer.setItem("Bananas", 2);
    customer.setItem("Apples", 3);

    supermarket.enqueue(customer);
    supermarket.dequeue();
    supermarket.displayStore();

//    supermarket.enqueue(customer3);
//    supermarket.enqueue(customer4);
//    supermarket.enqueue(customer2);
//    supermarket.enqueue(customer5);
//    supermarket.displayQueue();
//    supermarket.enqueue(customer3);
//    supermarket2.enqueue(customer3);
//    supermarket.displayQueue();
//
//
//    supermarket.dequeue();
//    supermarket.dequeue();
//    supermarket.dequeue();
//    supermarket.dequeue();
//    supermarket.displayQueue();
//    supermarket.dequeue();
    return 0;
}