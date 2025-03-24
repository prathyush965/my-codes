#include <iostream>
using namespace std;
int main() {
    int temp;
    cout << "Enter the temperature: ";
    cin >> temp;
    if (temp >= 80) {
        cout << "Suggested activity: Swimming" << std::endl;
    } 
    else if (temp >= 60) { 
        cout << "Suggested activity: Tennis" << endl;
    } 
    else if (temp >= 40) {  
        cout << "Suggested activity: Golf" << endl;
    }
    else {  
        cout << "Suggested activity: Skiing" << std::endl;
    }
    return 0;
}
