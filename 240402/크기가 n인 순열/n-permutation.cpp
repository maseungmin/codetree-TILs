#include <iostream>
#include <vector>

using namespace std;

int n,m;
vector<int>result;
bool used[10] = {false,};

void input()
{
    cin >> n;
}

void print()
{
    for(int i=0; i<n; i++)
    {
        cout << result[i] << " ";
    }
    cout << "\n";
}

void findCombination(int cnt)
{
    if(cnt==n)
    {
        print();
        return;
    }

    for(int i=1; i<=n; i++)
    {
        if(!used[i]){
        result.push_back(i);
        used[i] = true;
        findCombination(cnt+1);
        result.pop_back();
        used[i] = false;
        }
    }
}

int main() {
    input();
    findCombination(0);
    return 0;
}