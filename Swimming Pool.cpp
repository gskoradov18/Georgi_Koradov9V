#include <iostream>
#include <string.h>
using namespace std;

struct SWIMMINGPOOL
{
	int age;
	float time;
	int id;
	float prize = 20;
	char dayofweek[3];


};

////////////////////////////////////////////////////
void insertCustomer(SWIMMINGPOOL orders[], int& customercount)
{
	cout << "Enter age: "; cout << endl;
	cin >> orders[customercount].age;
	cout << "Enter time: "; cout << endl;
	cin >> orders[customercount].time;
	cout << "Enter id: "; cout << endl;
	cin >> orders[customercount].id;
	cout << "Enter day: "; cout << endl;
	cin >> orders[customercount].dayofweek;
	customercount++;
}
void showCustomer(SWIMMINGPOOL orders)
{

	cout << "\nCustomer age: " << orders.age << endl;
	cout << "Customer time: " << orders.time << endl;
	cout << "Customer id: " << orders.id << endl;
	cout << "Day of week: " << orders.dayofweek << endl;
	cout << "Prize: " << orders.prize << endl;
	cout << endl;

}
void showAllcustomers(SWIMMINGPOOL orders[], int& customercount)
{
	if (customercount == 0)
	{
		cout << "There are no customers enterred "; cout << endl << endl;
		insertCustomer(orders, customercount);
	}
	else
	{
		for (int i = 0; i < customercount; i++)
		{
			showCustomer(orders[i]);
		}
	}

}

bool customersMenu(SWIMMINGPOOL orders[], int& customercount)
{
	cout << endl<<endl;
	int option;
	cout << "1. Insert customer: " << endl;
	cout << "2. Show all customers: " << endl;
	cout << "3. Exit " << endl;
	cout << "Choose an option: ";
	cin >> option;

	switch (option)
	{
	case 1:
		insertCustomer(orders, customercount);
		break;

	case 2: showAllcustomers(orders, customercount);
		break;
	case 3:return false;
		break;

	}
	return true;
}



int main()
{
	int customercount = 0;
	bool menu = true;
	SWIMMINGPOOL orders[100];
	menu = customersMenu(orders, customercount);
	do {
		menu = customersMenu(orders, customercount);
	} while (menu);
}
