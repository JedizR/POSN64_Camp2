#include <bits/stdc++.h>

using namespace std;      //|
vector<int> g[30],ans;    //v check a-z
int in[30],mark[30][30],markout[30],ways[30];
char a[110][50];
queue<int> que;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n,lenA,lenB,now,possible=0,ch=0;
    cin >> n;
    for(int i=1;i<=n;i++)
        cin >> a[i];
    for(int i=1;i<n;i++)
    {
        lenA=strlen(a[i]),lenB=strlen(a[i+1]);
        for(int j=0;j<min(lenA,lenB);j++)
        {
            markout[a[i][j]-'a']=1;
            if((j>=1&&a[i][j-1]!=a[i+1][j-1])||a[i][j]==a[i+1][j]) continue;
            if(a[i][j]!=a[i+1][j])
            {
                int first=a[i][j]-'a',second=a[i+1][j]-'a';
                if(mark[second][first])
                {
                    cout << "!\n";
                    return 0;
                }
                mark[first][second]=1;
                g[first].push_back(second);
                in[second]++;
                break;
            }
        }
    }
    for(int i=0;i<26;i++)
    {
        if(!in[i]&&markout[i])
        {
            que.push(i);
        }
    }
    while(!que.empty())
    {
        if(que.size()>1) ch=1;
        now=que.front(); que.pop();
        ans.push_back(now);
        for(auto x:g[now])
        {
            in[x]--;
            if(!in[x])
                que.push(x);
        }
    }
    if(ch) cout << "?\n";
    else
        for(auto x:ans) printf("%c",x+'a');
    return 0;
}
