#include <iostream>

int main() {
    int num, count = 0;
    std::cout << "Enter a number: ";
    std::cin >> num;

    while (num != 0) {
        num /= 10;
        count++;
    }

    std::cout << "Number of digits: " << count;
    return 0;
}
