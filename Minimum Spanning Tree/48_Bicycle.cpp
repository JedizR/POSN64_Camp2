#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
map<int,int> mp;
int p[50050];
struct A{
    int u,v,w;
    bool operator<(const A&o)const{
        return w>o.w;
    }
}a[70070];
int fr(int u)
{
    return p[u]==u?u:p[u]=fr(p[u]);
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int q,num,n,m,u,v,i,ru,rv;
    cin >> q;
    while(q--)
    {
        int ans=0,all=0;
        cin >> n >> m;
        for(i=1;i<=n;i++)
        {
            cin >> num;
            mp[num]=i;
            p[i]=i;
        }
        for(i=0;i<m;i++)
        {
            cin >> u >> v >> a[i].w;
            a[i].u = mp[u];
            a[i].v = mp[v];
            all+=a[i].w;
        }
        sort(a,a+m);
        for(i=0;i<m;i++)
        {
            ru=fr(a[i].u),rv=fr(a[i].v);
            if(ru==rv) continue;
            p[ru] = rv;
            ans+=a[i].w;
        }
        cout << all-ans << endl;
    }
    return 0;
}
