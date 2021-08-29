// Mathias 23:08:2021

#include <iostream>
#include <string>
using namespace std;

int main()
{

    // age variable
	int age;

    // string variable for raiting
    string raiting;

    // prints out input message
	cout << "Enter age: ";

    // save input message in age variable
	cin >> age;

    // age if statment checker
    if (age >= 18) {
        raiting = "R rated";
    }
    else if (age >= 13 && age < 18 ) {
        raiting = "PG-13";
    }
    else {
        raiting = "PG";
    }

    // prints out riting from the if statments
    cout << "you can watch "<< raiting << " movies" <<endl;
	
	return 0;
}
