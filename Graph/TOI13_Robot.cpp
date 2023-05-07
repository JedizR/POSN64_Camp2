#include <bits/stdc++.h>

using namespace std;
struct A{
    int i,j,w;
};
queue <A> bfs;
int di[4]={1,-1,0,0},dj[4]={0,0,1,-1},dis[2050][2050];
char a[2050][2050];

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int r,c,i,j,cnt=0,w,k,ii,jj,ans1=0,ans2=0;
    cin >> r >> c;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            cin >> a[i][j];
            dis[i][j]=-1;
            if(a[i][j]=='X')
            {
                bfs.push({i,j,0}),dis[i][j]=0;
                a[i][j]='E';
            }
        }
    }
    while(!bfs.empty())
    {
        i=bfs.front().i,j=bfs.front().j,w=bfs.front().w;
        bfs.pop();
        if(a[i][j]=='A')
            ans1++,ans2+=w*2;
        for(k=0;k<4;k++)
        {
            ii=i+di[k];
            jj=j+dj[k];
            if(ii<0||jj<0||ii>=r||jj>=c) continue;
            if(dis[ii][jj]!=-1||a[ii][jj]=='W') continue;
            bfs.push({ii,jj,w+1});
            dis[ii][jj]=dis[i][j]+1;
        }
    }
    cout << ans1 << " " <<ans2;
    return 0;
}
