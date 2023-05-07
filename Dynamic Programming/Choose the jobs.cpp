#include <bits/stdc++.h>

using namespace std;
struct A{
    int s,e,w;
    bool operator<(const A&o)const{
    if(e!=o.e) return e<o.e;
    else if(s!=o.s) return s<o.s;
    }
}; A a[100100];
int dp[100100],b[100100];

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i].s >> a[i].e >> a[i].w;
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)
    {
        b[i]=a[i].e;
    }
    for(int i=1;i<=n;i++)
    {
        int ind=lower_bound(b+1,b+1+n,a[i].s)-b-1;
        dp[i]=max(dp[i-1],dp[ind]+a[i].w);
    }
    cout << dp[n] << "\n";
    return 0;
}
