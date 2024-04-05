#include <iostream>

using namespace std;

int dp[1001]={0,};

void process()
{
    dp[1]=1;
    dp[2]=2;
    for(int i=3; i<=1000; i++)
    {
        dp[i]=(dp[i-1]+dp[i-2])%10007;
    }
}

int main() {
    int n;
    cin >> n;
    process();
    cout << dp[n];
    return 0;
}