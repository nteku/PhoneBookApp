#include <iostream>
#include <vector>
#include "Contact.hpp"
using namespace std;

int main()
{

	int option;
	string optionOne;
	string optionTwo;
	string firstName;
	string lastName;
	string phoneNumber;
	string location;
	string email;
	vector <Contact> contacts;
	 

	cout << "******************************************************" << endl;
	cout << "       Welcome to your PhoneBook Application" << endl;
	cout << "******************************************************" << endl;
	cout << "Select any of the options: " << endl;
	cout << "1. Create a Phone Record." << endl;
	cout << "2. Update a Phone Record." << endl;
	cout << "3. Remove a Phone Record." << endl;
	cout << "4. Search if a Phone Record Exists." << endl;
	cout << "Press any key besides the numbers above to exit the application." << endl;
	
	while (true) {

		cin >> option;
		switch (option)
		{
		case 1:
			cout << "Please type the info for this phone record in the following order " << endl;
			cout << "First Name, Last Name, Phone Number, Location, Email" << endl;
			cin >> optionOne;

		case 2:
			cout << "What is the name of the phone record you would like to update " << endl;
			cin >> optionTwo;


		
		default:
			exit(0);
		}
	}
}


void checkContact() {

}
