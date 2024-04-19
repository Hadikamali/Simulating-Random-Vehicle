#include <iostream>
#include <ctime>
#include <cstdlib>
#include <windows.h>

using namespace std;

#define satrs 20
#define sotons 20

void ClearScreen() {
    system("cls");
}

void p_city(char city[satrs][sotons], int numtaghs) {
    for (int i = 1; i <= satrs; i++) {
        for (int j = 1; j <= sotons; j++) {
            city[i][j] = '-';
        }
    }
    srand(time(NULL));
    for (int i = 0; i < numtaghs; i++) {
        int satr = rand() % satrs + 1;
        int soton = rand() % sotons + 1;
        city[satr][soton] = '#';
    }
}

bool validmove(char city[satrs][sotons], int satr, int soton, int direction) {
    if (satr < 1 || satr > satrs || soton < 1 || soton > sotons) {
        return false;
    }
    if (city[satr][soton] == '#') {
        return false;
    }
    if (direction == 0) {  // left
        if (satr % 2 == 0) {
            soton--;
        }
        else {
            soton++;
        }
    }
    else if (direction == 1) {   // right
        if (satr % 2 != 0) {
            soton++;
        }
        else {
            soton--;
        }
    }
    else if (direction == 2) {  // up
        if (soton % 2 != 0) {
            satr--;
        }
        else {
            satr++;
        }
    }
    else {        // down
        if (soton % 2 == 0) {
            satr++;
        }
        else {
            satr--;
        }
    }
    if (satr < 1 || satr > satrs || soton < 1 || soton > sotons) {
        return false;
    }
    if (city[satr][soton] == '#') {
        return false;
    }
    return true;
}

void movecar(char city[satrs][sotons], int& satr, int& soton) {
    int direction = rand() % 4;
    while (!validmove(city, satr, soton, direction)) {
        direction = rand() % 4;
    }
    city[satr][soton] = '-';
    if (direction == 0) {  // left
        if (satr % 2 == 0) {
            soton--;
        }
        else {
            soton++;
        }
    }
    else if (direction == 1) {   // right
        if (satr % 2 != 0) {
            soton++;
        }
        else {
            soton--;
        }
    }
    else if (direction == 2) {  // up
        if (soton % 2 != 0) {
            satr--;
        }
        else {
            satr++;
        }
    }
    else {        // down
        if (soton % 2 == 0) {
            satr++;
        }
	        else {
            satr--;
        }
    }
    city[satr][soton] = '*';
}

void printcity(char city[satrs][sotons]) {
    for (int i = 1; i <= satrs; i++) {
        for (int j = 1; j <= sotons; j++) {
            if (city[i][j] == '#' || city[i][j] == '-'|| city[i][j] == '*') {
                cout << city[i][j] << " ";
            } else {
                cout << "- ";
            }
        }
        cout << endl;
    }
}


int main() {
    system("color 6");
    char city[satrs][sotons];
    int numtaghs;
    int numcars;
    int numiters;

    cout << "Enter the number of taghato: ";
    cin >> numtaghs;
    p_city(city, numtaghs);

    cout << "Enter the number of cars: ";
    cin >> numcars;

    cout << "Enter the number of iterations: ";
    cin >> numiters;
    ClearScreen();
    srand(time(NULL));

    int** car_negah = new int* [numcars];
    for (int i = 0; i < numcars; i++) {
        car_negah[i] = new int[2];
        int satr = rand() % satrs + 1;
        int soton = rand() % sotons + 1;
        while (city[satr][soton] == '#') {
            satr = rand() % satrs + 1;
            soton = rand() % sotons + 1;
        }
        city[satr][soton] = '*';
        car_negah[i][0] = satr;
        car_negah[i][1] = soton;
    }

    for (int i = 0; i < numiters; i++) {
        for (int j = 0; j < numcars; j++) {
            int satr = car_negah[j][0];
            int soton = car_negah[j][1];
            movecar(city, satr, soton);
            car_negah[j][0] = satr;
            car_negah[j][1] = soton;
        }
        printcity(city);
        Sleep(1000);
        cout << endl;
        ClearScreen();
    }

    for (int i = 0; i < numcars; i++) {
        delete[] car_negah[i];
    }
    delete[] car_negah;

    return 0;
}
