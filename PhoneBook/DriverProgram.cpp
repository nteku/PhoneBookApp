#include <iostream>
using namespace std;

int main()
{

	int option;
	string optionOne;
	string optionTwo;

	cout << "******************************************************" << endl;
	cout << "       Welcome to your PhoneBook Application" << endl;
	cout << "******************************************************" << endl;
	cout << "Select any of the options: " << endl;
	cout << "1. Create a Phone Record" << endl;
	cout << "2. Update a Phone Record" << endl;
	cout << "3. Remove a Phone Record" << endl;
	cout << "4. Search if a Phone Record Exists" << endl;
	cout << "5. To Exit this Application" << endl;

	while (true) {

		 
		switch (option)
		{
		case 1:
			cout << "Please type the info for this phone record in the following order " << endl;
			cout << "First Name, Last Name, Phone Number, Location, Email" << endl;
			cin >> optionOne;

		case 2:
			cout << "What is the name of the phone record you would like to update " << endl;
		default:
			break;
		}
	}
}
