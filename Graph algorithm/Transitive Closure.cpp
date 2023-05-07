#include <bits/stdc++.h>

using namespace std;
int a[510][510];

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin >> a[i][j];
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                a[i][j]=a[i][j]|(a[i][k]&a[k][j]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            printf((j!=n)?"%d ":"%d\n",a[i][j]);
    return 0;
}
