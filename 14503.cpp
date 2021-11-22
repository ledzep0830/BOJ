#include <cstdio>
using namespace std;

int board[50][50];
bool isVisited[50][50];
int dirRow[4] = {-1, 0, 1, 0};
int dirCol[4] = {0, 1, 0, -1};
int cnt;

void DFS(int rowPos, int colPos, int dirNum);

int main(void) {
    int rowNum, colNum, rowPos, colPos, dirNum;
    scanf("%d %d", &rowNum, &colNum);
    scanf("%d %d %d", &rowPos, &colPos, &dirNum);

    for(int i=0; i<rowNum; i++)
        for(int j=0; j<colNum; j++)
            scanf("%d", &board[i][j]);
    
    DFS(rowPos, colPos, dirNum);

    printf("%d", cnt);

    return 0;
}

void DFS(int rowPos, int colPos, int dirNum) {
    if(board[rowPos][colPos]==1)
        return;

    if(!isVisited[rowPos][colPos]) {
        isVisited[rowPos][colPos] = true;
        cnt++;
    }

    bool flag = false;
        
    for(int i=0; i<4; i++) {
        dirNum = (dirNum+3)%4;
        int newRowPos = rowPos + dirRow[dirNum];
        int newColPos = colPos + dirCol[dirNum];
        if(!board[newRowPos][newColPos] && !isVisited[newRowPos][newColPos]) {
            rowPos += dirRow[dirNum];
            colPos += dirCol[dirNum];
            flag = true;
            break; 
        }
    }

    if(!flag) {
        int backDir = (dirNum+2)%4;
        rowPos += dirRow[backDir];
        colPos += dirCol[backDir];
    }

    DFS(rowPos, colPos, dirNum);
};
