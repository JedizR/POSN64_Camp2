#include <bits/stdc++.h>

using namespace std;
vector<int> g[300100];
int dp[300100];

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n,u,v,maxx=-1e9;
    cin >> n;
    for(int i=1;i<n;i++)
    {
        cin >> u >> v;
        if(u>v) swap(u,v);
        g[u].push_back(v);
    }
    for(int i=n;i>=1;i--)
    {
        for(auto x:g[i])
        {
            dp[i]=max(dp[i],dp[x]);
        }
        dp[i]++;
        maxx=max(maxx,dp[i]);
    }
    cout << maxx << "\n";
    return 0;
}
