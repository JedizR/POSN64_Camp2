#include <bits/stdc++.h>

using namespace std;
struct A{
    int u,v,w,money;
    bool operator<(const A&o)const{
    return money<o.money;
    }
};
struct B{
    int c,use;
    bool operator<(const B&o)const{
    return c<o.c;
    }
};
B a[500010]; int p[3010],ups[500010];
vector<A> path;
int find_root(int i)
{
    if(p[i]==i) return i;
    else return p[i]=find_root(p[i]);
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n,m,u,v,w,t,ru,rv,sum=0;
    cin >> n >> m;
    for(int i=1;i<=n;i++)
    {
        p[i]=i;
    }
    for(int i=1;i<=m;i++)
    {
        cin >> u >> v >> w >> t;
        if(t==1)
        {
            ru=find_root(u); rv=find_root(v);
            p[ru]=rv;
        }
        else
            path.push_back({u,v,w});
    }
    cin >> m;
    for(int i=1;i<=m;i++)
    {
        cin >> a[i].c >> a[i].use;
    }
    sort(a+1,a+1+m);
    ups[m]=a[m].c;
    for(int i=m-1;i>=1;i--)
    {
        if(a[i].use>a[i+1].use)
            a[i].use=a[i+1].use;
        ups[i]=a[i].c;
    }
    for(int i=0;i<path.size();i++)
    {
        int ind=lower_bound(ups+1,ups+1+m,path[i].w)-ups;
        path[i].money=a[ind].use;
    }
    sort(path.begin(),path.end());
    for(int i=0;i<path.size();i++)
    {
        ru=find_root(path[i].u); rv=find_root(path[i].v);
        if(ru!=rv)
        {
            p[ru]=rv;
            sum+=path[i].money;
        }
    }
    cout << sum << "\n";
    return 0;
}
/*6 8
0 1 19 0
1 2 50 1
1 3 5 0
2 3 18 0
0 4 32 0
3 4 22 0
2 5 70 0
4 5 20 1
8
5 60
50 200
75 350
20 100
40 145
15 50
35 150
8 60*/
