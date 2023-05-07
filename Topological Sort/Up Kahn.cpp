#include <bits/stdc++.h>

using namespace std;
int deg[100100];
vector<int> g[100100],ans;
priority_queue<int,vector<int>,greater<int>> heap; //min heap

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int q,n,k,i,u,v,idx;
    cin >> q;
    while(q--)
    {
        cin >> n >> k;
        for(i=1;i<=k;i++)
        {
            cin >> u >> v;
            g[u].push_back(v);
            deg[v]++;
        }
        for(i=1;i<=n;i++) if(!deg[i]) heap.push(i);
        while(!heap.empty())
        {
            idx=heap.top(); heap.pop(); //heap !empty then pop
            ans.push_back(idx);
            for(auto x:g[idx])
            {
                deg[x]--;
                if(!deg[x]) heap.push(x);
            }
        }
        if(ans.size()==n)
        {
            cout << "Yes ";
            for(i=0;i<ans.size();i++) cout << ans[i] << " ";
            cout << "\n";
        }
        else cout << "No" << "\n";
        ans.clear();
        for(i=1;i<=n;i++) g[i].clear();
        memset(deg,0,sizeof deg); //clear heap n graph
    }
    return 0;
}
