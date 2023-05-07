#include <bits/stdc++.h>
#define maxx 2147483647
using namespace std;
int n,color[105][105],dp[105][105];

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int i,k,j,l,temp,q,minn;
    cin >> q;
    while(q--)
    {
        cin >> n;
        for(i=0;i<n;i++)
            cin >> color[i][i];
        for(l=2;l<=n;l++)
        {
            for(i=0;i<n-l+1;i++)
            {
                j=i+l-1,minn=maxx;
                for(k=i;k<=j-1;k++)
                {
                    temp=dp[i][k]+dp[k+1][j]+color[i][k]*color[k+1][j];
                    if(temp<minn)
                    {
                        color[i][j]=(color[i][k]+color[k+1][j])%100;
                        minn =temp,dp[i][j]=minn;
                    }
                }
            }
        }
        cout << dp[0][n-1] << "\n";
    }
    return 0;
}
