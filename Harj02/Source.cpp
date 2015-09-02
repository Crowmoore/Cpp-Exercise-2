#include <iostream>
#include <sstream>
//#include <struct.h>

using namespace std;

struct dogInfo
{
	string dogName;
	int dogAge;
};

int numberOfDogs;
int selection = 1;
dogInfo dog;

string getUserString();
int getUserInteger();
dogInfo getDogDetails();

int main() {

	while (selection != 0) {
		system("CLS");
		cout << "Enter a new dog? (1/0):\n ";
		cin >> selection;
		cin.ignore(1, '\n');
		if (selection != 0) {
			dogInfo dog = getDogDetails();
			numberOfDogs++;
		}
		else {
			for (int i = 0; i < numberOfDogs; i++) {
				cout << "Dog " << i + 1 << " ";
			}
			system("pause");
			return 0;
		}
	}
}

dogInfo getDogDetails() {

	struct dogInfo dog;
	cout << "Dog details\n";
	cout << "Name: ";
	dog.dogName = getUserString();
	cout << "Age: ";
	dog.dogAge = getUserInteger();
	return dog;
}

int getUserInteger() {

	int userInt;
	cin >> userInt;
	cin.ignore(1, '\n');
	return userInt;

}

string getUserString() {

	string userString;
	getline(cin, userString);
	return userString;
}


