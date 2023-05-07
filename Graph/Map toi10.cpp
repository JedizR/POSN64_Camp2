#include <bits/stdc++.h>

using namespace std;
int u[40100],d[40100],l[40100],r[40100];
int a[420][420];
void play(int i,int j,int now)
{
    a[i][j]=now;
    if(u[now]!=-1&&a[i-1][j]==-1)
        play(i-1,j,u[now]);
    if(d[now]!=-1&&a[i+1][j]==-1)
        play(i+1,j,d[now]);
    if(l[now]!=-1&&a[i][j-1]==-1)
        play(i,j-1,l[now]);
    if(r[now]!=-1&&a[i][j+1]==-1)
        play(i,j+1,r[now]);
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n,m,i,j,k,o;
    cin >> n >> m;
    char opr;
    memset(l,-1,sizeof l),memset(r,-1,sizeof r);
    memset(d,-1,sizeof d),memset(u,-1,sizeof u),memset(a,-1,sizeof a);
    for(i=0;i<n*m-1;i++)
    {
        cin >> j >> opr >> k;
        if(opr=='U')
            u[k]=j,d[j]=k;
        else if(opr=='L')
            l[k]=j,r[j]=k;
    }
    play(n,m,0);
    for(i=0;i<415;i++)
    {
        for(j=0;j<415;j++)
        {
            if(a[i][j]!=-1)
            {
                for(k=i;k<i+n;k++)
                {
                    for(o=j;o<j+m;o++)
                    {
                        cout << a[k][o];
                    }
                    cout << "\n";
                }
                return 0;
            }
        }
    }
    return 0;
}
