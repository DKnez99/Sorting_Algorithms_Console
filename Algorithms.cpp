#include "Algorithms.h"

void userInput(std::string sort, int* n, int* speed) {
	while (*n < 3 || *n > 20) {
		system("cls");
		color(7);		//white
		gotoXY(1, 1);
		std::cout << sort;
		gotoXY(1, 3);
		std::cout << "Number of elements in an array [3-20]: ";
		std::cin >> *n;
	}

	while (*speed < 1 || *speed>5) {
		system("cls");
		color(7);		//white
		gotoXY(1, 1);
		std::cout << sort;
		gotoXY(1, 3);
		std::cout << "Number of elements in an array [3-20]: "<<*n;
		gotoXY(1, 4);
		std::cout << "Sorting speed [1-5]: ";
		std::cin >> *speed;
	}
}

void initVector(std::vector<int> *v, int size) {
	for (int i = 0; i < size; i++) {		//initialize vector with random numbers from 0 to 50
		int elem = rand() % 51;
		v->push_back(elem);
		gotoXY(1, 5);
		color(7);	//white
		std::cout << "Unsorted   ";
		color(10);	//green
		std::cout << "Sorted   ";

		color(7);	//white
		gotoXY(1, i + 7);
		for (int j = 0; j < elem; j++) {
			std::cout << outputChar;
		}
		gotoXY(60, i + 7);
		std::cout << elem;
	}
}

void userInputPrint(std::string name, int n, int speed) {
	std::this_thread::sleep_for(std::chrono::milliseconds(0 + (5 - speed) * 50));
	system("cls");
	gotoXY(1, 1);
	color(7);		//white
	std::cout << name;
	gotoXY(1, 3);
	std::cout << "Number of elements in an array [3-20]: " << n;
	gotoXY(1, 4);
	std::cout << "Sorting speed [1-5]: " << speed;
	gotoXY(1, 5);
	color(7);	//white
	std::cout << "Unsorted   ";
	color(10);	//green
	std::cout << "Sorted   ";
}

void arrayPrint(int number, int k) {
	gotoXY(1, k + 7);
	for (int m = 0; m < number; m++) {
		std::cout << outputChar;
	}
	gotoXY(60, k + 7);
	std::cout << number;
}

void elementsCheckedPrint(int vectorSize, int cnt) {
	gotoXY(1, vectorSize + 8);
	color(7);		//white
	std::cout << "Elements checked: " << cnt;
}

//===========SELECTION SORT===========

void selectionPrint(std::vector<int> v, int min_id, int i, int j, int cnt, int speed, bool last) {
	userInputPrint("SELECTION SORT", v.size(), speed);
	color(14);	//yellow
	std::cout << "Current element   ";
	color(13);	//purple
	std::cout << "Smallest number in this iteration";
	for (int k = 0; k < v.size(); k++) {
		color(7);					//white
		if (k < i)					//already sorted
			color(10);				//green
		if (k == min_id)			//smallest number in current iteration
			color(13);				//purple
		if (k == j)					//current element
			color(14);				//yellow
		if (k == i && last == true)	//if at the end of an iteration and you need to swap with min id
			color(13);				//purple
		arrayPrint(v[k], k);
	}
	elementsCheckedPrint(v.size(), cnt);
}

void selectionSort() {
	int n = 0;
	int speed = 0;

	userInput("SELECTION SORT", &n, &speed);

	std::vector<int> vect;

	initVector(&vect, n);

	gotoXY(1, n + 8);
	std::cout << "Press any key to start...";
	char key = _getch();

	int cnt = 0;
	int min_id;

	for (int i = 0; i < n - 1; i++) {
		min_id = i;
		cnt++;
		selectionPrint(vect, min_id, i, -1, cnt, speed, false);
		for (int j = i + 1; j < n; j++) {
			cnt++;
			selectionPrint(vect, min_id, i, j, cnt, speed, false);
			if (vect[j] < vect[min_id]) {
				min_id = j;
				
			}			
		}
		selectionPrint(vect, min_id, i, -1, cnt, speed, true);
		swap(&vect[min_id], &vect[i]);
	}
	selectionPrint(vect, -1, vect.size(), -1, cnt, speed, false);
	gotoXY(1, n + 10);
	std::cout << "Press any key to go back to menu...";
}

//===========BUBBLE===========

void bubbleSort() {
	int n = 0;
	int speed = 0;

	userInput("BUBBLE SORT", &n, &speed);

	std::vector<int> vect;

	initVector(&vect, n);

	gotoXY(1, n + 8);
	std::cout << "Press any key to start...";
	char key = _getch();

	int cnt = 0;

	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if(j==0)
				cnt+=2;
			else {
				cnt++;
			}
			bubblePrint(vect, i, j, cnt, speed, false);
			if (vect[j] > vect[j + 1]) {
				bubblePrint(vect, i, j, cnt, speed, true);
				swap(&vect[j], &vect[j + 1]);
			}
		}
	}
	bubblePrintDone(vect, cnt, speed);
	gotoXY(1, n + 10);
	std::cout << "Press any key to go back to menu...";
}

void bubblePrint(std::vector<int> v, int i, int j, int cnt, int speed, bool same) {	//why doesnt this work on fully sorted vector (i=vect.size())? it prints out white instead of green
	userInputPrint("BUBBLE SORT", v.size(), speed);
	color(14);
	std::cout << "Comparing elements   ";
	color(13);
	std::cout << "Swapping elements   ";

	for (int k = 0; k < v.size(); k++) {
		color(7);						//white
		if (k > v.size() - i - 1)		//already sorted
			color(10);					//green
		if (k == j || k == j + 1) {		//current and next element
			if (same == true)
				color(13);				//purple
			else {
				color(14);				//yellow
			}
		}
		arrayPrint(v[k], k);
	}
	elementsCheckedPrint(v.size(), cnt);
}

void bubblePrintDone(std::vector<int> v, int cnt, int speed) {
	userInputPrint("BUBBLE SORT", v.size(), speed);
	color(14);
	std::cout << "Comparing elements   ";
	color(13);
	std::cout << "Swapping elements   ";

	for (int k = 0; k < v.size(); k++) {
		color(10);						//green
		arrayPrint(v[k], k);
	}
	elementsCheckedPrint(v.size(), cnt);
}

//===========INSERTION===========

void insertionSort() {
	int n = 0;
	int speed = 0;

	userInput("INSERTION SORT", &n, &speed);

	std::vector<int> vect;

	initVector(&vect, n);

	gotoXY(1, n + 8);
	std::cout << "Press any key to start...";
	char key = _getch();

	int cnt = 0;

	int val, j;
	for (int i = 1; i < n; i++)
	{
		val = vect[i];
		j = i - 1;
		cnt = cnt + 2;
		insertionPrint(vect, i, j, cnt, speed, false);
		while (j >= 0 && vect[j] > val)
		{
			vect[j + 1] = vect[j];
			vect[j] = val;					//had to put this here instead of commented code after while because of the print function (so it actually swaps place every single time)
			j--;
			cnt++;
			insertionPrint(vect, i, j, cnt, speed, true);
		}
		//vect[j + 1] = val;
	}

	insertionPrint(vect, vect.size()-1, -2, cnt, speed, false);
	gotoXY(1, n + 10);
	std::cout << "Press any key to go back to menu...";
}

void insertionPrint(std::vector<int> v, int i, int j, int cnt, int speed, bool greater) {
	userInputPrint("INSERTION SORT", v.size(), speed);
	color(11);
	std::cout << "Comparing with   ";
	color(14);
	std::cout << "Already swapped with   ";
	color(13);
	std::cout << "Current element";
	for (int k = 0; k < v.size(); k++) {
		color(7);					//white
		if (k > j+1 && k <= i && i!=v.size()-1 && greater==true)	//elements greater than val that are moved forward
			color(14);				//yellow
		if (k == j+1)				//val
			color(13);				//purple
		if (k == j)					//element which we compare val to
			color(11);				//cyan
		if (i == v.size() - 1 && (k > j+1))			//already sorted
			color(10);				//green
		arrayPrint(v[k], k);
	}
	elementsCheckedPrint(v.size(), cnt);
}

//===========MERGE===========				//find better solution

void merge(std::vector<int> *v, int left, int mid, int right, int n, int* cnt, int speed) {
	int subVectOne = mid - left + 1;
	int subVectTwo = right - mid;

	//temp vectors
	std::vector<int> leftVect;
	std::vector<int> rightVect;

	for (int i = 0; i < subVectOne; i++) {
		leftVect.push_back((*v)[left + i]);
		(*cnt)++;
		printM(*v, left + i, -1, -1, -1, *cnt, speed, false);
	}
	for (int j = 0; j < subVectTwo; j++) {
		if (v->size() != mid + 1 + j) {					//doesnt work without this
			rightVect.push_back((*v)[mid + 1 + j]);
			(*cnt)++;
			printM(*v, -1, mid + 1 + j, -1, -1, *cnt, speed, false);
		}
		else {											//and this
			subVectTwo--;
		}
	}

	int indexOne = 0;
	int indexTwo = 0;
	int indexMerged = left;

	//merge temp vectors back into sorted vector[left..right]
	while (indexOne < subVectOne && indexTwo < subVectTwo) {
		printM(*v, -1, -1, left+indexOne, mid + 1 + indexTwo, *cnt, speed, false);
		if (leftVect[indexOne] <= rightVect[indexTwo]) {
			printM(*v, -1, -1, left + indexOne, -1, *cnt, speed, true);
			(*v)[indexMerged++] = leftVect[indexOne++];
			(*cnt)++;
			//print
		}
		else {
			printM(*v, -1, -1, -1, mid + 1 + indexTwo, *cnt, speed, true);
			(*v)[indexMerged++] = rightVect[indexTwo++];
			(*cnt)++;
			//print
		}
	}

	//if there are any remaining left elements copy them in merged
	while (indexOne < subVectOne) {
		printM(*v, -1, -1, left + indexOne, -1, *cnt, speed, true);
		(*v)[indexMerged++] = leftVect[indexOne++];
		(*cnt)++;
	}

	//if there are any remaining right elements copy them in merged
	while (indexTwo < subVectTwo) {
		printM(*v, -1, -1, -1, mid + 1 + indexTwo, *cnt, speed, true);
		(*v)[indexMerged++] = rightVect[indexTwo++];
		(*cnt)++;
	}
}

void mergeSortAlg(std::vector<int> *v, int begin, int end, int n, int* cnt, int speed) {	//merge sort algorithm
	if (begin >= end)
		return;
	int mid = begin + (end - begin) / 2;
	mergeSortAlg(v, begin, mid, n, cnt, speed);
	mergeSortAlg(v, mid + 1, end, n, cnt, speed);
	merge(v, begin, mid, end, n, cnt, speed);
	printM(*v, -1, -1, -1, -1, *cnt, speed, false);
}

void mergeSort() {		//function that is called in main and which calls mergeSortAlg
	int n = 0;
	int speed = 0;

	userInput("MERGE SORT", &n, &speed);

	std::vector<int> vect;

	initVector(&vect, n);

	gotoXY(1, n + 8);
	std::cout << "Press any key to start...";
	char key = _getch();

	int cnt = 0;

	mergeSortAlg(&vect, 0, vect.size(), n, &cnt, speed);
	mergePrintDone(vect, cnt, speed);

	gotoXY(1, n + 10);
	std::cout << "Press any key to go back to menu...";
}

void printM(std::vector<int> v, int i11, int i12, int i21, int i22, int cnt, int speed, bool inserting) {
	userInputPrint("MERGE SORT", v.size(), speed);
	color(11);
	std::cout << "Inserting into temp vectors   ";
	color(14);
	std::cout << "Comparing elements from temp vectors   ";
	color(13);
	std::cout << "Inserting into vector";

	for (int k = 0; k < v.size(); k++) {
		color(7);					//white
		if (k == i11 || k == i12)	//inserting into temp vectors
			color(11);				//cyan
		if (k == i21 || k == i22) {	
			if (inserting == true)	//inserting into v
				color(13);			//purple
			else                    //comparing elements in left and right temp vectors
				color(14);			//yellow
		}
		arrayPrint(v[k], k);
	}
	elementsCheckedPrint(v.size(), cnt);
}

void mergePrintDone(std::vector<int> v, int cnt, int speed) {
	userInputPrint("MERGE SORT", v.size(), speed);
	color(11);
	std::cout << "Inserting into temp vectors   ";
	color(14);
	std::cout << "Comparing elements from temp vectors   ";
	color(13);
	std::cout << "Inserting into vector";

	for (int k = 0; k < v.size(); k++) {
		color(10);					//green
		arrayPrint(v[k], k);
	}
	elementsCheckedPrint(v.size(), cnt);
}

//===========QUICK===========				//find better solution

/* This function takes last element as pivot, places
   the pivot element at its correct position in sorted
	array, and places all smaller (smaller than pivot)
   to left of pivot and all greater elements to right
   of pivot */
int partition(std::vector<int>* v, std::vector<int>* sortedElems, int start, int end, int* cnt, int speed)	//CHECK
{
	int pivot = (*v)[end];    // pivot
	(*cnt)++;
	
	int i = start;  // Index of smaller element
	quickPrint(v, sortedElems, i, -1, end, *cnt, speed, false, false);

	for (int j = start; j <end; j++)
	{
		(*cnt)++;
		// If current element is smaller than or equal to pivot
		quickPrint(v, sortedElems, i, j, end, *cnt, speed, false, false);
		if ((*v)[j] < pivot)
		{	
			quickPrint(v, sortedElems, i, j, end, *cnt, speed, true, false);
			swap(&(*v)[i], &(*v)[j]);
			(*cnt)++;
			quickPrint(v, sortedElems, i, j, end, *cnt, speed, true, false);
			i++;    // increment index of smaller elements
		}	
	}
	quickPrint(v, sortedElems, i, -1, end, *cnt, speed, false, true);
	swap(&(*v)[i], &(*v)[end]);
	quickPrint(v, sortedElems, i, -1, end, *cnt, speed, false, true);
	return (i);
}

void quickSortAlg(std::vector<int>* v, std::vector<int>* sortedElems, int start, int end, int* cnt, int speed)
{
	if (start < end)
	{
		// pi is partitioning index, vect[pi] is now at right place
		int pi = partition(v, sortedElems, start, end, cnt, speed);
		sortedElems->push_back(pi);

		// Separately sort elements before partition and after partition
		quickSortAlg(v, sortedElems, start, pi - 1, cnt, speed);
		quickSortAlg(v, sortedElems, pi + 1, end, cnt, speed);
	}
}

void quickSort() {		//function that is called in main and which calls quickSortAlg
	int n = 0;
	int speed = 0;

	userInput("QUICK SORT", &n, &speed);

	std::vector<int> vect;
	std::vector<int> sortedElements;

	initVector(&vect, n);

	gotoXY(1, n + 8);
	std::cout << "Press any key to start...";
	char key = _getch();

	int cnt = 0;

	quickSortAlg(&vect, &sortedElements, 0, vect.size()-1, &cnt, speed);
	quickPrintDone(vect, cnt, speed);

	gotoXY(1, n + 10);
	std::cout << "Press any key to go back to menu...";
}

void quickPrint(std::vector<int> *v, std::vector<int>* sortedElems, int i, int j, int end, int cnt, int speed, bool swapJ, bool swapEnd) {
	userInputPrint("QUICK SORT", (*v).size(), speed);
	color(12);		//red
	std::cout << "Pivot   ";
	color(14);		//yellow
	std::cout << "Comparing to pivot   ";
	color(11);		//cyan
	std::cout << "Smaller than pivot   ";
	color(13);		//purple
	std::cout << "Swapping";


	for (int k = 0; k < (*v).size(); k++) {
		color(7);					//white
		if (k == j) 				//comparing to pivot
			color(14);				//yellow
		if (k == end)				//pivot
			color(12);				//red
		if (k < i)					//elements smaller than pivot
			color(11);
		if (swapJ && (k == i || k == j))
			color(13);				//purple
		if (swapEnd && (k == end || k == i))
			color(13);				//purple
		for (int c = 0; c < (*sortedElems).size(); c++) {
			if (k == (*sortedElems)[c]) {
				color(10);	//green
				break;
			}
		}
		arrayPrint((*v)[k], k);
	}
	elementsCheckedPrint((*v).size(), cnt);
}

void quickPrintDone(std::vector<int> v, int cnt, int speed) {
	userInputPrint("QUICK SORT", v.size(), speed);
	color(12);
	std::cout << "Pivot   ";
	color(14);
	std::cout << "Comparing to pivot   ";
	color(11);
	std::cout << "Smaller than pivot   ";
	color(13);
	std::cout << "Swapping";

	for (int k = 0; k < v.size(); k++) {
		color(10);					//green
		arrayPrint(v[k], k);
	}
	elementsCheckedPrint(v.size(), cnt);
}