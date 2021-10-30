#include "Menu.h"

int menu() {
	int defaultColor = 7;		//white
	int highlightColor = 12;	//red
	int colorSet[] = { highlightColor, defaultColor, defaultColor, defaultColor, defaultColor };
	int cnt = 0;
	char key;

	gotoXY(1, 1);
	color(7);
	std::cout << "MAIN MENU";

	while (true) {
		gotoXY(1, 3);
		color(colorSet[0]);
		std::cout << "Selection sort";

		gotoXY(1, 4);
		color(colorSet[1]);
		std::cout << "Bubble sort";

		gotoXY(1, 5);
		color(colorSet[2]);
		std::cout << "Insertion sort";

		gotoXY(1, 6);
		color(colorSet[3]);
		std::cout << "Merge sort";

		gotoXY(1, 7);
		color(colorSet[4]);
		std::cout << "Quick sort";

		key = _getch();

		switch (key) {
		case 72: {	//up arrow key
			if (cnt > 0)
				cnt--;
			break;
		}
		case 80: {	//down arrow key
			if (cnt < 4)
				cnt++;
			break;
		}
		case '\r': {	//enter
			color(defaultColor);
			system("cls");			//clear console window
			return cnt;
			break;
		}
		}

		for(int i=0;i<=4;i++)
			colorSet[i] = defaultColor;

		colorSet[cnt] = highlightColor;
	}
}