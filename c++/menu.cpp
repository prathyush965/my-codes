#include <iostream>
#include <algorithm>
using namespace std; 
const int SIZE = 100; 
void insert(int arr[], int &size, int value) { 
    if (size < SIZE) arr[size++] = value, cout << "Inserted.\n"; 
    else cout << "Array full.\n"; 
}
void remove(int arr[], int &size, int value) { 
    int i, found = 0; 
    for (i = 0; i < size; i++) if (arr[i] == value) { found = 1; break; } 
    if (found) { for (; i < size - 1; i++) arr[i] = arr[i + 1]; size--; cout << "Deleted.\n"; } 
    else cout << "Not found.\n"; 
}
void search(int arr[], int size, int value) { 
    for (int i = 0; i < size; i++) if (arr[i] == value) { cout << "Found at " << i + 1 << endl; return; } 
    cout << "Not found.\n"; 
}
void display(int arr[], int size) { 
    if (!size) { cout << "Empty.\n"; return; } 
    cout << "Elements: "; for (int i = 0; i < size; i++) cout << arr[i] << " "; cout << endl; 
}
void sortArray(int arr[], int size) { sort(arr, arr + size); cout << "Sorted.\n"; }
int main() { 
    int arr[SIZE], size = 0, choice, value; 
    do { 
        cout << "\n1.Insert 2.Delete 3.Search 4.Display 5.Sort 6.Exit\nEnter choice: "; 
        cin >> choice; 
        if (choice == 1) cin >> value, insert(arr, size, value); 
        else if (choice == 2) cin >> value, remove(arr, size, value); 
        else if (choice == 3) cin >> value, search(arr, size, value); 
        else if (choice == 4) display(arr, size); 
        else if (choice == 5) sortArray(arr, size); 
        else if (choice == 6) cout << "Exiting...\n"; 
        else cout << "Invalid!\n"; 
    } while (choice != 6); 
    return 0; 
}
