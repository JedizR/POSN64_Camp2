#include <bits/stdc++.h>

using namespace std;
int a[5101]={1};

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int i,j,n,k;
    scanf("%d %d",&n,&k);
    //cin >> n >> k;
    for(i=1;i<=n;i++)
    {
        for(j=n;j>=i;j--)
        {
            a[j]+=a[j-i];
            a[j]%=k;
        }
    }
    printf("%d\n",a[n]-1);
    //cout << a[n]-1 << "\n";
    return 0;
}
