#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

int main(int argc,char* argv[]){
    string moviename;
	float atp;//adult ticket price
	float ctp;//children ticket price
	int an;//number of adult tickets sold
	int cn;//number of child ticket sold
	float donation;
	int ts;//ts is total ticket sold;
	float tp;//tp is total price of all tickets
	float net;

	cout<<"Movie Name: ";
	getline(cin,moviename);
	cout<<"price of adult ticket: ";
	cin>>atp;
	cout<<"price of child ticket: ";
	cin>>ctp;
	cout<<"Number of adult tickets Sold: ";
	cin>>an;
	cout<<"Number of child tickets Sold: ";
	cin>>cn;
	cout<<"Percentage of donation: ";
	cin>>donation;
    ts=cn+an;
	tp=(atp*an)+(ctp*cn);
	float donated=(donation/100)*tp;
	net=tp-donated;

	cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<<endl;
    cout << left << setw(35) << "Movie Name:" << moviename <<endl;
    cout << left << setw(35) << "Number of Tickets Sold:" << ts << endl;
    cout << left << setw(35) << "Gross Amount:" << "$ " << fixed << setprecision(2) << tp << endl;
    cout << left << setw(35) << "Percentage of Gross Amount Donated:" << donation << "%" << endl;
    cout << left << setw(35) << "Amount Donated:" << "$ " << fixed <<setprecision(2) << donated << endl;
    cout << left << setw(35) << "Net Sale:" << "$ " << fixed << setprecision(2) << net << endl;
    cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<<endl;

    return 0;
}
	

	
