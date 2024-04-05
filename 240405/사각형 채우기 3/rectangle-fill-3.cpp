#include <iostream>

using namespace std;

int dp[1001]={0,};

void process()
{
    dp[1]=2;
    dp[2]=7;
    for(int i=3; i<=1000; i++)
    {
        dp[i] = (2*dp[i-1]+4*dp[i-2])%1000000007;
    }
}

int main() {
    int n;
    cin >> n;
    process();
    cout << dp[n];
    return 0;
}