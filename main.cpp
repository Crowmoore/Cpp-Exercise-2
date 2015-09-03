#include <iostream>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <resource.h>

using namespace std;

vector<dogInfo> dogs;
string getUserString();
int getUserInteger();
bool compareAges(const dogInfo& firstAge, const dogInfo& secondAge);
void sortAges();
dogInfo getDogDetails();
void addNewDog();
void printDogs();
int menuSelection();
void clearScreen();

int main() {

    int selection = -1;
	while (selection != 0) {
		cout << "What you would like to do?" << endl;
        cout << "0. Exit" << endl;
        cout << "1. Add a new dog" << endl;
        cout << "2. Sort dogs by age" << endl;
        selection = menuSelection();
	}

}
bool compareAges(const dogInfo& firstAge, const dogInfo& secondAge) {

    return firstAge.dogAge < secondAge.dogAge;
}

void sortAges() {

    sort(dogs.begin(), dogs.end(), compareAges);
}

void printDogs() {
    clearScreen();
    sortAges();
    for(int i = 0; i < dogs.size(); i++) {
        cout << "Dog no. " << i + 1 << ": " << dogs[i].dogName << " " << dogs[i].dogAge << endl;
    }
    system("pause");
    clearScreen();
}

int menuSelection() {

    int userSelection = getUserInteger();
    switch (userSelection)
    {
        case 0: return 0;
                break;
        case 1: addNewDog();
                break;
        case 2: printDogs();
                break;
        default: cout << "Choose from the listed options! Press Enter to continue.";
                cin.get();
    }
    return 1;

}

void addNewDog() {

    clearScreen();
    dogInfo dog = getDogDetails();
    dogs.push_back(dog);
    clearScreen();
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
void clearScreen() {
    system("CLS");
}
