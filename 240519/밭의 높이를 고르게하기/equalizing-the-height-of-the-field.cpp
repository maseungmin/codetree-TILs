#include <iostream>
#include <cmath>
#include <climits>

using namespace std;

int n,h,t;
int min_n = INT_MAX;
int arr[100]={0,};
int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> h >> t;
    for(int i=0; i<n; i++)
    {
        int cnt;
        cin >> cnt;
        arr[i] = abs(h-cnt);
    }

    for(int i=0; i<n-t; i++)
    {
        int sum=0;
        for(int j=0; j<t; j++)
        {
            int k=i+j;
            sum+=arr[k];
        }
        if(min_n>sum)
        {
            min_n = sum;
        }
    }

    cout << min_n;
    return 0;
}