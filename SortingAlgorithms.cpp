#include "Menu.h"
#include "Algorithms.h"

int main()
{
    while (true) {
        system("cls");
        switch (menu()) {
        case 0: {
            selectionSort();
            break;
        }
        case 1: {
            bubbleSort();
            break;
        }
        case 2: {
            insertionSort();
            break;
        }
        case 3: {
            mergeSort();
            break;
        }
        case 4: {
            quickSort();
            break;
        }
        }
        char key = _getch();
    }
}