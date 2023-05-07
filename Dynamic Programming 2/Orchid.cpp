 #include <bits/stdc++.h>

using namespace std;
int a[1000010],dp[1000010];

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n,maxx=0;
    cin >> n;
    for(int i=1;i<=n;i++)
        cin >> a[i];
    for(int i=1;i<=n;i++)
    {
        int idx=upper_bound(dp,dp+maxx,a[i])-dp;
        if(idx==maxx) maxx++;
        dp[idx]=a[i];
    }
    cout << n-maxx << "\n";
    return 0;
}
