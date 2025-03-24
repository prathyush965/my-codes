#include <iostream>
#include <cmath>
using namespace std;
int main() {
    int num1, num2, product;
    cout << "Enter two integers: ";
    cin >> num1 >> num2;
    product = num1 * num2;
    cout << "Product - " << product << std::endl;
    int digitCount = (product == 0) ? 1 : log10(abs(product)) + 1;
    cout << "Count of digits - " << digitCount <<endl;
    return 0;
}