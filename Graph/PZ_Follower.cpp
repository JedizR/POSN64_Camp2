#include <bits/stdc++.h>

using namespace std;
int mark[1024][105];
struct A{
    int v,w;
};
queue <A> q;
vector <A> pa[105];

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n,m,s,e,b,c,d,v,w,i,t;
    cin >> t;
    while(t--)
    {
        cin >> n >> m >> s >> e;
        while(m--)
        {
            cin >> b >> c >> d;
            pa[b].push_back({c,d});
            pa[c].push_back({b,d});
        }
        q.push({s,0});
        while(!q.empty())
        {
            v=q.front().v;
            w=q.front().w;
            q.pop();
            if(mark[w][v])
                continue;
            mark[w][v]=1;
            for(i=0;i<pa[v].size();i++)
            {
                q.push({pa[v][i].v,w^pa[v][i].w});
            }
        }
        for(i=0;i<1024;i++)
        {
            if(mark[i][e])
            {
                cout << i << "\n";
                break;
            }
        }
        for(i=1;i<=n;i++)
        {
            pa[i].clear();
        }
        memset(mark,0,sizeof(mark));
    }
    return 0;
}
