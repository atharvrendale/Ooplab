#include<iostream>
#include<string.h>
#include<iomanip>
using namespace std;

class Movie{
	public: 
	string name;
	float sold_tickets;
	float ticket_price;
	float d;
	float gross_amount;
	float donation;
	float Net_sale;

	
void get_Data() {
        cout << "Enter the name of Movie" << endl;
        cin >> name;
        cout << "Enter the Ticket price" << endl;
        cin >> ticket_price;
        cout << "Enter the no of solded tickets " << endl;
        cin >> sold_tickets;
        cout << "Enter the donation (percentage) " << endl;
        cin >> d;
}

void Display(){
	cout<<"Name of the Movie is :  "<<setw(8)<<setfill('*')<<name<<endl;
	cout<<"No of solded tickets are :  "<<setw(4)<<setfill('*')<<sold_tickets<<endl;
	cout<<"Gross amount:  "<<setw(17)<<setfill('*')<<sold_tickets*ticket_price<<endl;
	cout<<"Donated amount :  "<<setw(14)<<setfill('*')<<d/100*(sold_tickets*ticket_price)<<endl;
	cout<<"Net sale is:   "<<setw(17)<<setfill('*')<<(sold_tickets*ticket_price)-(d/100*(sold_tickets*ticket_price))<<endl;
}

}; 
int main() {
    Movie m1;
    m1.get_Data();
    cout<<endl;
    m1.Display();
    cout<<endl;
    
    return 0;
}



