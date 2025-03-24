#include <iostream>
using namespace std;

class ECommerce {
private:
    static double totalSpent; // Static variable to track total amount spent
    const double SALES_TAX = 0.05; // Constant sales tax rate (5%)

public:
    void purchase(double price, int quantity) {
        double subtotal = price * quantity;
        double tax = subtotal * SALES_TAX;
        double totalBill = subtotal + tax;
        totalSpent += totalBill; // Update total spent by user
        
        // Explicit type conversion to int before displaying
        cout << "Total Bill (including tax): " << (int)totalBill << "\n";
    }
    
    static void displayTotalSpent() {
        cout << "Total Amount Spent: " << (int)totalSpent << "\n";
    }
};

// Initialize static variable
double ECommerce::totalSpent = 0;

int main() {
    ECommerce user1;
    double price;
    int quantity;
    
    cout << "Enter item price: ";
    cin >> price;
    cout << "Enter quantity: ";
    cin >> quantity;
    
    user1.purchase(price, quantity);
    ECommerce::displayTotalSpent();
    
    return 0;
}
