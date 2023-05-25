#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>  
#include <memory>     
 

class PhoneBook {

private:

	shared_ptr <Contact> head;

public:



	PhoneBook() {
		head = nullptr;
	}


	void addContact(string firstName, string lastName, string phoneNumber,
		string location, string email) {

		shared_ptr <Contact> contact = make_shared<Contact>(firstName, lastName, phoneNumber, location, email);


		if (head == nullptr) {

			head = contact;
			cout << "\n\nSucessfully added contact.\n" << endl;
			return;
		}


		shared_ptr <Contact> cur = head;

		if (contactExists(firstName, lastName)) {

			cout << "This contact already exists" << endl;
			return;
		}

		while (cur->getNext() != nullptr) {
			cur = cur->getNext();
		}

		cur->setNext(contact);

		cout << "\n\nSucessfully added contact.\n" << endl;
	}


	void removeContact() {

		string firstName;
		string lastName;

		if (isEmpty()) {
			return;
		}


		cout << "Type the first name and the last name of the contact you want to remove." << endl;
		cin >> firstName >> lastName;



		if (!contactExists(firstName, lastName)) {
			cout << endl << "This contact does not exist." << endl << endl;
			return;
		}


		if ((head->getFirstName() == firstName) && (head->getLastName() == lastName)) {
			shared_ptr <Contact> temp = head->getNext();

			head = temp;

			cout << "Sucessfully removed contact" << endl;
			return;
		}


		shared_ptr <Contact> cur = head;


		while (cur->getNext() != nullptr) {

			if ( (cur->getNext()->getFirstName() == firstName) && (cur->getNext()->getLastName() == lastName) ) {

				cur->getNext() = cur->getNext()->getNext();

				cout << "Sucessfully removed contact" << endl;
				break;
			}

			cur = cur->getNext();
		}
	}


	void updatingContact() {

		if (isEmpty()) {

			cout << "This phonebook has no contacts.\n" << endl;
		}
		string firstName;
		string lastName;
		
		string prev;
		string rep;
		int option;

		cout << "Who do you want to update?" << endl;
		cin >> firstName >> lastName;

		if (!contactExists(firstName, lastName)) {
			cout << "This contact does not exist.\n" << endl;
			return;
		}

		shared_ptr <Contact> contact = getContact(firstName, lastName);

		cout << "What do you want to update" << endl;
		cout << "1 for First Name\n2 for Last Name\n3 for Phone Number\n4 for Location\n5 for Email." << endl;
		cin >> option;

		switch (option) {

		case 1:
			cout << "\nWhat would you like to update the first name to?" << endl;
			cin >> rep;
			finishUpdating("firstName", firstName, rep);
			break;
		case 2:
			cout << "\nWhat would you like to update the last name to?" << endl;
			cin >> rep;
			finishUpdating("lastName", lastName, rep);
			break;
		case 3:
			cout << "\nWhat would you like to update the phone number to?" << endl;
			cin >> rep;
			finishUpdating("phoneNumber", contact->getPhoneNumber(), rep);
			break;
		case 4:
			cout << "\nWhat would you like to update " << firstName << "'s location to ? " << endl;
			cin >> rep;
			finishUpdating("location", contact->getLocation(), rep);
			break;
		case 5:
			cout << "\nWhat would you like to update the contact's email to?" << endl;
			cin >> rep;
			finishUpdating("phoneNumber", contact->getPhoneNumber(), rep);
			break;
		}



	}

	shared_ptr <Contact> getContact(string firstName, string lastName) {
		shared_ptr <Contact> cur = head;
	
		while (cur != nullptr) {

			if ((cur->getFirstName() == firstName) && (cur->getLastName() == lastName))
				return cur;
		}

		return nullptr;
	}


	void finishUpdating(string op, string prev, string replacement) {
		shared_ptr <Contact> cur = head;

		if (op == "firstName") {

			while (cur != nullptr) {
				if (cur->getFirstName() == prev) {
					cur->setFirstName(replacement);
					break;
				}
			}
		}

		if (op == "lastName") {

			while (cur != nullptr) {
				if (cur->getLastName() == prev) {
					cur->setLastName(replacement);
					break;
				}
			}
		}

		if (op == "phoneNumber") {

			while (cur != nullptr) {
				if (cur->getPhoneNumber() == prev) {
					cur->setPhoneNumber(replacement);
					break;
				}
			}
		}


		if (op == "location") {

			while (cur != nullptr) {
				if (cur->getLocation() == prev) {
					cur->setLocation(replacement);
					break;
				}
			}
		}


		if (op == "email") {

			while (cur != nullptr) {
				if (cur->getEmail() == prev) {
					cur->setEmail(replacement);
					break;
				}
			}
		}

		cout << "This contact has offically been updated.\n" << endl;
	}


	bool contactExists(string firstName, string lastName) {
		shared_ptr <Contact> cur = head;
         
		while (cur != nullptr) {
			
			if ((cur->getFirstName() == firstName) && (cur->getLastName() == lastName))   {

				return true;
			}

			cur = cur->getNext();
		}

		return false;
	}

	void displayContacts() {
		shared_ptr <Contact> cur = head;

		if (head == nullptr) {
			cout << "There are no contacts avaialble." << endl << endl;
			return;
		}

		while (cur != nullptr) {

			cout << "\n\n*********************************************************************" << endl;
			cout << "First Name: " << cur->getFirstName() << endl;
			cout << "Last Name: " << cur->getLastName() << endl;
			cout << "Phone Number: " << cur->getPhoneNumber() << endl;
			cout << "Location: " << cur->getLocation() << endl;
			cout << "Email: " << cur->getEmail() << endl;
		 
			 
			cur = cur->getNext();
		}
		
		cout << endl << endl;
	}


	bool isEmpty() {

		if (head == nullptr) {

			cout << endl << "Your contact list is currently empty" << endl << endl;
			return true;
		}

		return false;
	}
};