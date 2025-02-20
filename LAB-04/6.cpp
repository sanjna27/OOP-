#include <iostream>
using namespace std;

class Invoice {
	private:
		string PartNumber;
		string PartDescription;
		int Quantity;
		double PerPrice;
	public:
		Invoice(){	
			PartNumber = "";
			PartDescription = "";
			Quantity = 0;
			PerPrice = 0.0;
		}
		Invoice(string Number, string Description, int Qty, double Price){	
			PartNumber = Number;
			PartDescription = Description;
			SetQuantity(Qty);
			SetPricePerItem(Price);
		}

		void SetPartNumber(string Number) {
			PartNumber = Number;
		}
		string GetPartNumber() const {
			return PartNumber;
		}
	
		void SetPartDescription(string Description) {
			PartDescription = Description;
		}
		string GetPartDescription() const {
			return PartDescription;
		}

		void SetQuantity(int Qty) {
			if (Qty > 0) {
				Quantity = Qty;
			} else {
				Quantity = 0; 
			}
		}
		int GetQuantity() const {
			return Quantity;
		}
	
		void SetPricePerItem(double Price) {
			if (Price > 0.0) {
				PerPrice = Price;
			} else {
				PerPrice = 0.0;
			}
		}
		double GetPricePerItem() const {
			return PerPrice;
		}

		double GetInvoiceAmount() const {
			return Quantity * PerPrice;
		}
};

int main() {
	Invoice invoice("SD-0738", "Screw Driver", 7, 27.99);

    cout << "Part Number: " << invoice.GetPartNumber() << endl;
    cout << "Part Description: " << invoice.GetPartDescription() << endl;
    cout << "Quantity: " << invoice.GetQuantity() << endl;
    cout << "Price Per Item: $" << invoice.GetPricePerItem() << endl;
    cout << "Invoice Amount: $" << invoice.GetInvoiceAmount() << endl;

    invoice.SetQuantity(-5); 
    invoice.SetPricePerItem(-7.0); 
    cout << "\nAfter Setting Invalid Values:" << endl;
    cout << "Quantity: " << invoice.GetQuantity() << endl;
    cout << "Price Per Item: $" << invoice.GetPricePerItem() << endl;
    cout << "Invoice Amount: $" << invoice.GetInvoiceAmount() << endl;

    return 0;
}
