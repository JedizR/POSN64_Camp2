#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pi pair<int,int>
#define pb push_back
#define all(x) x.begin(),x.end()
char a[1010];int dp[1010][1010];
int play(int l,int r){
    if(dp[l][r]!=-1) return dp[l][r];
    if(l>=r) return dp[l][r]=0;
    int maxx=INT_MIN;
    for(int i=l;i<r;i++){
        int value = play(l,i)+play(i+1,r);
        maxx = max(value,maxx);
    }
    if(a[l] == a[r]){
        int value = play(l+1,r-1)+1;
        maxx = max(value,maxx);
    }
    return dp[l][r]=maxx;
}
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n;cin >> n;
    memset(dp,-1,sizeof dp);
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    play(1,n);
    cout << dp[1][n];
    return 0;
}
