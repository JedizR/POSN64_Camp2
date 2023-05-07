#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    long long q,s,m;
    cin >> q;
    while(q--)
    {
        cin >> s >> m;
        long long l=0,r=s/2,ch=1;
        while(l<=r)
        {
            long long mid=(l+r)/2;
            long long b=s-mid;
            if(mid*b>m||mid*b/b!=mid)
            {
                r=mid-1;
            }
            else if(mid*b<m)
            {
                l=mid+1;
            }
            else
            {
                cout << mid << " " << b << "\n";
                ch=0;
                break;
            }
        }
        if(ch)
            cout << "No answer\n";
    }
    return 0;
}
