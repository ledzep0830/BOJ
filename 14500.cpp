#include <cstdio>
#include <algorithm>
using namespace std;

int board[500][500];
bool isVisited[500][500];
int dirRow[4] = {0, 0, -1, 1};
int dirCol[4] = {1, -1, 0, 0};
int maxVal, N, M;

void findTshapeMax(int row, int col);
void DFS(int iterNum, int sum, int row, int col);
void findMax(int row, int col);

int main(void) {
    scanf("%d %d", &N, &M);

    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            scanf("%d", &board[i][j]);

    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            findMax(i, j);

    printf("%d", maxVal);    

    return 0;
}

void findMax(int row, int col) {
    findTshapeMax(row, col);

    isVisited[row][col] = true;
    DFS(0, board[row][col], row, col);
    isVisited[row][col] = false;
}

void DFS(int iterNum, int sum, int row, int col) {
    if(iterNum==3) {
        maxVal = max(maxVal, sum);
        return;
    }
    for(int i=0; i<4; i++) {
        int newRow = row + dirRow[i];
        int newCol = col + dirCol[i];
        if(newRow<0 || newCol<0 || newRow>=N || newCol>=M)
            continue;
        if(isVisited[newRow][newCol])
            continue;
        isVisited[newRow][newCol] = true;
        DFS(iterNum+1, sum+board[newRow][newCol], newRow, newCol);
        isVisited[newRow][newCol] = false;
    }
}

void findTshapeMax(int row, int col) {
    if(row-1>=0 && col+2<M) // ㅗ
        maxVal = max(maxVal, board[row][col] + board[row][col+1] + board[row][col+2] + board[row-1][col+1]);
    if(row+1<N && col+2<M) // ㅜ
        maxVal = max(maxVal, board[row][col] + board[row][col+1] + board[row][col+2] + board[row+1][col+1]);
    if(row+2<N && col-1>=0) // ㅓ
        maxVal = max(maxVal, board[row][col] + board[row+1][col] + board[row+2][col] + board[row+1][col-1]);
    if(row+2<N && col+1<M) // ㅏ
        maxVal = max(maxVal, board[row][col] + board[row+1][col] + board[row+2][col] + board[row+1][col+1]);
}
