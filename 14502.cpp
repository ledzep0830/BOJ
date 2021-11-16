#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

int rowDir[4] = {0, 0, -1, 1};
int colDir[4] = {-1, 1, 0, 0};
int initMap[8];
int N, M;
int maxVal;

void BFS(void);
void BuildWall(int cnt, int prevRow, int prevCol);

int main(void) {
    scanf("%d %d", &N, &M);
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            scanf("%d", &initMap[i][j]);
    
    BuildWall(0);

    printf("%d", maxVal);
}

void BuildWall(int cnt) {
    if(cnt==3) {
        BFS();
        return;
    }

    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++) {
            if(initMap[i][j]==0) {
                initMap[i][j] = 1;
                BuildWall(cnt+1);
                initMap[i][j] = 0;
            }
        }
}

void BFS(void) {
    int afterVirusMap[8][8];
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            afterVirusMap[i][j] = initMap[i][j];
    
    queue<pair<int, int> > q;
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            if(afterVirusMap[i][j]==2)
                q.push(make_pair(i, j));
    
    while(!q.empty()) {
        int curRow = q.front().first;
        int curCol = q.front().second;
        q.pop();
        
        for(int i=0; i<4; i++) {
            int newRow = curRow + rowDir[i];
            int newCol = curCol + colDir[i];
            if(0<=newRow && 0<=newCol && newRow<N && newCol<M)
                if(afterVirusMap[newRow][newCol]==0) {
                    afterVirusMap[newRow][newCol] = 2;
                    q.push(make_pair(newRow, newCol));
                }
        }
    }

    int emptyCnt = 0;
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                if(afterVirusMap[i][j]==0)
                    emptyCnt++;
    maxVal = max(maxVal, emptyCnt);
}
