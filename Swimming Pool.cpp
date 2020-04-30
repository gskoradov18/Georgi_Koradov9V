#include <iostream>
#include <string.h>
using namespace std;

struct SWIMMINGPOOL
{
	int age = 0;
	string FirstName = "";
	string LastName = "";
	int time = 0;
	int id = 0;
	string dayofweek = "";
	int price;

};
//inserting a customer
void insertCustomer(SWIMMINGPOOL* customers, int& customercount)
{
	cout << "Enter First name: ";
	cin >> customers[customercount].FirstName;
	cout << "Enter Last name: ";
	cin >> customers[customercount].LastName;
	cout << "Enter age: ";
	cin >> customers[customercount].age;
	cout << "Enter time (round hours only): ";
	cin >> customers[customercount].time;

	cout << "Enter day (the first three letters)(small letters only): ";
	cin >> customers[customercount].dayofweek;
	if (customers[customercount].dayofweek == "sat" or customers[customercount].dayofweek == "sun")
	{
		cout << endl;
		cout << "The pool is closed on Saturday and Sunday. ";
	}
	if (customers[customercount].dayofweek != "mon" and customers[customercount].dayofweek != "tue" and customers[customercount].dayofweek != "wed" and
		customers[customercount].dayofweek != "thr" and customers[customercount].dayofweek != "fri" and customers[customercount].dayofweek != "sun"
		and customers[customercount].dayofweek != "sat")
	{
		cout << "You have entered an incorrect day. ";
	}
	customercount++;
}

void createCustomer(SWIMMINGPOOL* customers, int& customercount, int& maxId, SWIMMINGPOOL newCusotmer)
{
	newCusotmer.id = maxId;
	customers[customercount] = newCusotmer;
	customercount++;
	maxId++;
}
//funstion for showing only one customer
void showCustomer(SWIMMINGPOOL customers)
{
	cout << "Customer's Full name: ";
	cout << customers.FirstName << " " << customers.LastName << endl;
	cout << "Customer's age: ";
	cout << customers.age << endl;
	cout << "Customer's time: ";
	cout << customers.time << endl;
	cout << "Customer's id: ";
	cout << customers.id << endl;
	cout << "Day of week: ";
	cout << customers.dayofweek << endl;
	cout << endl;

}
//funstion for showing all customers with loop
void showAllcustomers(SWIMMINGPOOL* customers, int& customercount)
{
		for (int i = 0; i < customercount; i++)
		{

			showCustomer(customers[i]);

		}
}

//getting customer index by his id
int getCustomerIndexById(SWIMMINGPOOL* customers, int& customercount, int id)
{
	for (int i = 0; i < customercount; i++)
	{
		if (customers[i].id == id)
		{
			return i;
		}
	}

	return -1;
}

//function which returns customers index
SWIMMINGPOOL getCustomer(SWIMMINGPOOL* customers, int& customercount, int id)
{
	int index = getCustomerIndexById(customers, customercount, id);
	return customers[index];
}

void updateCustomer(SWIMMINGPOOL* customers, SWIMMINGPOOL newCustomer, int& customercount, int id) 
{
	int index = getCustomerIndexById(customers, customercount, id);
	customers[index] = newCustomer;
}

//function for deleting a customer from the array
void deleteCustomer(SWIMMINGPOOL* customers, int& customercount, int id)
{
	int index = getCustomerIndexById(customers, customercount, id);
	for (int i = 0; i < customercount - 1; i++)
	{
		customers[i] = customers[i + 1];
	}
	customercount--;
}

//function which does something like sales 
void Prices(SWIMMINGPOOL* customers, int& customercount)
{

	for (int i = 0; i < customercount; i++)
	{
		if (customers[i].age >= 60 or customers[i].age <= 10)
		{
			customers[i].price = 6;
		}
		else
		{
			customers[i].price = 8;
		}

	}
}

//function which calculates the prices
int PriceCalculator(SWIMMINGPOOL* customers, int& customercount)
{
	int sum = 0;
	int timeIS;

	Prices(customers, customercount);

	for (int i = 0; i < customercount; i++)
	{
		timeIS = customers[i].time;
		sum = sum + (customers[i].price * timeIS);
	}

	return sum;
}



//presentation layer


//functions for finding customers by createria
void findCusotmersByDay(SWIMMINGPOOL* customers, int& customercount)
{
	string day;
	cout << "Enter day (in small letters): ";
	cin >> day;
	cout << endl;
	for (int i = 0; i < customercount; i++)
	{
		if (customers[i].dayofweek == day)
		{
			showCustomer(customers[i]);
		}
		else
		{
			cout << "There is no customer by this creteria";
		}
	}
}

//functions for finding customers by createria
void findCusotmersByTime(SWIMMINGPOOL* customers, int& customercount)
{
	int time;
	cout << "Enter time: ";
	cin >> time;
	cout << endl;
	for (int i = 0; i < customercount; i++)
	{
		if (customers[i].time = time)
		{
			showCustomer(customers[i]);
		}
		else
		{
			cout << "There is no customer by this creteria";
		}
	}
}

//functions for finding customers by createria
void findCusotmersByAge(SWIMMINGPOOL* customers, int& customercount)
{
	int age;
	cout << "Enter age: ";
	cin >> age;
	cout << endl;
	for (int i = 0; i < customercount; i++)
	{
		if (customers[i].age = age)
		{
			showCustomer(customers[i]);
		}
		else
		{
			cout << "There is no customer by this creteria";
		}
	}
}

//function for choosing which the customer you want to delete with id
void deleteCustomerByID(SWIMMINGPOOL* customers, int& customercount)
{
	int id;
	cout << "Enter the id of the customer you want to delete: ";
	cin >> id;
	deleteCustomer(customers, customercount, id);
}

//the mneu for searching customer by diffrent criterias
void findCustomerMenu(SWIMMINGPOOL* customers, int& customercount)
{
	int age, time, choice;
	char dayOfWeek[3];
	cout << endl << endl;
	cout << "Which option you want to use" << endl << endl;
	cout << "1. Find customer by the time" << endl;
	cout << "2. Find customer by the age" << endl;
	cout << "3. Find customer by the day" << endl << endl;
	cout << "Your choice: "; cin >> choice;


	switch (choice)
	{
	case 1:
		findCusotmersByTime(customers, customercount);
		break;
	case 2:
		findCusotmersByAge(customers, customercount);
		break;
	case 3:
		findCusotmersByDay(customers, customercount);

	}


}

//the menu for the prices
void PriceMenu(SWIMMINGPOOL* customers, int& customercount)
{
	int Sum = 0;
	Sum = PriceCalculator(customers, customercount);
	cout << " The income for the week is: $" << Sum;
}


//function for editing a customer
void editCusotmerMenu(SWIMMINGPOOL* customers, int& customercount, int& maxId)
{
	int id;
	int choice;
	cout << endl;
	showAllcustomers(customers, customercount);
	cout << "Enter id: ";
	cin >> id;
	cout << endl;

	cout << "1. Change age" << endl;
	cout << "2. Change time" << endl;
	cout << "3. Change name" << endl;
	cout << "4. Change day of week" << endl << endl;
	cout << "Choose an option: ";
	cin >> choice;

	SWIMMINGPOOL customer = getCustomer(customers, customercount, id);


	switch (choice)
	{
	case 1:
		cout << "Enter the new age: ";
		cin >> customer.age;
		updateCustomer(customers, customer, customercount, id);
		break;
	case 2:
		cout << "Enter the new time (round hours only): ";
		cin >> customer.time;
		updateCustomer(customers, customer, customercount, id);
		break;
	case 3:
		cout << "Enter new name: ";
		cin >> customer.FirstName >> customer.LastName;
		updateCustomer(customers, customer, customercount, id);
		break;
	case 4:
		cout << "Enter new Day of week (the first three letters)(small letters only): ";
		cin >> customer.dayofweek;
		updateCustomer(customers, customer, customercount, id);
		break;
	default: cout << "Incorrect Input";
		break;


	}

}


//menu for choosing all the functions
bool customersMenu(SWIMMINGPOOL* customers, int& customercount, int& maxId,bool &flag)
{	
	cout << endl << endl;

	int option;

	cout << "1. Insert customer" << endl;
	cout << "2. Show all customers" << endl;
	cout << "3. Edit customer" << endl;
	cout << "4. Delete customer" << endl;
	cout << "5. Find customers by creteria" << endl;
	cout << "6. Price" << endl;
	cout << "7. Exit" << endl << endl;
	cout << "Choose an option: ";
	cin >> option;

	switch (option)
	{
	case 1:
		insertCustomer(customers, customercount);
		flag = true;
		break;
	case 2:
		if (flag == true) {
			showAllcustomers(customers, customercount);
		}
		else { cout << endl; cout << "incorrect input."; }
		break;

	case 3:
		if (flag == true) {
			editCusotmerMenu(customers, customercount, maxId);
		}
		else { cout << endl; cout << "incorrect input"; }
		break;

	case 4:
		if (flag == true) {
			deleteCustomerByID(customers, customercount);
		}
		else { cout << endl; cout << "incorrect input"; }
		break;

	case 5:
		if (flag == true) {
			findCustomerMenu(customers, customercount);
		}
		else { cout << endl; cout << "incorrect input"; }
		break;
	case 6:
		if (flag == true) {
			PriceMenu(customers, customercount);
		}
		else { cout << endl; cout << "incorrect input"; }
		break;

	case 7:
		cout << "Have a nice day!";
		return false;

		break;
	default:cout << "Incorrect input. Choose an avaliable option from the menu" << endl;

	}
	return true;
}

void Welcoming()
{
	cout << endl;
	cout << "Hello user!" << endl;
	cout << "Welcome to our project called SWIMMING POOL!" << endl;
	cout << "I hope you are having a wonderful day!" << endl << endl;
}

int main()
{
	Welcoming();

	int customercount = 0;
	int maxId = 0;
	bool menu = true;
	bool flag;

	SWIMMINGPOOL customers[100];

	menu = customersMenu(customers, customercount, maxId, flag);

	do {
		menu = customersMenu(customers, customercount, maxId, flag);
	} while (menu);

}
