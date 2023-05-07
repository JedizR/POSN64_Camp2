#include <bits/stdc++.h>

using namespace std;
long long a[100100];

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    long long n,q,i,num;
    cin >> n >> q;
    for(i=1;i<=n;i++)
    {
        cin >> num;
        a[i]=a[i-1]+num; //quicksum
    }
    for(i=n-1;i>=1;i--)
    {
        a[i]=min(a[i],a[i+1]);
    }
    while(q--)
    {
        cin >> num;
        cout << upper_bound(a+1,a+n+1,num)-a-1 << "\n";
    }
    return 0;
}
/*
5 3
10 20 -10 30 60
31
52
9
*/
