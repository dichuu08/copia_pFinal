#include <iostream>
#include <stdio.h>
#include <string.h>

// #include "structs.h"

#define MAX 100

using namespace std;

typedef struct
{
    int id;
    char kind[10], brand[10], model[15], color[10], transmission[1], year[4];
    double price;
} carData;

typedef struct
{
    int id;
    char name[20], lastName[20], address[50], email[20], cellphoneNumber[15];
    carData car;
} customerData;

customerData customers[MAX];
carData cars[MAX];
int lastRecord = 0;
int lastCar = 0;

// Create
void addCustomer(customerData customer);

void addCar(carData car);

// Read
void searchCustomer(int pos);
int customerExists(int id);
int carExists(int id);
void showCustomers();
void showCars();
void initCustomer(int pos);
// customerData getCustomer(int pos);

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

int main()
{
    initialize();
    return 0;
}

void addCustomer(customerData customer)
{
    customers[lastRecord] = customer;
    lastRecord++;
}

void addCar(carData car)
{
    cars[lastCar] = car;
    lastCar++;
}

void searchCustomer(int pos)
{
    cout << "_______________________________________________________________________________________________________________" << endl;
    cout << "\t\t\t\tCUSTOMER INFO" << endl;
    cout << "_______________________________________________________________________________________________________________" << endl;
    cout << "|       ID       |      Name      |      Last name    |              Address          |           Email          |      Cellphone #      |" << endl;
    cout << "|        " << customers[pos].id-1 << "       |      " << customers[pos].name << "   |        " << customers[pos].lastName << "|" << customers[pos].address << "|" << customers[pos].email << "|" << customers[pos].cellphoneNumber << "|" << endl;

    cout << "_______________________________________________________________________________________________________________" << endl;
    cout << "\t\t\t\tCAR INFO" << endl;
    cout << "_______________________________________________________________________________________________________________" << endl;
    cout << "|       Kind       |      Brand      |      Model    |           Color          |           Transmission          |      Year      |       Price     |" << endl;
    cout << "|" << cars[pos].kind << "|" << cars[pos].brand << "|" << cars[pos].model << "|" << cars[pos].color << "|" << cars[pos].transmission << "|" << cars[pos].year << "|" << cars[pos].price << "|" << endl;
}

customerData getCustomer(int pos)
{
    return customers[pos];
}

int customerExists(int id)
{
    int pos = 0;

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

int carExists(int id)
{
    int pos = -1;

    for (int i = 0; i < lastCar; i++)
    {
        if ((id == cars[i].id))
        {
            pos = i;
            break;
        }
    }
    return pos;
}

void searchCar(int pos)
{
    cout << "_______________________________________________________________________________________________________________" << endl;
    cout << "\t\tCAR INFO" << endl;
    cout << "_______________________________________________________________________________________________________________" << endl;
    cout << "|       ID       |      Kind      |      Brand    |           Model          |           Color          |      Transmission      |      Year      |       Price     |" << endl;
    cout << "|" << cars[pos].id << "|" << cars[pos].kind << "|" << cars[pos].brand << "|" << cars[pos].model << "|" << cars[pos].color << "|" << cars[pos].transmission << "|" << cars[pos].year << "|" << cars[pos].price << "|" << endl;
}

void showCars()
{
    if (lastCar == 0)
    {
        cout << "No records available" << endl;
        return;
    }
    for (int i = 0; i < lastCar; i++)
    {
        searchCar(i);
    }
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

    strcpy(cars[pos].kind, "");
    strcpy(cars[pos].brand, "");
    strcpy(cars[pos].model, "");
    strcpy(cars[pos].color, "");
    strcpy(cars[pos].transmission, "");
    strcpy(cars[pos].year, "");
    cars[pos].price = 0;
}

int menu()
{
    carData car;
    int choice, pos;

    do
    {
    system("cls");
    cout<<"*****CAR INVENTORY*****\n"<<endl;
    cout << "1. Add car to inventory" << endl;
    cout << "2. See car inventory" << endl;
    cout<<"3. Exit"<<endl;

    cout << "\nEnter your choice: ";
    cin >> choice;
    cin.ignore();

    switch (choice)
    {
    case 1:
        cout << "ID: " << cars[pos].id << endl;     

        cout << "Kind: ";
        cin.getline(car.kind, 10, '\n');

        cout << "Brand: ";
        cin.getline(car.brand, 10, '\n');

        cout << "Model: ";
        cin.getline(car.model, 15, '\n');

        cout << "Color: ";
        cin.getline(car.color, 10, '\n');

        fflush(stdin);
        
        cout << "Transmission: ";
        cin.getline(car.transmission, 1, '\n');
        cin.ignore();

        cout << "Year: ";
        cin.getline(car.year, 4, '\n');
        cin.ignore();

        cout << "Price: ";
        cin >> car.price;
    
        addCar(car);
        system("pause");
        break;

    case 2:
        showCars();
        system("pause");
        break;
    
     case 3: 
        system("pause");
        break;

    default:
        cout << "Unavailable option" << endl;
        break;
    }
    return 0;
    } while(choice != 3);
}

int mainMenu()
{
    int choice;

    cout << "___________________________________________________" << endl;
    cout << "\tCUSTOMER REGISTER SYSTEM" << endl;
    cout << "\t   Current records: " << lastRecord << endl;
    cout << "___________________________________________________\n"
         << endl;

    cout << "1. Car manage" << endl; // "0. Add car to inventory
    cout << "2. Add customer" << endl;
    cout << "3. Search customer" << endl;
    cout << "4. Show customers" << endl;
    cout << "5. Edit customer" << endl;
    cout << "6. Delete customer" << endl;
    cout << "7. Generate bill" << endl;
    cout << "8. Exit\n"
         << endl;

    cout << "Enter your choice: ";
    cin >> choice;
    cin.ignore();
    return choice;
}

void initialize()
{
    int pos, choice, id;
    char ans[1];
    customerData customer;
    carData car;

    readCustomers();
    do
    {
        system("cls");
        
        customers[pos].id = lastRecord;
        customers[pos].id++;

        cars[pos].id = lastCar;
        cars[pos].id++;

        choice = mainMenu();

        switch (choice)
        {
        case 1:
            menu();
            break;

        case 2:
            cout << "ID: " << customers[pos].id << "\n";

            cout << "Name: ";
            cin.getline(customer.name, 20, '\n');
            
            
            cout << "Last name: ";
            cin.getline(customer.lastName, 20, '\n');
            
            cout << "Address: ";
            cin.getline(customer.address, 50, '\n');
            
            cout << "Email: ";
            cin.getline(customer.email, 20, '\n');
            
            cout << "Cellphone number: ";
            cin.getline(customer.cellphoneNumber, 15, '\n');
            

            addCustomer(customer);
            break;

        case 3:
            cout << "Enter ID to search: ";
            cin.ignore();
            cin >> id;
            pos = customerExists(id);
            searchCustomer(pos);
            system("pause");
            break;

        case 4:
            showCustomers();
            system("pause");
            break;

        case 5:
            cout << "Enter ID to edit: ";
            cin.ignore();
            cin >> id;
            pos = customerExists(id);
            searchCustomer(pos);
            cout << "\n\n";
            cout << "NEW VALUES: ";
            cout << "Name: ";
            cin.getline(customer.name, 20, '\n');
            cout << "Last name: ";
            fflush(stdin);
            cin.getline(customer.lastName, 20, '\n');
            cout << "Address: ";
            cin.getline(customer.address, 50, '\n');
            cout << "Email: ";
            cin.getline(customer.email, 20, '\n');
            cout << "Cellphone number: ";
            cin.getline(customer.cellphoneNumber, 15, '\n');

            editCustomer(customer, pos);
            break;

        case 6:
            system("cls");
            if (lastRecord == 0)
            {
                cout << "No customers to delete\n"
                     << endl;
            }
          
            cout << "Enter ID to delete: ";
            cin >> id;
            pos = customerExists(id);
            searchCustomer(pos);
            cout << "\n\n";
            cout << "Are you sure you want to delete customer '" << customers[pos].name << " " << customers[pos].lastName << "'? (y/n): ";
            cin.getline(ans, 1, '\n');

            if (strcmp(ans, "y") == 0 || strcmp(ans, "Y") == 0)
            {
                deleteCustomer(pos);
                cout << "Customer deleted succesfully!\n"
                     << endl;
            }
            else if (strcmp(ans, "n") == 0 || strcmp(ans, "N") == 0)
            {
                cout << "Action canceled succesfully!\n"
                     << endl;
            }
            else
            {
                cout << "Option unavailable, please try again\n"
                     << endl;
            }
            system("pause");
            break;

        case 7:
            break;

        case 8:
            system("pause");
            break;

        default:
            cout << "Unavailable option, please try again\n"
                 << endl;
            system("pause");
            break;
        }
    } while (choice != 7);
    saveCustomers();
}

void saveCustomers()
{
    customerRegister = fopen("records.txt", "wb");
    fwrite(customers, sizeof(customerData), lastRecord, customerRegister);
    fclose(customerRegister);
}

void readCustomers()
{
    customerRegister = fopen("records.txt", "rb");
    if (customerRegister == NULL)
    {
        return;
    }
    lastRecord = getLastRecord(customerRegister);
    fread(customers, sizeof(customerData), MAX, customerRegister);

    fclose(customerRegister);
}

int getLastRecord(FILE *file)
{
    int tam_archivo, num_clientes;
    // Obtener el tamaño del archivo
    fseek(file, 0, SEEK_END);
    tam_archivo = ftell(file);
    rewind(file);

    // Calcular el número de alumnos
    num_clientes = tam_archivo / sizeof(customerData);
    return num_clientes;
}