#include <bits/stdc++.h>

using namespace std;
struct A{
    int a,b,c;
    bool operator<(const A&o)const{
        if(c<o.c) return true;
        return false;
    }
};
A e[1000000];
vector<int> node[1010];
int pa[1010],a[1010][1010];
int f(int i)
{
    if(i==pa[i]) return i;
    return pa[i]=f(pa[i]);
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n,i,j,k,x,y,Q,Ma,ans;
    cin >> Q;
    while(Q--)
    {
        cin >> n;
        for(i=1;i<=n;i++)
        {
            pa[i]=i;
            for(j=1;j<=n;j++)
            {
                cin >> a[i][j];
            }
        }
        k=0,Ma=0,ans=1;
        for(i=1;i<n;i++)
        {
            for(j=i+1;j<=n;j++)
            {
                e[k].a=i;
                e[k].b=j;
                e[k].c=a[i][j];
                k++;
            }
        }
        sort(e,e+k);
        for(i=0;i<k;i++)
        {
            x=f(e[i].a);
            y=f(e[i].b);
            if(x!=y)
            {
                pa[x]=y;
                node[e[i].a].push_back(e[i].b);
                node[e[i].b].push_back(e[i].a);
            }
        }
        for(i=1;i<=n;i++)
            if((int)node[i].size()>Ma)
                Ma=node[i].size(),ans=i;
        cout << ans << " " << Ma << "\n";
        for(i=1;i<=n;i++)
            node[i].clear();
        memset(a,0,sizeof a);
    }
    return 0;
}
/*
1
4
0 7 12 8
7 0 5 1
12 5 0 6
8 1 6 0
*/
