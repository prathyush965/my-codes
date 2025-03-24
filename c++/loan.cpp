#include <iostream>
#include <iomanip> // For setprecision
using namespace std;

class Bank {
public:
    static void calculateInterest(double loanAmount, int tenure) {
        float tenureFloat = tenure; // Implicit conversion (int → float)
        double interestRate;

        // Determine interest rate based on tenure
        if (tenureFloat >= 1 && tenureFloat <= 5)
            interestRate = 7.0;
        else if (tenureFloat >= 6 && tenureFloat <= 10)
            interestRate = 8.5;
        else
            interestRate = 10.0;
        
        // Calculate interest with precision using static_cast
        double interest = static_cast<double>(loanAmount * (interestRate / 100));
        
        // Display final interest with two decimal places
        cout << fixed << setprecision(2);
        cout << "Final Interest: $" << interest << endl;
    }
};

int main() {
    double loanAmount;
    int tenure;
    
    cout << "Enter loan amount: ";
    cin >> loanAmount;
    cout << "Enter tenure (in years): ";
    cin >> tenure;
    
    Bank::calculateInterest(loanAmount, tenure);
    
    return 0;
}
