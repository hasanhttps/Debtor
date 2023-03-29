#pragma once


int typecast_str(string data) {
	int str_int = 0;
	for (int i = 0; i < data.size(); i++) str_int = str_int * 10 + data[i] - 48;
	return str_int;
}

class Debtor {
	string _fullName;
	string _birthDay;
	string _phone;
	string _email;
	string _address;
	int _debt;
public:

	// Constructors

	Debtor() = default;
	Debtor(string fullName, string birthDay, string phone, string email, string address, int debt) :
		_fullName(fullName), _birthDay(birthDay), _phone(phone), _email(email), _address(address), _debt(debt) { }

	// Acsessors

	// Setters

	void setName(string fullName) { _fullName = fullName; }
	void setBirthDay(string birthDay) { _birthDay = birthDay; }
	void setPhone(string phone) { _phone = phone; }
	void setEmail(string email) { _email = email; }
	void setAddress(string address) { _address = address; }
	void setDebt(int debt) { _debt = debt; }

	// Getters

	string& getName() { return _fullName; }
	string& getBirthDay() { return _birthDay; }
	string& getPhone() { return _phone; }
	string& getEmail() { return _email; }
	string& getAddress() { return _address; }
	int getDebt() { return _debt; }

	// Functions

	void show() {
		string year;
		int age;
		year.resize(4);
		int index = 0;
		for (int i = _birthDay.size() - 4; i < _birthDay.size(); i++) year[index++] = _birthDay[i];
		age = 2023 - typecast_str(year);
		cout << "Surname : " << _fullName[_fullName.find(' ') + 1] << endl;
		cout << "Age : " << age << endl;
		cout << "Debt : " << _debt << endl;
	}

	// Function Overloading

	friend ostream& operator<<(ostream& print, const Debtor& other) {
		cout << "Full Name : " << other._fullName << endl
			 << "Birth Day : " << other._birthDay << endl
			 << "Phone : " << other._phone << endl
			 << "Email : " << other._email << endl
			 << "Address : " << other._address << endl
			 << "Debt : " << other._debt << endl;

		return print;
	}

};