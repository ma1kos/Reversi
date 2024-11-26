#include <unordered_map>
#include <iostream>
#include <vector>
#include <string.h>

using namespace std;


class Reversi
{
    struct coord
    {
        int row;
        int col;
    };
    coord move;
    vector<vector<vector<char>>> board;
    int n = 8;
    int player;
    int compPlr;
    int winner;
    int list;
    int r;
    int scoreS;
    unordered_map<char, int> remainingCoins;
    unordered_map<char, int> coinsCountOnBoard;


public:
    Reversi()
    {
        r = 0;
        list = 0;
        player = 1;
        compPlr = -1;
        winner = 0;
        list = 0;
        scoreS = 0;
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
            board[list].push_back(temp);
        }
        board[list][3][3] = 'B';
        board[list][3][4] = 'W';
        board[list][4][3] = 'W';
        board[list][4][4] = 'B';
        remainingCoins.insert({ 'B', 30 });
        remainingCoins.insert({ 'W', 30 });
        coinsCountOnBoard.insert({ 'B', 2 });
        coinsCountOnBoard.insert({ 'W', 2 });
    }

private:
    bool checkFlip(char colour, int row, int col, int deltaRow, int deltaCol) // ПРОВЕРКА ХОДА НА ЗАХВАТ ФИШЕК СОПЕРНИКА
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

        if (board[list][row][col] == oppColour)
        {
            while ((row >= 0) && (row < 8) && (col >= 0) && (col < 8))
            {
                if (board[list][row][col] == '-')
                {
                    return false;
                }
                if (board[list][row][col] == colour)
                {
                    return true;
                }

                row += deltaRow;
                col += deltaCol;
            }
        }
        return false;
    }
    void changeCoins(char colour, int row, int col, int deltaRow, int deltaCol) // ЗАХВАТ ФИШЕК
    {
        char oppColour = 'W';
        if (colour == 'W')
        {
            oppColour = 'B';
        }

        while (board[list][row][col] == oppColour)
        {
            board[list][row][col] = colour;
            if (list == 0 && r == 0)
            {
                coinsCountOnBoard[colour]++;
                coinsCountOnBoard[oppColour]--;
            }
            if (oppColour == 'W')
            {
                scoreS++; // ПОВЫШЕНИЕ СЧЁТЧИКА ДЛЯ МИНИМАКС
            }
            else
            {
                scoreS--; // ПОНИЖЕНИЕ СЧЁТЧИКА ДЛЯ МИНИМАКС
            }

            row += deltaRow;
            col += deltaCol;
        }
        return;
    }

public:
    int moveRow() // КООРДИНАТЫ СТРОК
    {
        return move.row;
    }
    int moveCol() // СТОЛБЦОВ
    {
        return move.col;
    }
    bool isValidMove(int row, int col)
    {
        if ((row < 0) || (row >= 8) || (col < 0) || (col >= 8))
        {
            return false;
        }

        if (board[list][row][col] != '-')
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
    void makeMove(int row, int col) // ВЫПОЛНЕНИЕ ХОДА НА ГЛАВНОЙ ДОСКЕ
    {
        char colour = 'W';
        if (getPlayer() == 2)
        {
            colour = 'B';
        }
        board[list][row][col] = colour;
        remainingCoins[colour]--;
        coinsCountOnBoard[colour]++;

        flipCoins(colour, row, col);

        player = -1 * player;
        return;
    }
    void flipCoins(char colourF, int rowF, int colF) // ПЕРЕВОРАЧИВАНИЕ ПОБИТЫХ ФИШЕК
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
    void displayBoard() //ВЫВОД ДОСКИ НА ДИСПЛЕЙ
    {
        for (int i = 0; i < n; i++)
        {
            cout << i <<" | "<< "\t";
            for (int j = 0; j < n; j++)
            {
                cout << board[0][i][j] << "\t";
            }
            if (i == n - 1)
            {
                cout << "\n" << "  +";
                for (int i = 0; i < n; i++)
                {
                    cout << "——------";
                }
                cout << "\n";
            }
            else { cout << "\n" << "  | " << "\n"; }
        }
        cout << "\t0\t1\t2\t3\t4\t5\t6\t7\n";
        cout << "Осталось фишек у Игрока №" << getOppPlayer() << ": " << remainingCoins['B'] << "\n";
        cout << "Осталось фишек у Игрока №" << getPlayer() << ": " << remainingCoins['W'] << "\n";
        cout << "Счёт Игрока №" << getOppPlayer() << ": " << coinsCountOnBoard['B'] << "\n";
        cout << "Счёт Игрока №" << getPlayer() << ": " << coinsCountOnBoard['W'] << "\n";
        return;
    }

    void turnComp() // ХОД КОМПЬЮТЕРА
    {
        int max_score;
        int score;
        r = 1;
        compPlr = player;
        max_score = INT_MIN;
        board[1] = board[0];
        list++;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                player = -1;
                if (board[1][i][j] == '-' && isValidMove(i, j))
                {
                    player = compPlr;
                    board[1][i][j] = 'B';
                    flipCoins('B', i, j);
                    score = minimax(3, 1);
                    scoreS = 0;
                    board[1] = board[0];
                    if (score > max_score)
                    {
                        max_score = score;
                        move.row = i;
                        move.col = j;
                    }
                }
            }
        }
        r = 0;
        player = compPlr;
        list = 0;
        return;
    }

    int minimax(int depth, int plr) // АЛГОРИТМ МИНИМАКС
    {
        if (depth == 0)
        {
            return scoreS;

        }
        //ПРОВЕРКУ НА КОНЕЦ ИГРЫ
        int score = 0;
        int max_score; int min_score;
        board[list + 1] = board[list];
        if (plr == -1) // ХОД КОМПЬЮТЕРА, ЗНАЧИТ ИЩЕМ ЛУЧШИЙ РЕЗУЛЬТАТ(MAX)
        {
            player = plr;
            max_score = INT_MIN;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (board[list][i][j] == '-' && isValidMove(i, j))
                    {
                        list++;
                        board[list][i][j] = 'B';
                        flipCoins('B', i, j);
                        score = minimax(depth - 1, 1);
                        board[list] = board[list - 1];
                        list--;
                        player = plr;
                        max_score = max(score, max_score);
                    }
                }
            }
            return max_score;
        }
        else // ХОД ИГРОКА, ЗНАЧИТ ИЩЕМ ХУДШИЙ РЕЗУЛЬТАТ(MIN)
        {
            player = plr;
            min_score = INT_MAX;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (board[list][i][j] == '-' && isValidMove(i, j))
                    {
                        list++;
                        board[list][i][j] = 'W';
                        flipCoins('W', i, j);
                        score = minimax(depth - 1, -1);
                        board[list] = board[list - 1];
                        list--;
                        player = plr;
                        min_score = min(score, min_score);
                    }
                }
            }
            return min_score;

        }
    }

    bool isGameOver() // ПРОВЕРКА НА КОНЕЦ ИГРЫ
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
                winner = 1;
            }
            else if (coinsCountOnBoard['B'] < coinsCountOnBoard['W'])
            {
                winner = -1;
            }
            else
            {
                winner = 0;
            }
            return true;
        }
        return false;
    }
    int getPlayer()
    {
        if (player == -1)
        {
            return 2;
        }
        return player;
    }
    int getOppPlayer()
    {
        if (player == -1)
        {
            return 1;
        }
        return 2;
    }
    int getWinner()
    {
        return winner;
    }
};

int main()
{
    Reversi Game;
    setlocale(LC_ALL, "Russian");
    cout << "Игра началась.\n";
    Game.displayBoard();
    int row;
    int col;

    while (!Game.isGameOver())
    {
        cout << "Ходит Игрок №" << Game.getPlayer() << "\n";
        if (Game.getPlayer() == 2)
        {
            Game.turnComp();
            row = Game.moveRow();
            col = Game.moveCol();
        }
        else
        {
            cout << "Введите номер строки: ";
            cin >> row;
            cout << "Введите номер столбца: ";
            cin >> col;
        }
        if (Game.isValidMove(row, col))
        {
            Game.makeMove(row, col);
            system("cls");
            Game.displayBoard();
        }
        else
        {
            cout << "Невозможный ход!!!!!\n";
        }
    }

    cout << "Конец игры.\n";
    if (Game.getWinner() != 0)
    {
        cout << "Победил Игрок № " << Game.getWinner() << ".\n";
    }
    else
    {
        cout << "Игра закончилась ничьёй.\n";
    }

    return 0;
}