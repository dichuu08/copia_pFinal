#include<iostream>
#include<string.h>

#define MAX 100
using namespace std;

typedef struct
{
    int id;
    char kind[10], brand[10], model[15], color[10], transmission[1], year[4];
    double price;
} carData;

carData cars[MAX];
int lastCar = 0;
void addCar(carData car);

int carExists(int id);
void showCars();
void initCar();

void addCar(carData car)
{
    car.id = lastCar;
    cars[lastCar] = car;
    lastCar++;
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
    cout << "_____________________________________________________________________________________________________________________________________" << endl;
    cout << "\t\tCAR INFO" << endl;
    cout << "_____________________________________________________________________________________________________________________________________" << endl;
    cout << "|       ID       |      Kind      |      Brand    |           Model          |           Color          |      Transmission      |      Year      |       Price     |" << endl;
    cout << "|" << cars[pos].id << "|" << cars[pos].kind << "|" << cars[pos].brand << "|" << cars[pos].model << "|" << cars[pos].color << "|" << cars[pos].transmission << "|" << cars[pos].year << "|" << cars[pos].price << "|\n\n\n" << endl;
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

void initCar(int pos)
{
    strcpy(cars[pos].kind, "");
    strcpy(cars[pos].brand, "");
    strcpy(cars[pos].model, "");
    strcpy(cars[pos].color, "");
    strcpy(cars[pos].transmission, "");
    strcpy(cars[pos].year, "");
    cars[pos].price = 0;
}