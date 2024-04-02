#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n,m;
int dr[4] = {-1,1,0,0};
int dc[4] = {0,0,-1,1};
int map[101][101] = {0,};
bool visited[101][101] = {false,};

void input()
{
    cin >> n >> m;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            cin >> map[i][j];
        }
    }
}

bool Inrange(int r, int c)
{
    return r>0&&r<=n&&c>0&&c<=m;
}

void bfs()
{
    queue<pair<int,int>>q;
    //탈출여부
    bool flag = false;
    //시작점 큐에 넣어주기
    q.push({1,1});
    visited[1][1] = true;
    //경로가 없을때까지 반복
    while(!q.empty())
    {
        //현재위치 저장
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        //끝칸에 도착했을 경우(탈출성공)
        if(r==n && c==m)
        {
            flag = true;
            break;
        }
        //경로있는지 상하좌우 탐색
        for(int i=0; i<4; i++)
        {
            int nr = r+dr[i];
            int nc = c+dc[i];
            //갈 수 있는 길인지 확인
            if(Inrange(nr,nc)&&!visited[nr][nc]&&map[nr][nc]==1)
            {
                q.push({nr,nc});
                visited[nr][nc] = true;
            }
        }
    }
    if(flag)
        //탈출성공
        cout << 1;
    else
        //탈출실패
        cout << 0;

}

int main() {
    input();
    bfs();
    return 0;
}