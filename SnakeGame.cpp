#include "hideCursor.h"
#include <conio.h>	//console input output
#include <windows.h>
#include <iostream>

bool gameOver{};

//map dimentions
const int width{ 20 };
const int height{ 20 };

//head coordinates
int x{}, y{};

//fruit coordinates
int fruitX{}, fruitY{};

int score{0};

//directions
enum class eDirection{ STOP, LEFT, RIGHT, UP, DOWN};
eDirection dir{};




void Setup() {
	gameOver = false;
	dir = eDirection::STOP;

	//setup snake head in middle of map
	x = width / 2;
	y = height / 2;

	//set fruit at random coordinates
	fruitX = rand() % width;	//generate random num between 0 and width-1
	fruitY = rand() % height;

	score = 0;
}

void Draw() {
	hideCursor();	//to not display cursor in console while printing
	system("cls");	//clear console

	//print top border
	for (int i = 0; i < width+1; i++) 
		std::cout << "#";
	std::cout << std::endl;
	
	//print l and r walls
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (j == 0 || j == width - 1)
				std::cout << "#";

			if (i == y && j == x)
				std::cout << "O";	//print snake head
			else if (i == fruitX && j == fruitY)
				std::cout << "F";
			else
				std::cout << " ";
		}
		std::cout << std::endl;
	}

	//print bottom border
	for (int i = 0; i < width+1; i++) 
		std::cout << "#";
	std::cout << std::endl;
	
}

void Input() {
	if (_kbhit()) {	//checks if key is pressed asynchroniosly
		// wasd commands
		switch (_getch()) {
		case 'w':
			dir = eDirection::UP;
			break;
		case 'a':
			dir = eDirection::LEFT;
			break;
		case 's':
			dir = eDirection::DOWN;
			break;
		case 'd':
			dir = eDirection::RIGHT;
			break;
		case 'x':
			gameOver = true;
			break;
		}
	}
}

void Logic() {
	switch (dir) {	//change head coordinates based on dir
	case eDirection::LEFT:
		--x;
		break;
	case eDirection::RIGHT:
		++x;
		break;
	case eDirection::UP:
		--y;
		break;
	case eDirection::DOWN:
		++y;
		break;
	default:
		break;
	}

	if (x < 0 || x > width || y < 0 || y > height)
		gameOver = true;
}

int main() {
	Setup();
	while (!gameOver) {
		Draw();
		Input();
		Logic();
		Sleep(50);	//make snake speed slower
	}

	return 0;
}