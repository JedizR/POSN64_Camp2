#include <bits/stdc++.h>

using namespace std;
struct A{
    int u,v,w;
    bool operator<(const A&o)const{
    return w>o.w;
    }
};
A a[1000010]; int p[2510];
int find_root(int i)
{
    if(p[i]==i) return i;
    else return p[i]=find_root(p[i]);
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n,m,u,v,w,st,en;
    double pp;
    cin >> n >> m;
    for(int i=1;i<=n;i++)
    {
        p[i]=i;
    }
    for(int i=1;i<=m;i++)
    {
        cin >> a[i].u >> a[i].v >> a[i].w;
    }
    cin >> st >> en >> pp;
    sort(a+1,a+1+m);
    int minn=1e9;
    for(int i=1;i<=m;i++)
    {
        int ru=find_root(a[i].u);
        int rv=find_root(a[i].v);
        if(ru!=rv)
        {
            p[ru]=rv;
            minn=min(minn,a[i].w);
        }
        if(p[find_root(st)]==p[find_root(en)])
        {
            double res=pp/(minn-1);
            //printf("%.0lf\n",ceil(res));
            cout << fixed << setprecision(0) << ceil(res) << "\n";
            break;
        }
    }
    return 0;
}
