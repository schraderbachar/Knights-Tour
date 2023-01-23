#include <stdio.h>

int isValid(int x, int y, int board[5][5])
{
    if (x >= 0 && x <= 4 && y >= 0 && y <= 4 && board[x][y] != 0)
    {
        return 1; // true
    }
    return 0; // false
}
void copyBoard(int oldBoard[5][5], int newBoard[5][5])
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            newBoard[i][j] = oldBoard[i][j];
        }
    }
}

void copyOrder(int oldBoard[25], int newBoard[25])
{
    for (int i = 0; i < 25; ++i)
    {
        newBoard[i] = oldBoard[i];
    }
}
void solveProblem(int moveCount, int x, int y, int board[5][5], int orderBoard[25])
{
    int xMoves[8] = {2, 1, -1, -2, -2, -1, 1, 2};
    int yMoves[8] = {1, 2, 2, 1, -1, -2, -2, -1};
    orderBoard[moveCount] = board[x][y];
    board[x][y] = 0;
    moveCount++;
    if (moveCount < 25)
    { // length of xMoves
        for (int i = 0; i < 8; ++i)
        {
            int nextX = x + xMoves[i];
            int nextY = y + yMoves[i];
            if (isValid(nextX, nextY, board) == 1)
            {
                int newBoard[5][5];
                copyBoard(board, newBoard);
                int copyOrderBoard[25];
                copyOrder(orderBoard, copyOrderBoard);
                int copyMoveCount = moveCount;
                solveProblem(copyMoveCount, nextX, nextY, newBoard, copyOrderBoard);
            }
        }
    }
    else
    {
        for (int i = 0; i < 25; i++)
        {
            if (i == 24)
            {
                printf("%d", orderBoard[i]);
            }
            else
            {
                printf("%d, ", orderBoard[i]);
            }
        }
        printf("\n");
    }
}

void solveKnightTourProblem()
{

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            int visited[5][5] = {
                {1, 2, 3, 4, 5},
                {6, 7, 8, 9, 10},
                {11, 12, 13, 14, 15},
                {16, 17, 18, 19, 20},
                {21, 22, 23, 24, 25}};
            int orderVisited[25];
            solveProblem(0, i, j, visited, orderVisited);
        }
    }
}

int main()
{
    solveKnightTourProblem();
    return 0;
}
