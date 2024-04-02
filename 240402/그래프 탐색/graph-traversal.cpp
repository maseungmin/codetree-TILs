#include <iostream>
#include <vector>

using namespace std;

vector<int>arr[1001];
bool visited[1001]={false,};
int n,m,cnt;

void input()
{
    cin >> n >> m;
    for(int i=0; i<m; i++)
    {
        int a,b;
        cin >> a >> b;
        arr[a].push_back(b);
    }
}

void dfs(int node)
{
    if(visited[node])
        return;
    visited[node] = true;
    cnt++;
    for(int next:arr[node])
    {
        dfs(next);
    }
}

int main() {
    input();
    dfs(1);
    cout << cnt-1 << '\n';
    return 0;
}