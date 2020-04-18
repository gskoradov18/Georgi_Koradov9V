#include <iostream>
#include <string.h>
using namespace std;

struct SWIMMINGPOOL
{
	int age=0;
	string FirstName=" ";
	string LastName = " ";
	int time=0;
	int id=0;
	string dayofweek=" ";
	int prize = 5;

};


void insertCustomer(SWIMMINGPOOL* customers, int& customercount)
{
	cout << "Enter First name: ";
	cin >> customers[customercount].FirstName;
	cout << "Enter Last name: ";
	cin >> customers[customercount].LastName;
	cout << "Enter age: "; cout;
	cin >> customers[customercount].age;
	cout << "Enter time: "; cout;
	cin >> customers[customercount].time;
	cout << "Enter id: "; cout;
	cin >> customers[customercount].id;
	cout << "Enter day: "; cout;
	cin >> customers[customercount].dayofweek;
	if (customers[customercount].dayofweek == "Sat" or customers[customercount].dayofweek == "Sun")
	{
		cout << "The pool is closed on Saturday and Sunday. ";
	}
	customercount++;
}

void showCustomer(SWIMMINGPOOL customers)
{
	cout << "Customer's Full name: ";
	cout << customers.FirstName <<" "<<customers.LastName<< endl;
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
		cout << "There are no customers enterred "; cout << "Please insert customer's info"; cout << endl << endl;

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

void editCusotmer(SWIMMINGPOOL* customers, int& customercount)
{
	int id;
	int choose, newage, newtime;
	char newday;
	cout << "Enter id: ";
	cin >> id;
	cout << "1. Change age" << endl;
	cout << "2. Cahnge time" << endl;

	cout << "Choose an option: ";
	cin >> choose;



	switch (choose)
	{
	case 1:
		cout << "Enter the new age: ";
		cin >> newage;
		customers[id].age = newage;
		break;
	case 2:
		cout << "Enter the new time: ";
		cin >> newtime;
		customers[id].age = newtime;

		break;


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

void deleteCustomer(SWIMMINGPOOL* customers, int& customercount, int id)
{
	int index = getCustomerIndexById(customers, customercount, id);
	for (int i = 0; i < customercount - 1; i++)
	{
		customers[i] = customers[i + 1];
	}
	customercount--;
}

int sum(SWIMMINGPOOL* customers, int& customercount)
{
	int sum = 0;
	int timeIS;


	for (int i = 0; i < customercount; i++)
	{
		timeIS = customers[i].time;
		sum = sum + (customers[i].prize * timeIS);
	}

	return sum;
}

void sumMenu(SWIMMINGPOOL* customers, int& customercount)
{
	int Sum = 0;
	Sum = sum(customers, customercount);
	cout <<" The prize for your time spent is: $"<< Sum;
}

/*
void prizes(SWIMMINGPOOL* customers, int& customercount)
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
*/



//presentation layer

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
	}
}

void deleteID(SWIMMINGPOOL* customers, int& customercount)
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
	cout << "1. Find customer by the id" << endl;
	cout << "2. Find customer by the age" << endl<<endl;
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

bool customersMenu(SWIMMINGPOOL* customers, int& customercount)
{
	cout << endl << endl;
	int option;
	cout << "1. Insert customer" << endl;
	cout << "2. Show all customers" << endl;
	cout << "3. Edit customer" << endl;
	cout << "4. Delete customer" << endl;
	cout << "5. Find customers by creteria" << endl;
	cout << "6. Prize" << endl;
	cout << "7. Exit" << endl<<endl;
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

		editCusotmer(customers, customercount);
		break;

	case 4:
		deleteID(customers, customercount);
		break;

	case 5:
		findCustomerMenu(customers, customercount);
		break;
	case 6:

		sumMenu(customers, customercount);
		break;

	case 7:
		cout << "Have a nice day!";
		return false;

		break;

	}
	return true;
}

int main()
{
	cout << "Hello user!";
	int customercount = 0;
	bool menu = true;
	SWIMMINGPOOL customers[100];
	menu = customersMenu(customers, customercount);
	do {
		menu = customersMenu(customers, customercount);
	} while (menu);

}
