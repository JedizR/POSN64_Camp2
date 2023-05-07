#include <bits/stdc++.h>

using namespace std;
int a[3030],b[3030],dp[3030][3030];

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n,i,j;
    cin >> n;
    for(i=1;i<=n;i++)
        cin >> a[i];
    for(i=1;i<=n;i++)
        cin >> b[i];
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(a[i]==b[j])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    cout << dp[n][n];
    return 0;
}
