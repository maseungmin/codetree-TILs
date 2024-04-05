#include <iostream>

using namespace std;

int dp[1001]={0,};

void process()
{
    dp[2]=1;
    dp[3]=1;
    for(int i=4; i<=1000; i++)
    {
        dp[i]=(dp[i-2]+dp[i-3])%10007;
    }

}

int main() {
    int n;
    cin >> n;
    process();
    cout << dp[n];
    return 0;
}