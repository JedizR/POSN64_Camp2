#include <bits/stdc++.h>

using namespace std;
int dp[10010][10010];
char a[10010],b[10010];

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int lena,lenb,i,j,ma=0,ei;
    cin >> a >> b;
    lena=strlen(a);
    lenb=strlen(b);
    for(i=1;i<=lena;i++)
    {
        for(j=1;j<=lenb;j++)
        {
            if(a[i-1]==b[j-1])
            {
                dp[i][j]=dp[i-1][j-1]+1;
                if(dp[i][j]>ma)
                {
                    ma=max(ma,dp[i][j]);
                    ei=i;
                }
            }
            else dp[i][j]=0;
        }
    }
    for(i=ei-ma;i<ei;i++)
    {
        cout << a[i];
    }
    return 0;
}
