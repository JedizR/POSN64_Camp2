#include <bits/stdc++.h>

using namespace std;
struct A{
    int w,ind;
    bool operator<(const A&o)const{
    return w<o.w;
    }
}; A now;
int mark[100100];
priority_queue<A> pq;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n,q,num;
    cin >> n >> q;
    for(int i=1;i<=n;i++)
    {
        cin >> num;
        pq.push({num,i});
    }
    for(int i=1;i<=q;i++)
    {
        int ans=0;
        cin >> num;
        while(!pq.empty())
        {
            now=pq.top();
            if(now.w>num)
            {
                if(mark[now.ind]!=i&&mark[now.ind]!=0)
                {
                    pq.pop(); continue;
                }
                if(!mark[now.ind+1]&&now.ind+1<=n) mark[now.ind+1]=i,ans++;
                if(!mark[now.ind-1]&&now.ind-1>=1) mark[now.ind-1]=i,ans++;
                if(!mark[now.ind]) mark[now.ind]=i,ans++;
                pq.pop();
            }
            else break;
        }
        cout << ans;
    }
    return 0;
}
