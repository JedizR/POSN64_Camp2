#include <bits/stdc++.h>

using namespace std;
char a[1100],b[1100];
int dp[1100][1100];

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int q,lena,lenb;
    cin >> q;
    while(q--)
    {
        cin >> a+1 >> b+1;
        lena=strlen(a+1),lenb=strlen(b+1);
        for(int i=1;i<=lenb;i++)
        {
            dp[0][i]=i;
        }
        for(int i=1;i<=lena;i++)
        {
            dp[i][0]=i;
        }
        for(int i=1;i<=lena;i++)
        {
            for(int j=1;j<=lenb;j++)
            {
                if(a[i]==b[j])
                    dp[i][j]=dp[i-1][j-1];
                else dp[i][j]=min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1]))+1;
            }
        }
        cout << dp[lena][lenb] << "\n";
        memset(dp,0,sizeof dp);
    }
    return 0;
}
