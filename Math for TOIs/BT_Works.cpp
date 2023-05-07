#include <bits/stdc++.h>

using namespace std;
const int mod=1e9+7;
int dp[1010][1010];

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int q,n,m,i,d,j,ans;
    cin >> q;
    dp[0][0]=1;
    for(i=1;i<=1000;i++)
    {
        dp[i][0]=1;
        for(j=1;j<=i;j++)
        {
            dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
            dp[i][j]%=mod;
        }
    }
    while(q--)
    {
        cin >> n >> m >> d;
        if(d*(m-1)+m>n) ans=0;
        else ans=dp[n-(d*(m-1))][m];
        cout << ans;
    }
    return 0;
}
