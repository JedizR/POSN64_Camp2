#include <bits/stdc++.h>

using namespace std;
int w[110],v[110],dp[110][10100];

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n,m;
    cin >> n >> m;
    for(int i=1;i<=n;i++)
    {
        cin >> v[i] >> w[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            if(j-w[i]<0) continue;
            dp[i][j]=max(dp[i][j],dp[i-1][j-w[i]]+v[i]);
        }
    }
    cout << dp[n][m] << "\n";
    return 0;
}
