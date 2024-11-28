#include "MyForm.h"
#using <system.drawing.dll>
#include <iostream>
#include <vector>
#include <unordered_map>

#pragma comment(lib, "user32.lib")

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;
using namespace System::Drawing::Drawing2D;
using namespace std;




[STAThreadAttribute]
int main()
{
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	Revers::MyForm form;
	Application::Run(% form);
}
struct coord
{
	int row;
	int col;
};
coord MV;
vector<vector<vector<char>>> board;
int n = 8;
int player;
int compPlr;
int winner;
int GameList;
int r, Complexity;
bool Start = false;
unordered_map<char, int> remainingCoins;
unordered_map<char, int> coinsCountOnBoard;

void Revers::MyForm::displayBoard() {
	gr = this->pictureBox1->CreateGraphics();
	Green = gcnew SolidBrush(Color::Green);
	Black = gcnew SolidBrush(Color::Black);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[0][i][j] == 'W') {
				gr->FillEllipse(Green, i * 75 + 8, j * 75 + 8, 60, 60);
			}
			if (board[0][i][j] == 'B') {
				gr->FillEllipse(Black, i * 75 + 8, j * 75 + 8, 60, 60);
			}
		}
	}
	this->LCP->Text = remainingCoins['W'].ToString();
	this->LCC->Text = remainingCoins['B'].ToString();
	this->COBP->Text = coinsCountOnBoard['W'].ToString();
	this->COBC->Text = coinsCountOnBoard['B'].ToString();
	if (isGameOver()) {
		board.clear();
		switch (winner) {
		case 1:
			MessageBox::Show("Поздравляем, Вы победили!!!" , "Конец игры");
			break;
		case -1:
			MessageBox::Show("Вы проиграли." , "Конец игры");
			break;
		case 0:
			MessageBox::Show("Победителей нет.\nНичья." , "Конец игры");
			break;
		}
		return;
	}
}

System::Void Revers::MyForm::pictureBox1_MouseUp(System::Object ^ sender, System::Windows::Forms::MouseEventArgs ^ e) {
	int row, col;
	if (!Start) { return; }
	comboBox1->Enabled = false;
	row = e->X / 75;
	col = e->Y / 75;
	if (isValidMove(row, col)) {
		makeMove(row, col);
	}
	else {
		MessageBox::Show("Невозможный ход!");
		return;
	}

	displayBoard();

	turnComp();
	makeMove(MV.row, MV.col);
	displayBoard();
	}

System::Void Revers::MyForm::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (Start) {
		board.clear();
		pictureBox1->Refresh();
		coinsCountOnBoard.clear();
		remainingCoins.clear();
		comboBox1->Enabled = !comboBox1->Enabled;
		Start = false;
		button1->Text = "Начать";
		return;
	}
	else { comboBox1->Enabled = false; }
	Start = true;
	board.resize(20); r = 0;
	GameList = 0;
	player = 1;
	compPlr = -1;
	winner = 0;
	vector<char> temp;
	board.resize(20);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (temp.size() != 8)
			{
				temp.push_back('-');
			}
		}
		board[GameList].push_back(temp);
	}
	board[GameList][3][3] = 'B';
	board[GameList][3][4] = 'W';
	board[GameList][4][3] = 'W';
	board[GameList][4][4] = 'B';
	remainingCoins.insert({ 'B', 30 });
	remainingCoins.insert({ 'W', 30 });
	coinsCountOnBoard.insert({ 'B', 2 });
	coinsCountOnBoard.insert({ 'W', 2 });
	displayBoard();
	switch (comboBox1->SelectedIndex) {
	case 0:
		Complexity = -1;
		break;
	case 1:
		Complexity = 0;
		break;
	case 2:
		Complexity = 3;
		break;
	case 3:
		Complexity = 5;
		break;
	}
	button1->Text = "Начать заново";
}

int Revers::MyForm::getPlayer()
{
	if (player == -1)
	{
		return 2;
	}
	return player;
}

int Revers::MyForm::getOppPlayer()
{
	if (player == -1)
	{
		return 1;
	}
	return 2;
}

void Revers::MyForm::changeCoins(char colour, int row, int col, int deltaRow, int deltaCol) // ЗАХВАТ ФИШЕК
{
	char oppColour = 'W';
	if (colour == 'W')
	{
		oppColour = 'B';
	}

	while (board[GameList][row][col] == oppColour)
	{
		board[GameList][row][col] = colour;
		if (GameList == 0 && r == 0)
		{
			coinsCountOnBoard[colour]++;
			coinsCountOnBoard[oppColour]--;
		}
		row += deltaRow;
		col += deltaCol;
	}
	return;
}

bool Revers::MyForm::checkFlip(char colour, int row, int col, int deltaRow, int deltaCol) // ПРОВЕРКА ХОДА НА ЗАХВАТ ФИШЕК СОПЕРНИКА
{
	char oppColour = 'W';
	if (colour == 'W')
	{
		oppColour = 'B';
	}

	if ((row < 0) || (row >= 8) || (col < 0) || (col >= 8))
	{
		return false;
	}

	if (board[GameList][row][col] == oppColour)
	{
		while ((row >= 0) && (row < 8) && (col >= 0) && (col < 8))
		{
			if (board[GameList][row][col] == '-')
			{
				return false;
			}
			if (board[GameList][row][col] == colour)
			{
				return true;
			}

			row += deltaRow;
			col += deltaCol;
		}
	}
	return false;
}

bool Revers::MyForm::isValidMove(int row, int col) // ФУНКЦИЯ ПРОВЕРКИ ХОДА НА ПРАВИЛЬНОСТЬ
{
	if ((row < 0) || (row >= 8) || (col < 0) || (col >= 8))
	{
		return false;
	}

	if (board[GameList][row][col] != '-')
	{
		return false;
	}

	char colour = 'W';
	if (getPlayer() == 2)
	{
		colour = 'B';
	}

	// ПРОВЕРКА ВВЕРХ
	if (checkFlip(colour, row - 1, col, -1, 0))
	{
		return true;
	}
	// ПРОВЕРКА ВНИЗ
	if (checkFlip(colour, row + 1, col, 1, 0))
	{
		return true;
	}
	// ПРОВЕРКА ВЛЕВО
	if (checkFlip(colour, row, col - 1, 0, -1))
	{
		return true;
	}
	// ПРОВЕРКА ВПРАВО
	if (checkFlip(colour, row, col + 1, 0, 1))
	{
		return true;
	}
	// ПРОВЕРКА ВНИЗ И ВПРАВО
	if (checkFlip(colour, row + 1, col + 1, 1, 1))
	{
		return true;
	}
	// ПРОВЕРКА ВНИЗ И ВЛЕВО
	if (checkFlip(colour, row + 1, col - 1, 1, -1))
	{
		return true;
	}
	// ПРОВЕРКА ВВЕРХ И ВПРАВО
	if (checkFlip(colour, row - 1, col + 1, -1, 1))
	{
		return true;
	}
	// ПРОВЕРКА ВВЕРХ И ВЛЕВО
	if (checkFlip(colour, row - 1, col - 1, -1, -1))
	{
		return true;
	}

	return false;
}

void Revers::MyForm::flipCoins(char colourF, int rowF, int colF) // ПЕРЕВОРАЧИВАНИЕ ПОБИТЫХ ФИШЕК
{
	// ПРОВЕРКА ВВЕРХ
	if (checkFlip(colourF, rowF - 1, colF, -1, 0))
	{
		changeCoins(colourF, rowF - 1, colF, -1, 0);
	}
	// ПРОВЕРКА ВНИЗ
	if (checkFlip(colourF, rowF + 1, colF, 1, 0))
	{
		changeCoins(colourF, rowF + 1, colF, 1, 0);
	}
	// ПРОВЕРКА ВЛЕВО
	if (checkFlip(colourF, rowF, colF - 1, 0, -1))
	{
		changeCoins(colourF, rowF, colF - 1, 0, -1);
	}
	// ПРОВЕРКА ВПРАВО
	if (checkFlip(colourF, rowF, colF + 1, 0, 1))
	{
		changeCoins(colourF, rowF, colF + 1, 0, 1);
	}
	// ПРОВЕРКА ВНИЗ И ВПРАВО
	if (checkFlip(colourF, rowF + 1, colF + 1, 1, 1))
	{
		changeCoins(colourF, rowF + 1, colF + 1, 1, 1);
	}
	// ПРОВЕРКА ВНИЗ И ВЛЕВО
	if (checkFlip(colourF, rowF + 1, colF - 1, 1, -1))
	{
		changeCoins(colourF, rowF + 1, colF - 1, 1, -1);
	}
	// ПРОВЕРКА ВВЕРХ И ВПРАВО
	if (checkFlip(colourF, rowF - 1, colF + 1, -1, 1))
	{
		changeCoins(colourF, rowF - 1, colF + 1, -1, 1);
	}
	// ПРОВЕРКА ВВЕРХ И ВЛЕВО
	if (checkFlip(colourF, rowF - 1, colF - 1, -1, -1))
	{
		changeCoins(colourF, rowF - 1, colF - 1, -1, -1);
	}
}

void Revers::MyForm::makeMove(int row, int col) // ВЫПОЛНЕНИЕ ХОДА НА ГЛАВНОЙ ДОСКЕ
{
	char colour = 'W';
	if (getPlayer() == 2)
	{
		colour = 'B';
	}
	board[GameList][row][col] = colour;
	remainingCoins[colour]--;
	coinsCountOnBoard[colour]++;

	flipCoins(colour, row, col);

	player = -1 * player;
	return;
}

void Revers::MyForm::turnComp() // ХОД КОМПЬЮТЕРА
{
	int max_score;
	int score;
	r = 1;
	compPlr = player;
	max_score = INT_MIN;
	board[1] = board[0];
	if (Complexity == -1) // Реализация самой простой сложности
	{
		while (!isValidMove(MV.row, MV.col)) {
			MV.row = rand() % n;
			MV.col = rand() % n;
		}
		return;
	}
	GameList++;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (board[1][i][j] == '-' && isValidMove(i, j))
			{
				board[1][i][j] = 'B';
				flipCoins('B', i, j);
				score = minimax(Complexity, 1);
				player = compPlr;
				board[1] = board[0];
				if (score > max_score)
				{
					max_score = score;
					MV.row = i;
					MV.col = j;
				}
			}
		}
	}
	r = 0;
	GameList = 0;
	return;
}

int Revers::MyForm::minimax(int depth, int plr) // АЛГОРИТМ МИНИМАКС
{
	if (depth == 0)
	{
		return sum();

	}
	int score;
	int max_score;
	board[GameList + 1] = board[GameList];
	if (plr == -1) // ХОД КОМПЬЮТЕРА, ЗНАЧИТ ИЩЕМ ЛУЧШИЙ РЕЗУЛЬТАТ(MAX)
	{
		player = plr;
		max_score = INT_MIN;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (board[GameList][i][j] == '-' && isValidMove(i, j))
				{
					GameList++;
					board[GameList][i][j] = 'B';
					flipCoins('B', i, j);
					score = minimax(depth - 1, 1);
					board[GameList] = board[GameList - 1];
					GameList--;
					player = plr;
					max_score = max(score, max_score);
				}
			}
		}
	}
	else // ХОД ИГРОКА, ЗНАЧИТ ИЩЕМ ХУДШИЙ РЕЗУЛЬТАТ(MIN)
	{
		player = plr;
		max_score = INT_MAX;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (board[GameList][i][j] == '-' && isValidMove(i, j))
				{
					GameList++;
					board[GameList][i][j] = 'W';
					flipCoins('W', i, j);
					score = minimax(depth - 1, -1);
					board[GameList] = board[GameList - 1];
					GameList--;
					player = plr;
					max_score = min(score, max_score);
				}
			}
		}

	}
	return max_score;
}

int Revers::MyForm::sum()
{
	int W = 0; int B = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (board[GameList][i][j] == 'W')
			{
				W++;
			}
			else
			{
				if (board[GameList][i][j] == 'B')
				{
					B++;
				}
			}
		}
	}
	return B - W;
}

bool Revers::MyForm::isGameOver() // ПРОВЕРКА НА КОНЕЦ ИГРЫ
{
	if (coinsCountOnBoard['B'] == 0)
	{
		winner = -1;
		return true;
	}
	else if (coinsCountOnBoard['W'] == 0)
	{
		winner = 1;
		return true;
	}
	else if (remainingCoins['B'] == 0 && remainingCoins['W'] == 0)
	{
		if (coinsCountOnBoard['B'] > coinsCountOnBoard['W'])
		{
			winner = -1;
		}
		else if (coinsCountOnBoard['B'] < coinsCountOnBoard['W'])
		{
			winner = 1;
		}
		else
		{
			winner = 0;
		}
		return true;
	}
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (isValidMove(i, j)) {
				return false;
			}
		}
	}
	if (coinsCountOnBoard['B'] > coinsCountOnBoard['W'])
	{
		winner = -1;
	}
	else if (coinsCountOnBoard['B'] < coinsCountOnBoard['W'])
	{
		winner = 1;
	}
	else
	{
		winner = 0;
	}
	return true;
}