#include <iostream>
#include <vector>
#include "Contact.hpp"
#include "PhoneBook.hpp"
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
	PhoneBook phoneBook;
	 
	 

	cout << "******************************************************" << endl;
	cout << "       WELCOME TO YOUR PHONEBOOK" << endl;
	cout << "******************************************************" << endl;
	 
	
	while (true) {
		cout << "Select any of the options: " << endl;
		cout << "1. Create a Phone Record." << endl;
		cout << "2. Update a Phone Record." << endl;
		cout << "3. Remove a Phone Record." << endl;
		cout << "4. Search if a Phone Record Exists." << endl;
		cout << "5. Display all Contacts. " << endl;
		cout << "Press any key besides the numbers above to exit the application." << endl;

		cin >> option;
		switch (option)
		{
		case 1:
			cout << "Please type the info for this phone record in the following order " << endl;
			cout << "First Name, Last Name, Phone Number, Location, Email" << endl;
			cin >> firstName >> lastName >> phoneNumber >> location >> email;
			phoneBook.addContact(firstName, lastName, phoneNumber, location, email);
			break;
			

		case 2:
			cout << "What is the name of the phone record you would like to update " << endl;
			cin >> firstName >> lastName;
			break;

		case 3:
			phoneBook.removeContact();
			break;

		case 5:
			phoneBook.displayContacts();
			break;
		default:
			exit(0);
		}
	}
}


void checkContact() {

}
