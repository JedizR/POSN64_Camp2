#include <bits/stdc++.h>

using namespace std;
struct A{
    int w,v,d,i;
    bool operator<(const A&o)const{
        return w>o.w;
    }
};
struct B{
    int w,v,d,i;
    bool operator<(const B&o)const{
        return d>o.d;
    }
};
priority_queue<A> hat;
priority_queue<B> tim;
int mark[200100];

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n,m,i,opr,j,ch,w,v,d,x;
    cin >> n >> m;
    for(i=0;i<n+m;i++)
    {
        cin >> opr;
        if(opr==1)
        {
            cin >> j;
            if(j==1)
            {
                cin >> w >> v;
                hat.push({w,v,200100,i});
            }
            if(j==2)
            {
                cin >> w >> v >> d;
                hat.push({w,v,d,i});
            }
            if(j==3)
            {
                cin >> w >> v >> d >> x;
                hat.push({w,v,d,i});
                tim.push({x,v,d,i});
            }
        }
        else
        {
            while(!tim.empty()&&tim.top().d<=i)
            {
                hat.push({tim.top().w,tim.top().v,200100,tim.top().i});
                tim.pop();
            }
            ch=1;
            while(!hat.empty())
            {
                if(hat.top().d<=i||mark[hat.top().i])
                {
                    hat.pop(); continue;
                }
                mark[hat.top().i]=1;
                cout << hat.top().v << "\n";
                hat.pop(); ch=0;
                break;
            }
            if(ch)
                cout << "0" << "\n";
        }
    }
    return 0;
}
