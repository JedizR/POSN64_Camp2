#include <bits/stdc++.h>

using namespace std;
int u[300100],v[300100],color[300100];
vector<int> g[300100];
int check(int v,int col)
{
    if(color[v]!=0)
    {
        return (color[v]==col);
    }
    color[v]=col;
    for(auto x:g[v])
    {
        if(!check(x,3-col))
            return 0;
    }
    return 1;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n,m;
    cin >> n >> m;
    for(int i=1;i<=m;i++)
    {
        cin >> u[i] >> v[i];
    }
    int l=1,r=m,mid;
    while(l<r)
    {
        int ch=1;
        mid=(l+r)/2;
        for(int i=1;i<=mid;i++)
        {
            g[u[i]].push_back(v[i]),g[v[i]].push_back(u[i]);
        }
        for(int i=1;i<=n;i++)
        {
            if(color[i]==0)
            {
                if(!check(i,1))
                {
                    ch=0;
                    break;
                }
            }
        }
        for(int i=1;i<=mid;i++)
        {
            g[i].clear();
        }
        memset(color,0,sizeof color);
        if(ch) l=mid+1;
        else r=mid;
    }
    cout << l << "\n";
    return 0;
}
