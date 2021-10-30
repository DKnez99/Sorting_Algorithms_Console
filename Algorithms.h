#pragma once
#include "HelperFunctions.h"

const char outputChar = char(254);

void userInput(std::string sort, int* n, int* speed);	
void initVector(std::vector<int>* v, int size);
void userInputPrint(std::string name, int n, int speed);		//also prints the name of the sorting algo
void arrayPrint(int number, int k);								//visual representation of an array
void elementsCheckedPrint(int vectorSize, int cnt);

void selectionPrint(std::vector<int> v, int min_id, int i, int j, int cnt, int speed, bool last);
void selectionSort();

void bubblePrint(std::vector<int> v, int i, int j, int cnt, int speed, bool same);
void bubblePrintDone(std::vector<int> v, int cnt, int speed);
void bubbleSort();

void insertionPrint(std::vector<int> v, int i, int j, int cnt, int speed, bool greater);
void insertionSort();

void printM(std::vector<int> v, int i11, int i12, int i21, int i22, int cnt, int speed, bool inserting);
void mergePrintDone(std::vector<int> v, int cnt, int speed);
void merge(std::vector<int>* v, int left, int mid, int right, int n, int* cnt, int speed);
void mergeSortAlg(std::vector<int>* v, int begin, int end, int n, int* cnt, int speed);
void mergeSort();


void quickPrint(std::vector<int>* v, std::vector<int>* sortedElems, int i, int j, int end, int cnt, int speed, bool swapJ, bool swapEnd);
void quickPrintDone(std::vector<int> v, int cnt, int speed);
int partition(std::vector<int>* v, std::vector<int>* sortedElems, int start, int end, int* cnt, int speed);
void quickSortAlg(std::vector<int>* v, std::vector<int>* sortedElems, int start, int end, int* cnt, int speed);
void quickSort();