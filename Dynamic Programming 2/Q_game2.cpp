#include <bits/stdc++.h>

using namespace std;
int a[220][220],dpmx[220][220],dpmn[220][220];
void setIO();

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n,m,i,j;
    cin >> n >> m;
    for(i=n;i>=1;i--)
        for(j=1;j<=m;j++)
            cin >> a[i][j];
    for(i=1;i<=n;i++) dpmx[i][1]=dpmn[i][1]=dpmx[i-1][1]+a[i][1];
    for(i=1;i<=m;i++) dpmx[1][i]=dpmn[1][i]=dpmx[1][i-1]+a[1][i];
    for(i=2;i<=n;i++)
    {
        for(j=2;j<=m;j++)
        {
            dpmn[i][j]=min(dpmn[i-1][j],dpmn[i][j-1])+a[i][j];
            dpmx[i][j]=max(dpmx[i-1][j],dpmx[i][j-1])+a[i][j];
        }
    }
    cout << dpmx[n][m]-dpmn[n][m] << endl;
    return 0;
}
