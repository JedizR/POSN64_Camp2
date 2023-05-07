#include <bits/stdc++.h>

using namespace std;
priority_queue <long long,vector<long long>,greater<long long>> pq;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int q;
    cin >> q;
    while(q--)
    {
        while(!pq.empty())
            pq.pop();
        int n,k;
        cin >> n >> k;
        long long last,val;
        cin >> last;
        for(int i=2;i<=n;i++)
        {
            long long val;
            cin >> val;
            pq.emplace(val-last);
            last=val;
        }
        long long ans=0;
        while(pq.size()>=k)
        {
            ans+=pq.top();
            pq.pop();
        }
        cout << ans << "\n";
    }

    return 0;
}
