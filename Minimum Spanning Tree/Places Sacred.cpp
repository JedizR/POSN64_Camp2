#include <bits/stdc++.h>

using namespace std;
struct A{
    int u,v,w;
    bool operator<(const A&o)const{
        return w>o.w;
    }
}a[1000010];
int p[200020];
int fr(int u)
{
    return p[u]==u?u:p[u]=fr(p[u]); //if abb.
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n,m,ru,rv;
    long long ans=0;
    cin >> n >> m;
    for(int i=1;i<=n;i++)
    {
        p[i]=i;
    }
    for(int i=0;i<m;i++)
        cin >> a[i].u >> a[i].v >> a[i].w;
    sort(a,a+m);
    for(int i=0;i<m;i++)
    {
        ru=fr(a[i].u);
        rv=fr(a[i].v);
        if(ru==rv) continue;
        p[ru]=rv;
        ans+=a[i].w-1;
    }
    cout << ans << endl;
    return 0;
}
