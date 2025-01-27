//c++ code to calculate bill
#include <iostream>
#include <string>  
using namespace std;

int main() {
    int customerID, unitsConsumed;
    string customerName;
    cout << "Enter Customer ID: ";
    cin >> customerID;
    cout << "Enter Customer Name: ";
    cin >> customerName;
    cout << "Enter Units Consumed: ";
    cin >> unitsConsumed;

    double chargePerUnit = 0, amountCharges = 0, surcharge = 0, netAmount = 0;

    if (unitsConsumed <= 199) {
        chargePerUnit = 16.20;
    } else if (unitsConsumed >= 200 && unitsConsumed < 300) {
        chargePerUnit = 20.10;
    } else if (unitsConsumed >= 300 && unitsConsumed < 500) {
        chargePerUnit = 27.10;
    } else { 
        chargePerUnit = 35.90;
    }

    amountCharges = unitsConsumed * chargePerUnit;
    if (amountCharges > 18000) {
        surcharge = amountCharges * 0.15;
    }

    netAmount = amountCharges + surcharge;

    cout << "Customer ID   : " << customerID << endl;
    cout << "Customer Name : " << customerName << endl;
    cout << "Units Consumed: " << unitsConsumed << endl;
    cout << "Amount Charges @Rs. " << chargePerUnit << " per unit: " << amountCharges << endl;
    cout << "Surcharge Amount: " << surcharge << endl;
    cout << "Net Amount Paid by the Customer: " << netAmount << endl;

    return 0;
}
