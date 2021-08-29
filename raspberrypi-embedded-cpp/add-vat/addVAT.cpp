// Mathias 23:08:2021

#include <iostream>
#include <string>
using namespace std;

int main()
{
	// price and vat variables
	int productPrice;
    int VAT;
	
	// write string and save input for both strings
	cout << "Enter price for a product: ";
	cin >> productPrice;
    cout << "Enter VAT to add: ";
	cin >> VAT;

	// calculated total price from price and vat input
	int totalPrice = productPrice * VAT / 100 + productPrice;

	// write total price out
	cout << "Total Product Price: " << totalPrice << endl;
	
	return 0;
}