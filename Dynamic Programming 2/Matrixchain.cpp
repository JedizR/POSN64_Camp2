#include <bits/stdc++.h>

using namespace std;
int col[15],row[15],dp[15][15],path[15][15];
int play(int l,int r)
{
    if(dp[l][r]!=-1) return dp[l][r];
    if(l==r) return dp[l][r]=0;
    int minn=1e9;
    for(int i=l;i<r;i++)
    {
        int value=play(l,i)+play(i+1,r)+row[l]*col[i]*col[r];
        if(value<minn)
        {
            minn=value,path[l][r]=i;
        }
    }
    return dp[l][r]=minn;
}
void print(int l,int r)
{
    if(l==r)
    {
        cout << "A" << l;
        return;
    }
    cout << "(";
    print(l,path[l][r]);
    cout << " x ";
    print(path[l][r]+1,r);
    cout << ")";
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n;
    memset(dp,-1,sizeof dp);
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> row[i] >> col[i];
    }
    play(1,n);
    cout << dp[1][n] << "\n";
    print(1,n);
    return 0;
}
