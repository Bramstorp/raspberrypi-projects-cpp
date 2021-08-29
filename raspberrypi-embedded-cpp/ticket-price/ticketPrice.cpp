#include <iostream>
#include <string>
using namespace std;

int main()
{
	int age;
    int rate;
    int ticketPrice;

	cout << "Enter age: ";
	cin >> age;
    cout << "Enter Ticket price: ";
	cin >> ticketPrice;

    if (age < 12) {
        ticketPrice = 0;
    } 
    else if (age < 24){
        ticketPrice = ticketPrice * 30 / 100;
    } 
    else if (age < 65){
        ticketPrice = ticketPrice;
    }
    else if (age > 65){
        ticketPrice = ticketPrice * 25 / 100 ;
    }

    cout << "you ticket price is "<< ticketPrice <<endl;
	
	return 0;
}
