#include<iostream>
#include<string.h>
#define MAX 100

using namespace std;

typedef struct
{
    int id;
    char name[20], lastName[20], address[50], email[20], cellphoneNumber[15], kind[10];
} customerData;

customerData customers[MAX];
int lastRecord = 0;
//int lastCustomer = 0;
//int lastCar = 0;

// Create
void addCustomer(customerData customer);

// Read
void searchCustomer(int pos);
int customerExists(int id);

void showCustomers();

void initCustomer(int pos);
customerData getCustomer(int pos);

// Edit
void editCustomer(customerData customer, int pos);

// Delete
void deleteCustomer(int pos);

// Menu
int mainMenu();
void initialize();

// Files
FILE *customerRegister;
void saveCustomers();
void readCustomers();
int getLastRecord(FILE *file);

void addCustomer(customerData customer)
{
    customer.id = lastRecord + 1;
    customers[lastRecord] = customer;
    lastRecord++;
}

void searchCustomer(int pos)
{
    cout << "_______________________________________________________________________________________________________________" << endl;
    cout << "\t\t\t\tCUSTOMER INFO" << endl;
    cout << "_______________________________________________________________________________________________________________" << endl;
    cout << "|       ID       |      Name      |      Last name    |              Address          |           Email          |      Cellphone #      |" << endl;
    cout << "_________________________________________________________________________________________________________________" << endl;
    cout << "|        " << customers[pos].id << "       |      " << customers[pos].name << "   |        " << customers[pos].lastName << "|" << customers[pos].address << "|" << customers[pos].email << "|" << customers[pos].cellphoneNumber << "|" << endl;

    cout << "_______________________________________________________________________________________________________________" << endl;
    cout << "\t\t\t\tCAR INFO" << endl;
    cout << "_______________________________________________________________________________________________________________" << endl;
    cout << "|       Kind       |" << endl;
    cout<<customers[pos].kind<<endl;
}

customerData getCustomer(int pos)
{
    return customers[pos];
}

int customerExists(int id)
{
    int pos = -1;

    for (int i = 0; i < lastRecord; i++)
    {
        if ((id == customers[i].id))
        {
            pos = i;
            break;
        }
    }
    return pos;
}


void showCustomers()
{
    if (lastRecord == 0)
    {
        cout << "No records available" << endl;
        return;
    }

    for (int i = 0; i < lastRecord; i++)
    {
        searchCustomer(i);
    }
}

void editCustomer(customerData customer, int pos)
{
    customers[pos] = customer;
}

void deleteCustomer(int pos)
{
    if (pos == lastRecord || pos < 0)
    {
        cout << "No records available" << endl;
        return;
    }

    for (int i = pos; i < lastRecord; i++)
    {
        customers[i] = customers[i + 1];
    }

    lastRecord--;
    initCustomer(lastRecord);
}

void initCustomer(int pos)
{
    customers[pos].id = 0;
    strcpy(customers[pos].name, "");
    strcpy(customers[pos].lastName, "");
    strcpy(customers[pos].address, "");
    strcpy(customers[pos].email, "");
    strcpy(customers[pos].cellphoneNumber, "");
    strcpy(customers[pos].kind, "");
}