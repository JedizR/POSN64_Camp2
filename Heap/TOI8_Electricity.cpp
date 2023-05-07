//toi8 electric
#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> PI;
priority_queue<PI> h;
int dp[500100];

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n,k,i,num;
    cin >> n >> k >> i;
    dp[1]=i;
    h.push({-i,1});
    for(int i=2;i<=n;i++)
    {
        cin >> num;
        while(!h.empty()&&i-h.top().second > k)
        {
            h.pop();
        }
        dp[i]=-(h.top().first) + num;
        h.push({-dp[i],i});
    }
    cout << dp[n] << "\n";
    return 0;
}
