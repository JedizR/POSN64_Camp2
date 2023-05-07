#include <bits/stdc++.h>

using namespace std;
vector< pair<int,int> > v[105];
int p[105];
int mic[105][105];
vector<int> child[105];
void dfs(int now)
{
    for(auto x:v[now])
    {
        if(p[x.first]==-1) //never contain any value
        {
            p[x.first]=x.second;
            child[now].push_back(x.first);
            dfs(x.first);
        }
    }
}
int play(int now,int K)
{
    if(mic[now][K]!=-1) return mic[now][K];
    if(K==0) return 0;
    if(child[now].size()==0) return p[now];
    if(child[now].size()==1)
        return mic[now][K]=play(child[now][0],K-1)+p[now];
    int Max=-1;
    for(int i=0;i<=K-1;i++)
        Max=max(Max,play(child[now][0],i)+play(child[now][1],K-i-1)+p[now]);
    return mic[now][K]=Max;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n,k;
    cin >> n >> k;
    memset(p,-1,sizeof p);
    memset(mic,-1,sizeof mic);
    for(int i=1;i<n;i++)
    {
        int s,w,e;
        cin >> s >> e >> w;
        v[s].push_back({e,w});
        v[e].push_back({s,w});
    }
    p[1]=0;
    dfs(1);
    cout << play(1,k+1);
    return 0;
}
