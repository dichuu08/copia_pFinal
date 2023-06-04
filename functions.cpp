#include <iostream>
#include <stdio.h>
#include <string.h>
#include"customerF.cpp"
#include"carFunctions.cpp"

#define MAX 100

using namespace std;



int main()
{
    initialize();
    return 0;
}


void menu()
{
    carData car;
    int choice, pos;

    do
    {
        system("cls");
        cout << "*****CAR INVENTORY*****\n"
             << endl;
        cout << "1. Add car to inventory" << endl;
        cout << "2. See car inventory" << endl;
        cout << "3. Exit" << endl;

        cout << "\nEnter your choice: ";
        cin >> choice;
        cin.ignore();
        system("cls");

        switch (choice)
        {
        case 1:

            cars[pos].id = lastCar;
            cars[pos].id++;

            cout << "ID: " << cars[pos].id << endl;

            cout << "Kind: ";
            scanf("%[^\n]", car.kind);

            cout << "Brand: ";
            scanf("%[^\n]", car.brand);

            cout << "Model: ";
            scanf("%[^\n]", car.model);

            cout << "Color: ";
            scanf("%[^\n]", car.color);

            cout << "Transmission: ";
            scanf("%[^\n]", car.transmission);

            cout << "Year: ";
            scanf("%[^\n]", car.year);

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
    } while (choice != 3);
}

int mainMenu()
{
    int choice;

    cout << "___________________________________________________" << endl;
    cout << "\tCUSTOMER REGISTER SYSTEM" << endl;
    cout << "\t   Current records: " << lastRecord << endl;
    cout << "___________________________________________________\n"
         << endl;

    cout << "1. Car manage" << endl;
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
    int carPos = carExists(id);

    customerData customer;
    carData car;

    readCustomers();
    do
    {
        system("cls");

        choice = mainMenu();

        switch (choice)
        {
        case 1:

            menu();
            break;

        case 2:
            system("cls");

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

            /*system("cls");
            cout << "Customer added successfully!\n\n\n"
                << endl;*/

            cout << "\n\nEnter ID of the car bought: ";
            cin >> id;

            if (carPos != -1)
            {
                // El carro existe, asigna el carro al cliente
                customers[lastRecord-1].car = cars[carPos];
            }
            else
            {
                // El carro no existe, muestra un mensaje de error
                cout << "Invalid car ID. Car not found." << endl;
            }
            system("pause");
            break;

        case 3:
            system("cls");

            cout << "Enter ID to search: ";
            cin >> id;

            system("cls");

            pos = customerExists(id);
            if (pos == -1)
            {
                cout << "Customer not found" << endl;
            }
            else
            {
                searchCustomer(pos);
            }
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