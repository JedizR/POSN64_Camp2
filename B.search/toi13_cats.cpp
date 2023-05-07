#include <bits/stdc++.h>

using namespace std;
long long a[2000100];
stack<long long> st;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    long long n,i,l,r,mid,ch,now;
    cin >> n;
    for(i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    l=0,r=1e18;
    while(l<r)
    {
        mid=(l+r)/2,ch=0;
        for(i=1;i<=n;i++)
        {
            if(a[i]<=mid) continue;
            st.push(a[i]);
        }
        while(!st.empty())
        {
            now=st.top();
            st.pop();
            if(now!=st.top())
            {
                ch=1; break;
            }
            else
            {
                st.pop();
            }
        }
        while(!st.empty()) st.pop();
        if(ch) l=mid+1;
        else r=mid;
    }
    cout << l;
    return 0;
}
