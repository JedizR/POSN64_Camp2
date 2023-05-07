#include <bits/stdc++.h>

using namespace std;
long long a[500100],st[500100],dp[500100];

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    long long n,i,sum=0;
    cin >> n;
    for(i=1;i<=n;i++)
        cin >> a[i];
    for(i=1;i<=n;i++)
        cin >> st[i];
    sort(a+1,a+1+n);
    sort(st+1,st+1+n,greater<int>());
    for(i=1;i<=n;i++)
        dp[i]=a[i]+st[i];
    sort(dp+1,dp+1+n);
    for(i=2;i<=n;i++)
    {
        sum+=abs(dp[i]-dp[i-1]);
    }
    cout << sum;
    return 0;
}
