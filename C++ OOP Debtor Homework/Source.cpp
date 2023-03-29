#include <iostream>
#include <string>
#include <list>
#include <algorithm>
using namespace std;

#include "Debtor.h"
#include "Datas.h"


int main() {
	cout << "SORTED BY RHYTA.COM AND DAYREP.COM\n\n\n";
		
	for_each(begin(debtors), end(debtors), [](Debtor*& deb)->void {
		string rhyta = "rhyta.com";
		string dayrep = "dayrep.com";
		for (int i = 1; i < deb->getEmail().size(); i++) {
			if (deb->getEmail()[i - 1] == '@') {
				int index = 0;
				for (int j = i; deb->getEmail()[j] == rhyta[index++] && j < deb->getEmail().size() - 1; j++) {}
				if (index == rhyta.size()) cout << *deb << endl;
				else {
					index = 0;
					for (int j = i; deb->getEmail()[j] == dayrep[index++] && j < deb->getEmail().size() - 1; j++) {}
					if (index == dayrep.size()) cout << *deb << endl;
				}
			}
		}
	});

	cout << "SORTED BY between 26 and 36 year old.\n\n\n";


	for_each(begin(debtors), end(debtors), [](Debtor*& deb)->void {
		string year;
		year.resize(4);
		int index = 0;
		for (int i = deb->getBirthDay().size() - 4; i < deb->getBirthDay().size(); i++) year[index++] = deb->getBirthDay()[i];
		if (2023 - typecast_str(year) >= 26 && 2023 - typecast_str(year) <= 36) cout << *deb << endl;
	});


	cout << "SORTED BY Debt Less Than 5000.\n\n\n";

	for_each(begin(debtors), end(debtors), [](Debtor*& deb)->void {
		if (deb->getDebt() <= 5000) cout << *deb << endl;
	});

	cout << "SORTED BY 18 Symbol Name.\n\n\n";

	for_each(begin(debtors), end(debtors), [](Debtor*& deb)->void {
		if (deb->getName().size() > 18) {
			bool have2 = false;
			bool have27 = false;
			if (deb->getPhone().find("2") != string::npos) have2 = true;
			if (deb->getPhone().find("7") != string::npos && deb->getPhone().rfind("7") != string::npos) {
				if (deb->getPhone().find("7") != deb->getPhone().rfind("7")) have27 = true;
			}if (have2 || have27) cout << *deb << endl;
		}
	});

	cout << "SORTED BY People Born in Winter.\n\n\n";

	for_each(begin(debtors), end(debtors), [](Debtor*& deb)->void {
		int len = 0;
		for (int i = 0; deb->getBirthDay()[i] != ' '; i++) len++;
		if (!deb->getBirthDay().compare(0, len, "January") ||
			!deb->getBirthDay().compare(0, len, "February") ||
			!deb->getBirthDay().compare(0, len, "December")) cout << *deb << endl;
	});

	cout << "SORTED BY Debt Higher than avarage debt.\n\n\n";

	int sum = 0;
	int avg;
	for (auto& i : debtors) {
		sum += i->getDebt();
	}
	avg = sum / debtors.size();

	debtors.sort([](Debtor* d1, Debtor* d2)->auto {
		int surname = d1->getName().find(' ') + 1;
		int surname2 = d2->getName().find(' ') + 1;
		if (d1->getName()[surname] == d2->getName()[surname2]) {
			if (d2->getDebt() < d1->getDebt()) return true;
		}return d1->getName()[surname] < d2->getName()[surname2];
	});

	for_each(begin(debtors), end(debtors), [&avg](Debtor*& deb)->void {
		if (deb->getDebt() > avg) cout << *deb << endl;
	});

	cout << "PRINTED SURNAME AGE DEBT BY not 8 number in phone.\n\n\n";

	for_each(begin(debtors), end(debtors), [&avg](Debtor*& deb)->void {
		if (deb->getPhone().find("8") == string::npos) deb->show();
		else cout << *deb; cout << endl;
	});

	cout << "SORTED NAME SURNAME SAME 3 CHAR\n\n\n";

	debtors.sort([](Debtor* d1, Debtor* d2)->auto {
		return d2->getDebt() < d1->getDebt();
	});

	for_each(begin(debtors), end(debtors), [](Debtor*& deb)->void {
		int surname = deb->getName().find('.') + 2, count = 0;
		string surnames;
		surnames.resize(deb->getName().size() - (surname + 1));
		for (int i = surname; i < deb->getName().size(); i++) surnames[i - surname] = deb->getName()[i];
		for (int i = 0; deb->getName()[i] != ' '; i++) {
			if (surnames.find(deb->getName()[i]) != string::npos) count++;
		}if (count >= 3) cout << *deb << endl;
	});

	cout << "MOST YEAR \n\n\n";

	list<short> years;

	for (auto& i : debtors) {
		string year;
		year.resize(4);
		short index = 0, age;
		for (int j = i->getBirthDay().size() - 4; j < i->getBirthDay().size(); j++) year[index++] = i->getBirthDay()[j];
		years.push_back(typecast_str(year));
	}
	short defaultMax = count(years.begin(), years.end(), years.front());
	short most = years.front();

	for (auto& i : years) {
		int inside = count(years.begin(), years.end(), i);
		if (inside > defaultMax) {
			most = i;
		}
	}
	for_each(begin(debtors), end(debtors), [&most](Debtor*& deb)->void {
		string year;
		year.resize(4);
		int index = 0;
		for (int i = deb->getBirthDay().size() - 4; i < deb->getBirthDay().size(); i++) year[index++] = deb->getBirthDay()[i];
		if (typecast_str(year) == most) cout << *deb << endl;
	});

	cout << "PRINT MOST 5 DEBTOR\n\n\n";

	debtors.sort([](Debtor* d1, Debtor* d2)->auto {
		return d2->getDebt() < d1->getDebt();
	});
	for_each(begin(debtors), debtors.end(), [&most](Debtor*& deb)->void {
		static int sint = 0;
		if (sint != 5) {
			cout << *deb << endl;
			sint++;
		}
	});

	cout << "Sum of Debts\n";
	int sums = 0;
	for (auto& i : debtors) {
		sums += i->getDebt();
	}cout << sums << endl;

	cout << "PRINT PEOPLE SAW SECOND WWAR\n\n\n";

	for_each(begin(debtors), end(debtors), [](Debtor*& deb)->void {
		string year;
		year.resize(4);
		int index = 0;
		for (int i = deb->getBirthDay().size() - 4; i < deb->getBirthDay().size(); i++) year[index++] = deb->getBirthDay()[i];
		if (typecast_str(year) >= 1939 && 1945 >= typecast_str(year)) cout << *deb << endl;
	});

	cout << "PRINT NOT SAME NUMBERS IN PHONE NUMBER\n\n\n";

	for_each(begin(debtors), end(debtors), [](Debtor*& deb)->void {
		bool issame = false;
		for (int i = 0; i < deb->getPhone().size(); i++) {
			if (count(deb->getPhone().begin(), deb->getPhone().end(), deb->getPhone()[i]) != 1 && deb->getPhone()[i] != '-') issame = true;
		}if (!issame) cout << *deb << endl;
	});

	cout << "Tesevvur edek ki,butun borclari olanlar bugunden etibaren her ay 500 azn pul odeyecekler. Oz ad gunune kimi borcun oduyub qurtara bilenlerin siyahisin cixartmaq\n\n\n";

	for_each(begin(debtors), end(debtors), [](Debtor*& deb)->void {
		string month;
		int monthi = 0;
		int currentmonth = 3;
		int len = 0;
		for (int i = 0; deb->getBirthDay()[i] != ' '; i++) len++;
		month.resize(len);
		for (int i = 0; deb->getBirthDay()[i] != ' '; i++) month[i] = deb->getBirthDay()[i];
		if (month == "January") monthi = 1;
		else if (month == "February") monthi = 2;
		else if (month == "March") monthi = 3;
		else if (month == "April") monthi = 4;
		else if (month == "May") monthi = 5;
		else if (month == "June") monthi = 6;
		else if (month == "July") monthi = 7;
		else if (month == "August") monthi = 8;
		else if (month == "September") monthi = 9;
		else if (month == "October") monthi = 10;
		else if (month == "November") monthi = 11;
		else if (month == "December") monthi = 12;
		int sub;
		if (monthi <= currentmonth) sub = 12 - (currentmonth - monthi);
		else sub = monthi - currentmonth;
		if (sub * 500 >= deb->getDebt()) cout << *deb << endl;
	});

	cout << "Adindaki ve familyasindaki herflerden \"smile\" sozunu yaza bileceyimiz borclularin siyahisini cixartmaq\n\n\n";

	for_each(begin(debtors), end(debtors), [](Debtor*& deb)->void {
		if (count(deb->getName().begin(), deb->getName().end(), 's') != 0 && count(deb->getName().begin(), deb->getName().end(), 'm') != 0
		&& count(deb->getName().begin(), deb->getName().end(), 'i') != 0 && count(deb->getName().begin(), deb->getName().end(), 'l') != 0
			&& count(deb->getName().begin(), deb->getName().end(), 'e') != 0) cout << *deb << endl;
	});
}