#include <bits/stdc++.h>

using namespace std;
int dp[2021][2021],path[2021][2021];
char a[2021],b[2021];
vector<char> ans;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int lena,lenb,i,j,ma=0,ei;
    cin >> a >> b;
    lena=strlen(a),lenb=strlen(b);
    for(i=1;i<=lena;i++)
    {
        for(j=1;j<=lenb;j++)
        {
            if(a[i-1]==b[j-1])
            {
                dp[i][j]=dp[i-1][j-1]+1;
                path[i][j]=1;
            }
            else if(dp[i-1][j]>=dp[i][j-1])
            {
                dp[i][j]=dp[i-1][j];
                path[i][j]=2;
            }
            else
            {
                dp[i][j]=dp[i][j-1];
                path[i][j]=3;
            }
        }
    }
    cout << dp[lena][lenb] << "\n";
    i=lena;j=lenb;
    if(dp[lena][lenb]==0)
    {
        cout << "No Roma word\n";
        exit(0);
    }
    while(i>0&&j>0)
    {
        if(path[i][j]==1)
        {
            ans.push_back(a[i-1]),i--,j--;
        }
        else if(path[i][j]==2) i--;
        else j--;
    }
    for(i=ans.size()-1;i>=0;i--)
        cout << ans[i];
    return 0;
}
