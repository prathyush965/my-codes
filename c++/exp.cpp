#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    double num = -123.456;
    cout << scientific << setprecision(4) << num << endl;
    return 0;
}
