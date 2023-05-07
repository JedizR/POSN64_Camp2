#include <bits/stdc++.h>
#include <cstdio>

using namespace std;
char aa[50][50];
int visit[50][50],roomCount,exitDepth,m,n,l,a,b,c,d;
int DIR[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int onBoard(int ni, int nj)
{
    if((ni>=0)&&(ni<m)&&(nj>=0)&&(nj<n)) return 1;
    return 0;
}

void play(int i,int j,int depth)
{
    visit[i][j]=1;
    roomCount++;
    if((i==c)&&(j==d))
        exitDepth =depth;
    for(int dir=0;dir<4;dir++)
    {
        int ni=i+DIR[dir][0];
        int nj=j+DIR[dir][1];
        if(onBoard(ni,nj)&&aa[ni][nj]=='.'&&(!visit[ni][nj]))
        {
            play(ni,nj,depth+1);
        }
    }
}
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int Q,i,j;
    cin >> Q;
    while(Q--)
    {
        cin >> m >> n >> l;
        for(i=0;i<m;i++)
        {
            cin >> aa[i];
        }
        cin >> a >> b >> c >> d;
        a--,b--,c--,d--;
        for(i=0;i<m;i++)
            for(j=0;j<n;j++)
                visit[i][j]=0;
        roomCount=0,exitDepth=-1;
        play(a,b,0);
        if(exitDepth==-1)
            cout << "-1\n";
        else if(exitDepth>l)
            cout << "-1\n";
        else
        {
            int extraRoom = roomCount - exitDepth - 1;
            if(l-exitDepth-extraRoom*2>=0)
                cout << roomCount << "\n";
            else
            {
                int lleft=l-exitDepth;
                cout << 1+exitDepth+(lleft/2) << "\n";
            }
        }
    }
    return 0;
}
