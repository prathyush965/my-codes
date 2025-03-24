#include <iostream>
#include <sstream>
#include "frac.h"
using namespace std;
int main() {
    int num1, den1, num2, den2;
    cout << "Enter first numerator : ";
    cin >> num1 ;
    cout << "Enter first  denomenator: ";
    cin >> den1 ;
    cout << "Enter second numerator : ";
    cin >> num2;
    cout << "Enter second denomenator : ";
    cin >> den2 ;
    int productNum = num1 * num2;
    int productDen = den1 * den2;
    cout << "Product = " << productNum << "/" << productDen << endl;
    return 0;
}