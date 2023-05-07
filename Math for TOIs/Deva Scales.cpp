#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n,now,countt=0,sum=0,v=1;
    cin >> n;
    while(n)
    {
        now=n%3;
        n/=3;
        if(now==1)
        {
            countt++,sum+=v;
        }
        else if(now==2)
        {
            countt++,n++;
        }
        v*=3;
    }
    cout << countt << sum;
    return 0;
}
