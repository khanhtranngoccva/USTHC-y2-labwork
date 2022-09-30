#include <iostream>

int &wtf(int &x) {
    return x;
}

int main() {
    int x = 2;
    int y = wtf(x);
    y = 3;
    std::cout << x << std::endl;
    return 0;
}
