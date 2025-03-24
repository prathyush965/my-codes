#include <iostream>
using namespace std;
int main() {
    int num;
    while (true) {
        cout << "Enter a number: ";
        cin >> num;
        if (num % 2 == 0 && num % 3 == 0) {
            cout << "EXIT" << endl;
            break;  
        }
        cout << "Cube of " << num << " is: " << (num * num * num) << endl;
    }
    return 0;
}