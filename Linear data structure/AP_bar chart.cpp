#include <bits/stdc++.h>

using namespace std;
int l[100002],r[100002],n,q;
long long a[100002];

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> q;
    while(q--)
    {
        cin >> n;
        long long mx=0;
        for(int i=1;i<=n;i++)
        {
            cin >> a[i];
        }
        for(int i=1;i<=n;i++)
        {
            l[i]=i-1;
            while(l[i]>0&&a[i]<=a[l[i]])
                l[i]=l[l[i]];
        }
        for(int i=n;i>0;i--)
        {
            r[i]=i+1;
            while(r[i]<=n&&a[i]<=a[r[i]])
                r[i]=r[r[i]];
        }
        for(int i=1;i<=n;i++)
        {
            mx=max(mx,a[i]*(r[i]-l[i]-1));
        }
        cout << mx << "\n";
    }
    return 0;
}
