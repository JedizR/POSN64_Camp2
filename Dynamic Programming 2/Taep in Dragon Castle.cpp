#include <bits/stdc++.h>

using namespace std;
const int N = 25;
int a[N][N], dp[N][N];

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int q;
    cin >> q;
    while(q--)
    {
        int r,c,k,p;
        memset(a,0,sizeof a);
        cin >> r >> c >> k >> p;
        for(int i=1;i<=r;i++)
        {
            for(int j=1;j<=c;j++)
            {
                a[i][j]=1;
            }
        }
        k--;
        while(k--)
        {
            for(int i=1;i<=r;i++)
                for(int j=1;j<=c;j++)
                    dp[i][j]=(a[i][j]+a[i+1][j]+a[i][j+1]+a[i-1][j]+a[i][j-1])%p;
            for(int i=1;i<=r;i++)
                for(int j=1;j<=c;j++)
                    a[i][j]=dp[i][j];
        }
        int ans=0;
        for(int i=1;i<=r;i++)
            for(int j=1;j<=c;j++)
                ans+=a[i][j],ans%=p;
        cout << ans << "\n";
    }
    return 0;
}
