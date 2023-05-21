#include <unordered_map>
#include <string>
#include <stdexcept>  
#include <memory>   
#include <iostream>

using namespace std;
class Contact {

private:
   
	string firstName;
	string lastName;
	string phoneNumber;
	string location;
	string email;
	shared_ptr <Contact> next;


public:
	 

	Contact(string firstName, string lastName, string phoneNumber, string location, string email) {
		this->firstName = firstName;
		this->lastName = lastName;
		this->phoneNumber = phoneNumber;
		this->location = location; 
		this->email = email;

		next = nullptr;
	}

	 
	bool validPhoneNumber(string phoneNumber) {

		for (auto itr = phoneNumber.begin(); itr != phoneNumber.end(); itr++) {
			if (!isdigit(*itr)) {
				return false;
			}
		}

		return true;
	}

	bool validInfo(string phoneRecord) {
		
		for (int i = 0; i < phoneRecord.size(); i++) {
			 
		}
	}

	void setFirstName(string fName) {
		this->firstName = fName;
	}
	string getFirstName() {
		return firstName;
	}

	void setLastName(string lName) {
		this->lastName = lName;
	}

	string getLastName() {
		return lastName;
	}

	void setPhoneNumber(string pNumber) {

		string temp = pNumber.substr(0,3) + "-" + pNumber.substr(3,3) + "-" + pNumber.substr(6,3);
		this->phoneNumber = temp;
	}

	string getPhoneNumber() {
		return phoneNumber;
	}

	void setLocation(string tempLocation) {
		this->location = tempLocation;
	}

	string getLocation() {
		return location;
	}

	void setEmail(string tempEmail) {
		this->email = tempEmail;
	}

	string getEmail() {
		return email;
	}

	shared_ptr <Contact> getNext() {
		return next;
	}

	void setNext(shared_ptr <Contact> nextNode) {
		next = nextNode;
	}
};