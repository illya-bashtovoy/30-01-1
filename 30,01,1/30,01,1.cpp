/*
Завдання 1.
  Дано два масиви : А[M] і B[N](M і N вводяться з клавіатури).
 Необхідно створити третій масив мінімально можливого розміру, у якому потрібно зібрати
елементи масиву A, які не включаються до масиву B, без повторень 
*/

#include <iostream>
#include <Windows.h>
#include <ctime>

using namespace std;

void inputArr(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 50;
    }
}


void prtArr(const int* arr, const int size) {
    for (int i = 0; i < size; i++) {
        cout << "\t arr [" << i << "] =" << " " << arr[i] << ";" << endl;
    }
}


void prt1Arr(int* arr, const int size, int* arr1, const int size1, int*& nArr, int& nSize) {
    int l = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size1; j++) {
            if (arr[i] == arr1[j]) {
                break;
            }
            else if (j == size1 - 1) {
                nArr[l] = arr[i];
                l++;
            }
        }
    }
    nSize = l;
}


int main() {
    srand(time(NULL));
    SetConsoleCP(1251); 
    SetConsoleOutputCP(1251);

    int size = 1;
    int size1 = 1;

    cout << " Введіть розмір size елементів першого масиву =" << endl;
    cin >> size;
    cout << " Введіть розмір size1 елементів другого масиву =" << endl;
    cin >> size1;

    int* arr = new int[size]; 
    int* arr1 = new int[size1]; 
    int nSize = size;
    int* nArr = new int[nSize]; 

    inputArr(arr, size);
    inputArr(arr1, size1);
    cout << "\n\tЕлементи першого масиву :" << endl;

    prtArr(arr, size);
    cout << "\n\tЕлементи другого масиву :" << endl;

    prtArr(arr1, size1);
    cout << "\n\tЕлементи третього масиву :" << endl;

    prt1Arr(arr, size, arr1, size1, nArr, nSize);
    prtArr(nArr, nSize);

    delete[]arr;
    delete[]arr1;
    delete[]nArr;
}