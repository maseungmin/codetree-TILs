#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <cmath>

using namespace std;

int n,s;
int min_n=INT_MAX;
int arr[100]={0,}; //입력배열

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> s;
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }

    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            int sum=0;
            for(int k=0; k<n; k++)
            {
                if(k!=i&&k!=j)
                    sum+=arr[k];
            }
            int cnt = abs(s-sum);
            if(min_n>cnt)
            {
                min_n=cnt;
            }
        }
    }

    cout << min_n;
    return 0;
}