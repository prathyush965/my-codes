#include <iostream>
using namespace std;

// Function to input marks
void enterMarks(int marks[], int &n) {
    cout << "Enter marks for " << n << " students:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Student " << i + 1 << ": ";
        cin >> marks[i];
    }
}

// Function to calculate average marks
double calculateAverage(int marks[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += marks[i];
    }
    return (double)sum / n;
}

// Function to find highest and lowest marks
void findHighLow(int marks[], int n, int &highest, int &lowest) {
    highest = marks[0];
    lowest = marks[0];
    for (int i = 1; i < n; i++) {
        if (marks[i] > highest)
            highest = marks[i];
        if (marks[i] < lowest)
            lowest = marks[i];
    }
}

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;
    
    int marks[n];
    int choice;
    
    do {
        cout << "\nMenu:\n";
        cout << "1. Enter marks\n";
        cout << "2. Calculate average\n";
        cout << "3. Find highest and lowest marks\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                enterMarks(marks, n);
                break;
            case 2:
                cout << "Average Marks: " << calculateAverage(marks, n) << endl;
                break;
            case 3: {
                int highest, lowest;
                findHighLow(marks, n, highest, lowest);
                cout << "Highest Marks: " << highest << "\nLowest Marks: " << lowest << endl;
                break;
            }
            case 4:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 4);
    
    return 0;
}
