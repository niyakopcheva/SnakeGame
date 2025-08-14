#include <iostream>

bool gameOver{};

//map dimentions
const int width{ 20 };
const int height(20);

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
	fruitX = rand() % width; //generate random num between 0 and width-1
	fruitY = rand() % height;

	score = 0;
}

void Draw() {

}

void Input() {

}

void Logic() {

}

int main() {
	Setup();
	while (!gameOver) {
		Draw();
		Input();
		Logic();
	}

	return 0;
}