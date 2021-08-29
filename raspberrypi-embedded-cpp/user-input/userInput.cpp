// Mathias 23:08:2021

#include <iostream>
#include <string>
using namespace std;

int main()
{
	// fullName variable
	string fullName;

	// age variable
	int age;
	
	// input for enter fullname
	cout << "Enter fullname: ";

	// get and save input
	getline(cin, fullName);

	// input for age
	cout << "Enter age: ";

	// save input
	cin >> age;
	
	// write out age and fullname variables
	cout << "Your name is: " << fullName << endl;
	cout << "Your age is: " << age << endl;
	
	return 0;
}