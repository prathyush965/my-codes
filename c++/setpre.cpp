#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    double num = 987.654321;
    cout << fixed << setprecision(4) << num << endl;
    return 0;
}
