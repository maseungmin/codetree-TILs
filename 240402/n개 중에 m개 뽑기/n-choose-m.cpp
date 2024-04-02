#include <iostream>
#include <vector>

using namespace std;

int n,m;
vector<int>result;

void input()
{
    cin >> n >> m;
}

void print()
{
    for(int i=0; i<m; i++)
    {
        cout << result[i] << " ";
    }
    cout << "\n";
}

void findCombination(int cnt)
{
    if(cnt==m)
    {
        print();
        return;
    }


    for(int i=1; i<=n; i++)
    {
        if(cnt==0||i>result[cnt-1]){
        result.push_back(i);
        findCombination(cnt+1);
        result.pop_back();
        }
    }
}

int main() {
    input();
    findCombination(0);
    return 0;
}