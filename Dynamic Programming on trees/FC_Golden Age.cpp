#include <bits/stdc++.h>

using namespace std;
int a[5010],dp[5010][5010];
int n,k,ans=0;
int play(int u,int k)
{
    if(u>n||k==0) return 0;
    if(dp[u][k]!=-1) return dp[u][k]; //memoization
    int ans=0;
    for(int i=0;k-i-1>=0;i++)
        ans=max(ans,a[u]+play(2*u,i)+play(2*u+1,k-i-1));
    return dp[u][k]=ans;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k;
    for(int i=1;i<=n;i++)
        cin >> a[i];
    memset(dp,-1,sizeof dp);
    for(int i=1;i<=n;i++)
        ans=max(ans,play(i,k));
    cout << ans << "\n";
    return 0;
}
