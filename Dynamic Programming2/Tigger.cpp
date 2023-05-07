#include <bits/stdc++.h>

using namespace std;
int a[1010],dp[1010][1010],n;
int play(int now,int last)
{
    if(now<1||now>n) return 1e9;
    if(dp[now][last]) return dp[now][last];
    if(now==n) return a[now];
    return dp[now][last]=a[now]+min(play(now+last+1,last+1),play(now-last,last));
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for(int i=1;i<=n;i++)
        cin >> a[i];
    cout << play(2,1);
    return 0;
}
