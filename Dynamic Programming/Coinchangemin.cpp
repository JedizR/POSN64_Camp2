#include <bits/stdc++.h>

using namespace std;
int dp[1000010],coin[15];

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n,m;
    cin >> n >> m;
    for(int i=1;i<=n;i++)
    {
        cin >> coin[i];
    }
    for(int i=1;i<=m;i++)
    {
        dp[i]=1e9;
        for(int j=1;j<=n;j++)
        {
            if(i-coin[j]<0) continue;
            dp[i]=min(dp[i],dp[i-coin[j]]+1);
        }
    }
    if(dp[m]==1e9) cout << "0\n";
    else cout << dp[m] << "\n";
    return 0;
}
