#include <iostream>
#include <string.h>
using namespace std;



struct SWIMMINGPOOL
{
	int age;
	float time;
	int id;
	int prize = 20;
	char dayofweek[3];
	


};




void insertCustomer(SWIMMINGPOOL* customers, int& customercount)
{
	cout << "Enter age: "; cout;
	cin >> customers[customercount].age;
	cout << "Enter time: "; cout;
	cin >> customers[customercount].time;
	cout << "Enter id: "; cout;
	cin >> customers[customercount].id;
	cout << "Enter day: "; cout;
	cin >> customers[customercount].dayofweek;
	customercount++;
}

int prizes(SWIMMINGPOOL* customers, int& customercount)
{
	if (customers[customercount].age >= 60 or customers[customercount].age <= 10)
	{
		customers[customercount].prize == 10;
	}

	return customers[customercount].prize;

}

void showCustomer(SWIMMINGPOOL customers)
{

	cout << "\nCustomer age: ";
	cout << customers.age << endl;
	cout << "Customer time: ";
	cout << customers.time << endl;
	cout << "Customer id: ";
	cout << customers.id << endl;
	cout << "Day of week: ";
	cout << customers.dayofweek << endl;
	cout << "Prize: ";

	cout << customers.prize << endl;
	cout << endl;

}

void showAllcustomers(SWIMMINGPOOL* customers, int& customercount)
{
	if (customercount == 0)
	{
		cout << "There are no customers enterred "; cout << endl << endl;

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
void findCusotmersByAge(SWIMMINGPOOL* customers, int& customercount)
{
	int age;
	cout << "Choose the age you want to see the customers: ";
	cin >> age;
	for (int i = 0; i < customercount; i++)
	{
		if (customers[i].age = age)
		{
			showCustomer(customers[i]);
		}
	}
}
void findCusotmersByDay(SWIMMINGPOOL* customers, int& customercount)
{
	char dayOfWeek[3];
	cout << "Choose the day you want to see the customers: ";
	cin >> dayOfWeek;
	for (int i = 0; i < customercount; i++)
	{
		if (customers[i].dayofweek = dayOfWeek)
		{
			showCustomer(customers[i]);
		}
	}
}



void findCusotmersByTime(SWIMMINGPOOL* customers, int& customercount)
{
	int time;
	cout << "Choose the time you want to see the customers: ";
	cin >> time;
	for (int i = 0; i < customercount; i++)
	{
		if (customers[i].time = time)
		{
			showCustomer(customers[i]);
		}
	}
}

void findCustomerMenu(SWIMMINGPOOL* customers, int& customercount)
{
	int age, time, choose;
	char dayOfWeek[3];
	cout << "Which option you want to use";
	cin >> choose;
	cout << "1. Find customer by the time";
	cout << "2. Find customer by the age";
	cout << "3. Find customer by day of the week";
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
		break;
	}

	
}

int getCustomerIndexById(SWIMMINGPOOL* customers, int& customercount, int id)
{
	for (int i = 0; i < customercount; i++)
	{
		if (customers[i].id == id) // check 
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

void deleteID(SWIMMINGPOOL* customers, int& customercount)
{
	int id;
	cout << "Enter the id on which position you want to delete a customer: ";
	cin >> id;
	deleteCustomer(customers, customercount, id);
}


SWIMMINGPOOL getCustomer(SWIMMINGPOOL* customers, int& customercount, int id)
{
	int index = getCustomerIndexById(customers, customercount, id);
	return customers[index];
}
void updateCustomer(SWIMMINGPOOL* customers, int& customercount, int index, SWIMMINGPOOL newcustomer)
{
	customers[index] = newcustomer;
}

void editCusotmer(SWIMMINGPOOL* customers, int& customercount)
{
	int id;
	int choose;
	cout << "Enter id: ";
	cin >> id;
	cout << "1. Change age: " << endl;
	cout << "2. Cahnge time" << endl;
	cout << "3. Change id" << endl;
	cout << "4. Change day of week" << endl;
	cout << "Choose an option: ";
	cin >> choose;
	SWIMMINGPOOL customer = getCustomer(customers, customercount, id);


	switch (choose)
	{
	case 1:
		cout << "Enter the new age:";
		cin >> customer.age;
		updateCustomer(customers, customercount, id, customer);
		break;
	case 2:
		cout << "Enter the new time:";
		cin >> customer.time;
		updateCustomer(customers, customercount, id, customer);
		break;
	case 3:
		cout << "Enter the new id:";
		cin >> customer.id;
		updateCustomer(customers, customercount, id, customer);
		break;
	case 4:
		cout << "Enter the new day of the week:";
		cin >> customer.dayofweek;
		updateCustomer(customers, customercount, id, customer);
		break;



	}

}





bool customersMenu(SWIMMINGPOOL* customers, int& customercount)
{
	cout << endl << endl;
	int option;
	cout << "1. Insert customer: " << endl;
	cout << "2. Show all customers: " << endl;
	cout << "3. Edit customer" << endl;
	cout << "4. Delete customer" << endl;
	cout << "5. Find customers by creteria" << endl;
	cout << "6. Exit " << endl;
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
