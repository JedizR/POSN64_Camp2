#include <bits/stdc++.h>

using namespace std;
int a[1010],length[1010],from[1010],keep[1010];

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int N,maxx=0,att=0,i,j;
    cin >> N;
    for(i=0;i<N;i++)
    {
        cin >> a[i];
        length[i]=1;
        from[i]=i;
    }
    for(i=1;i<N;i++)
    {
        for(j=0;j<i;j++)
        {
            if(a[i]>a[j]&&length[i]<length[j]+1)
            {
                length[i]=length[j]+1,from[i]=j;
            }
        }
    }
    for(i=0;i<N;i++)
    {
        if(length[i]>maxx)
            maxx=length[i],att=i;
    }
    cout << maxx << "\n";
    for(i=0;i<maxx;i++)
    {
        keep[i]=a[att],att=from[att];
    }
    for(i=maxx-1;i>=0;i--)
        if(i==0)
        {
            cout << keep[i] << "\n";
        }
        else
        {
            cout << keep[i] << " ";
        }
    return 0;
}
