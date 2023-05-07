#include <bits/stdc++.h>

using namespace std;
int dp[300];

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n,k,i,w,j,sum,mark;
    cin >> n >> k;
    for(i=1;i<(1<<k);i++) dp[i]=1e9;
    for(i=1;i<=n;i++)
    {
        cin >> w;
        for(j=0,sum=0;j<k;j++)
        {
            cin >> mark;
            if(mark) sum+=(1<<j);
        }
        for(j=0;j<(1<<k);j++)
            dp[j|sum]=min(dp[j|sum],dp[j]+w);
    }
    cout << dp[(1<<k)-1] << "\n";
    return 0;
}
