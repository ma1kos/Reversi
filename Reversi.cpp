#include <unordered_map>
#include <iostream>
#include <vector>
#include <string.h>

using namespace std;


class Othello
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
    // int depth;
     //int max_score;
     //int min_score;
    int scoreS;
    unordered_map<char, int> remainingCoins;
    unordered_map<char, int> coinsCountOnBoard;


public:
    Othello()
    {
        list = 0;
        // max_score = 0;
        player = 1;
        compPlr = -1;
        winner = 0;
        list = 0;
        //depth = 2;
        //min_score = 0;
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
            while ((row > 0) && (row < 7) && (col > 0) && (col < 7))
            {
                row += deltaRow;
                col += deltaCol;
                if (board[list][row][col] == '-')
                {
                    return false;
                }
                if (board[list][row][col] == colour)
                {
                    return true;
                }
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
            coinsCountOnBoard[colour]++;
            coinsCountOnBoard[oppColour]--;
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
        // move.row = 1; 
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
        // Check Up
        if (checkFlip(colourF, rowF - 1, colF, -1, 0))
        {
            changeCoins(colourF, rowF - 1, colF, -1, 0);
        }
        // Check Down
        if (checkFlip(colourF, rowF + 1, colF, 1, 0))
        {
            changeCoins(colourF, rowF + 1, colF, 1, 0);
        }
        // Check Left
        if (checkFlip(colourF, rowF, colF - 1, 0, -1))
        {
            changeCoins(colourF, rowF, colF - 1, 0, -1);
        }
        // Check Right
        if (checkFlip(colourF, rowF, colF + 1, 0, 1))
        {
            changeCoins(colourF, rowF, colF + 1, 0, 1);
        }
        // Check Down-Right
        if (checkFlip(colourF, rowF + 1, colF + 1, 1, 1))
        {
            changeCoins(colourF, rowF + 1, colF + 1, 1, 1);
        }
        // Check Down-Left
        if (checkFlip(colourF, rowF + 1, colF - 1, 1, -1))
        {
            changeCoins(colourF, rowF + 1, colF - 1, 1, -1);
        }
        // Check Top-Right
        if (checkFlip(colourF, rowF - 1, colF + 1, -1, 1))
        {
            changeCoins(colourF, rowF - 1, colF + 1, -1, 1);
        }
        // Check Top-Left
        if (checkFlip(colourF, rowF - 1, colF - 1, -1, -1))
        {
            changeCoins(colourF, rowF - 1, colF - 1, -1, -1);
        }
    }
    void displayBoard() //ВЫВОД ДОСКИ НА ДИСПЛЕЙ
    {
        for (int i = 0; i < n; i++)
        {
            cout << i << "\t";
            for (int j = 0; j < n; j++)
            {
                cout << board[0][i][j] << "\t";
            }
            cout << "\n";
        }
        cout << "\t0\t1\t2\t3\t4\t5\t6\t7\n";
        cout << "Coins left for Player-" << getOppPlayer() << ": " << remainingCoins['B'] << "\n";
        cout << "Coins left for Player-" << getPlayer() << ": " << remainingCoins['W'] << "\n";
        cout << "Coins on board for Player-" << getOppPlayer() << ": " << coinsCountOnBoard['B'] << "\n";
        cout << "Coins on board for Player-" << getPlayer() << ": " << coinsCountOnBoard['W'] << "\n";
        return;
    }

    void turnComp() // ХОД КОМПЬЮТЕРА
    {
        int max_score;
        int score;
        scoreS = 0;
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
        player = compPlr;
        list = 0;
        return;
    }

    int minimax(int depth, int plr) // АЛГОРИТМ МИНИМАКС
    {
        if (depth == 0)
        {
            //list--;
            return scoreS;

        }

        /*if (player == -1)
        {
            player = 1;
        }
        else
        {
            player = -1;
        }*/
        //ПРОВЕРКУ НА КОНЕЦ ИГРЫ
        int score = 0;
        int max_score; int min_score;
        //list++;
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
                        //player = compPlr;
                        board[list][i][j] = 'B';
                        scoreS = 0;
                        flipCoins('B', i, j);
                        //depth--;
                        score = minimax(depth - 1, 1);
                        board[list] = board[list - 1];
                        list--;
                        player = plr;
                        max_score = max(score, max_score);
                    }
                }
            }
            //list--;
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
                        //player = compPlr;
                        board[list][i][j] = 'W';
                        scoreS = 0;
                        flipCoins('W', i, j);
                        // depth--;
                        score = minimax(depth - 1, -1);
                        board[list] = board[list - 1];
                        list--;
                        player = plr;
                        min_score = min(score, min_score);
                    }
                }
            }
            //list--;
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
    Othello Game;
    cout << "The Game has started.\n";
    Game.displayBoard();
    int row;
    int col;

    while (!Game.isGameOver())
    {
        cout << "Player-" << Game.getPlayer() << "'s turn.\n";
        if (Game.getPlayer() == 2)
        {
            Game.turnComp();
            row = Game.moveRow();
            col = Game.moveCol();
        }
        else
        {
            cout << "Enter the Row Number: ";
            cin >> row;
            cout << "Enter the Column Number: ";
            cin >> col;
        }
        if (Game.isValidMove(row, col))
        {
            Game.makeMove(row, col);
        }
        else
        {
            cout << "Invalid Move. Try Again.\n";
        }

        Game.displayBoard();
    }

    cout << "Game Over.\n";
    if (Game.getWinner() != 0)
    {
        cout << "The winner is Player-" << Game.getWinner() << ".\n";
    }
    else
    {
        cout << "The match ended in a draw.\n";
    }

    return 0;
}