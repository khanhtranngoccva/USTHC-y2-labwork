//
// Created by khanh on 11/3/2022.
//
#include <iostream>
#include "DynamicList.hpp"

//class PrimeNumberGenerator {
//private:
//    // A structure similar to the hashtable. Stores cached data.
//    DynamicList *_primeMap;
//    // An array storing all the primes, allowing generation of new primes.
//    DynamicList *_primes;
//public:
//    PrimeNumberGenerator() {
//        this->_primeMap = new DynamicList();
//        this->_primes = new DynamicList();
//        this->_primeMap->push(0);
//        this->_primeMap->push(0);
//        this->_primeMap->push(1);
//        this->_primes->push(2);
//    }
//
//    void printAvailablePrimes() const {
//        this->_primes->display();
//    }
//
//    bool isPrime(unsigned int value) {
//        // The value is in the cache array. Use a O(1) index to get whether it is in the array or not.
//        if (value < this->_primeMap->length()) {
//            return (bool) this->_primeMap->get((int) value);
//        }
//        int starting = this->_primeMap->length();
//        for (int i = starting; i <= value; i++) {
//            bool isPrime = true;
//            for (int j = 0; j < this->_primes->length(); j++) {
//                if (i % this->_primes->get(j) == 0) {
//                    isPrime = false;
//                }
//            }
//            this->_primeMap->push(isPrime);
//            if (isPrime) {
//                this->_primes->push(i);
//            }
//        }
//        return (bool) this->_primeMap->get((int) value);
//    }
//};

int main() {
    auto l1 = new DynamicList();
    l1->push(2);
}