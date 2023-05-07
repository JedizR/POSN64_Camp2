#include <bits/stdc++.h>

using namespace std;
string s;
unordered_map<long long,int> mp;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n,k;
    long long cnt=0,ans=0;
    cin >> n >> k >> s;
    mp[0]=0;
    for(long long i=0;i<n;i++)
    {
        if(s[i]=='O')
            cnt++;
        else
            cnt-=k;
        if(mp.find(cnt)==mp.end())
            mp[cnt]=i;
        else
            ans=max(ans,i-mp[cnt]);
    }
    cout << ans;
    return 0;
}
