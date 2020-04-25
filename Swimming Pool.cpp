#include <iostream>
#include <string.h>
using namespace std;

struct SWIMMINGPOOL
{
	int age = 0;
	string FirstName = "";
	string LastName = " ";
	int time = 0;
	int id = 0;
	string dayofweek = " ";
	int prize;

};

void Welcoming()
{
	cout << endl;
	cout << "Hello user!" << endl;
	cout << "Welcome to our project called SWIMMINGPOOL!" << endl;
	cout << "I hope you are having a wonderful day!" << endl << endl;
}

void insertCustomer(SWIMMINGPOOL* customers, int& customercount)
{
	cout << "Enter First name: ";
	cin >> customers[customercount].FirstName;
	cout << "Enter Last name: ";
	cin >> customers[customercount].LastName;
	cout << "Enter age: ";
	cin >> customers[customercount].age;
	cout << "Enter time: ";
	cin >> customers[customercount].time;

	cout << "Enter day: ";
	cin >> customers[customercount].dayofweek;
	if (customers[customercount].dayofweek == "sat" or customers[customercount].dayofweek == "sun")
	{
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

void showAllcustomers(SWIMMINGPOOL* customers, int& customercount)
{
	if (customercount == 0)
	{
		cout << "There are no customers enterred " << endl; cout << "Please insert customer's info"; cout << endl << endl;

		insertCustomer(customers, customercount);
	}
	else
	{
		for (int i = 0; i < customercount; i++)
		{

			showCustomer(customers[i]);

		}
	}

}

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

SWIMMINGPOOL getCustomer(SWIMMINGPOOL* customers, int& customercount, int id)
{
	int index = getCustomerIndexById(customers, customercount, id);
	return customers[index];
}



void updateCustomer(SWIMMINGPOOL* customers, SWIMMINGPOOL newCustomer, int& customercount, int id) {
	int index = getCustomerIndexById(customers, customercount, id);
	customers[index] = newCustomer;
}

void editCusotmer(SWIMMINGPOOL* customers, int& customercount, int& maxId)
{
	int id;
	int choice;

	cout << "Enter id: ";
	cin >> id;
	cout << "1. Change age" << endl;
	cout << "2. Cahnge time" << endl;
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
		cout << "Enter the new time: ";
		cin >> customers->time;
		updateCustomer(customers, customer, customercount, id);
		break;


	}

}

void deleteCustomer(SWIMMINGPOOL* customers, int& customercount, int id)
{
	int index = getCustomerIndexById(customers, customercount, id);
	for (int i = 0; i < customercount - 1; i++)
	{
		customers[i] = customers[i + 1];
	}
	customercount--;
}

void Prices(SWIMMINGPOOL* customers, int& customercount)
{

	for (int i = 0; i < customercount; i++)
	{
		if (customers[i].age >= 60 or customers[i].age <= 10)
		{
			customers[i].prize = 10;
		}
		else
		{
			customers[i].prize = 20;
		}

	}
}

int sum(SWIMMINGPOOL* customers, int& customercount)
{
	int sum = 0;
	int timeIS;

	Prices(customers, customercount);

	for (int i = 0; i < customercount; i++)
	{
		timeIS = customers[i].time;
		sum = sum + (customers[i].prize * timeIS);
	}

	return sum;
}

void PriceMenu(SWIMMINGPOOL* customers, int& customercount)
{
	int Sum = 0;
	Sum = sum(customers, customercount);
	cout << " The prize for your time spent is: $" << Sum;
}




//presentation layerzz

void findCusotmersByDay(SWIMMINGPOOL* customers, int& customercount)
{
	string day;
	cout << "Enter day: ";
	cin >> day;
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

void findCusotmersByTime(SWIMMINGPOOL* customers, int& customercount)
{
	int time;
	cout << "Enter time: ";
	cin >> time;
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

void findCusotmersByAge(SWIMMINGPOOL* customers, int& customercount)
{
	int age;
	cout << "Enter age: ";
	cin >> age;
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

void deleteCustomerByID(SWIMMINGPOOL* customers, int& customercount)
{
	int id;
	cout << "Enter the id of the customer you want to delete: ";
	cin >> id;
	deleteCustomer(customers, customercount, id);
}

void findCustomerMenu(SWIMMINGPOOL* customers, int& customercount)
{
	int age, time, choose;
	char dayOfWeek[3];
	cout << endl << endl;
	cout << "Which option you want to use" << endl << endl;
	cout << "1. Find customer by the time" << endl;
	cout << "2. Find customer by the age" << endl;
	cout << "3. Find customer by the day" << endl << endl;
	cout << "Your choice: "; cin >> choose;


	switch (choose)
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

bool customersMenu(SWIMMINGPOOL* customers, int& customercount, int& maxId)
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
		break;
	case 2:
		showAllcustomers(customers, customercount);
		break;

	case 3:

		editCusotmer(customers, customercount, maxId);
		break;

	case 4:
		deleteCustomerByID(customers, customercount);
		break;

	case 5:
		findCustomerMenu(customers, customercount);
		break;
	case 6:

		PriceMenu(customers, customercount);
		break;

	case 7:
		cout << "Have a nice day!";
		return false;

		break;
	default:cout << "Incorrect input. Choose an avaliable option from the menu" << endl;

	}
	return true;
}

int main()
{
	Welcoming();
	int customercount = 0;
	int maxId = 0;
	bool menu = true;
	SWIMMINGPOOL customers[100];

	menu = customersMenu(customers, customercount, maxId);

	do {
		menu = customersMenu(customers, customercount, maxId);
	} while (menu);

}
