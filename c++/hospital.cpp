#include <iostream>
using namespace std;

class PatientBill {
private:
    string patientName;
    int patientID;
    double billAmount;
    double amountPaid;

public:
    // Constructor for new patients with zero initial bill
    PatientBill(string name, int id) {
        patientName = name;
        patientID = id;
        billAmount = 0;
        amountPaid = 0;
        cout << "Zero bill" << endl;
    }

    // Constructor for discharged patients with final bill calculation
    PatientBill(string name, int id, double totalBill, double paid) {
        patientName = name;
        patientID = id;
        billAmount = totalBill;
        amountPaid = paid;
    }

    // Method to display the final bill summary
    void displayBillSummary() {
        cout << "Patient Name: " << patientName << endl;
        cout << "Patient ID: " << patientID << endl;
        cout << "Final Bill Amount: $" << billAmount << endl;
        cout << "Amount Paid: $" << amountPaid << endl;

        if (amountPaid == billAmount)
            cout << "Status: Fully Paid" << endl;
        else if (amountPaid == 0)
            cout << "Status: Unpaid" << endl;
        else
            cout << "Status: Outstanding Amount: $" << (billAmount - amountPaid) << endl;
    }
};

int main() {
    // New patient admission (zero initial bill)
    PatientBill patient1("John Doe", 101);
    
    // Discharged patient with a final bill
    PatientBill patient2("Alice Smith", 102, 1500.0, 1000.0);
    
    // Displaying bill summaries
    cout << endl;
    patient1.displayBillSummary();
    cout << endl;
    patient2.displayBillSummary();
    
    return 0
    
}
