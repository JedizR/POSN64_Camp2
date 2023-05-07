#include <bits/stdc++.h>

using namespace std;
int a[1010],b[1010],days[1010][1010],mini[1010][1010];

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n,m;
    cin >> m >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++) cin >> b[i];
    for(int i=1;i<=n;i++)
    {
        if(mini[i-1][0]+b[i]<=m)
            mini[i][0]=mini[i-1][0]+b[i],days[i][0]=days[i-1][0];
        else
            mini[i][0]=b[i],days[i][0]=days[i-1][0]+1;
    }
    for(int j;j<=n;j++)
    {
        if(mini[0][j-1]+a[j]<=m)
            mini[0][j]=mini[0][j-1]+a[j],days[0][j]=days[0][j-1];
        else
            mini[0][j]=a[j],days[0][j]=days[0][j-1]+1;
    }
    int minna,daya,dayb,minnb;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(mini[i-1][j]+b[i]<=m)
                minna=mini[i-1][j]+b[i],daya=days[i-1][j];
            else minna=b[i],daya=days[i-1][j]+1;
            if(mini[i][j-1]+a[j]<=m)
                minnb=mini[i][j-1]+a[j],dayb=days[i][j-1];
            else minnb=a[j],dayb=days[i][j-1]+1;
            if(daya==dayb) days[i][j]=daya,mini[i][j]=min(minna,minnb);
            else if(daya<dayb) days[i][j]=daya,mini[i][j]=minna;
            else if(dayb<daya) days[i][j]=dayb,mini[i][j]=minnb;
        }
    }
    cout << days[n][n]+1 << "\n" << mini[n][n] << "\n";
    return 0;
}
