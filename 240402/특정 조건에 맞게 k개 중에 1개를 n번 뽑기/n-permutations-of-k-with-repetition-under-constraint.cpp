#include <iostream>
#include <vector>

using namespace std;

int k,n;
vector<int>result;

void input()
{
    cin >> k >> n;
}

void print()
{
    for(int i=0; i<n; i++)
    {
        cout << result[i] << " ";
    }
    cout << '\n';
}

void process(int cnt)
{
    if(cnt==n)
    {
        print();
        return;
    }

    for(int i=1; i<=k; i++)
    {
        if(cnt<2||result[cnt-1]!=i||result[cnt-2]!=i){
        result.push_back(i);
        process(cnt+1);
        result.pop_back();
        }
    }
}

int main() {
    input();
    process(0);
    return 0;
}