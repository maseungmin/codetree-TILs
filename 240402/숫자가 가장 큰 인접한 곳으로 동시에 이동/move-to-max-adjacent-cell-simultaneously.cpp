#include <iostream>

using namespace std;

int arr[21][21] = {0,}; //격자판
int temp[21][21] = {0,}; //구슬배열 
int cnt[21][21]={0,}; //구슬배열복사본
int dr[4] = {-1,1,0,0};
int dc[4] = {0,0,-1,1};
int n,m,t;

void input()
{
    cin >> n >> m >> t;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin >> arr[i][j];
        }
    }
    for(int i=0; i<m; i++)
    {
        int a,b;
        cin >> a >> b;
        a-=1;
        b-=1;
        temp[a][b] = 1;
    }
}

void Move(int r, int c)
{
    int maxNum=0;
    int maxR=0;
    int maxC=0;
    for(int i=0; i<4; i++)
    {
        int nr = r+dr[i];
        int nc = c+dc[i];
        if(nr<0&&nr>=n&&nc<0&&nc>=n)
            continue;
        if(maxNum<arr[nr][nc])
        {
            maxNum = arr[nr][nc];
            maxR=nr;
            maxC=nc;
        }
    }
    cnt[maxR][maxC]+=1;
}

void MoveAll()
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cnt[i][j]=0;
        }
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(temp[i][j]==1)
            {
                Move(i,j);
            }
        }
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            temp[i][j]=cnt[i][j];
        }
    }

}

void deleteCnt()
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(temp[i][j]>=2)
            {
                temp[i][j]=0;
            }
        }
    }
}

void process()
{
    while(t--)
    {
        //1.구슬움직이기
        MoveAll();
        //2.겹치는 구슬삭제
        deleteCnt();
    }
    int result=0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(temp[i][j]==1)
            {
                result++;
            }
        }
    }
    cout << result;
}

int main() {
    input();
    process();
    return 0;
}