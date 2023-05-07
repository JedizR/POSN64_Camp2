#include <bits/stdc++.h>

using namespace std;
priority_queue<double> s;
priority_queue<double,vector<double>,greater<double>> g;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n,i;
    double med,x;
    scanf("%d %lf",&n,&med);
    //cin >> n >> med;
    s.push(med);
    printf("%.1lf\n",med);
    //cout << fixed << setprecision(1) << med << "\n";
    for(i=1;i<n;i++)
    {
        scanf("%lf",&x);
        //cin >> x;
        if(s.size()>g.size())
        {
            if(x<med)
                g.push(s.top()),s.pop(),s.push(x);
            else
                g.push(x);
            med=(s.top()+g.top())/2.0;
        }
        else if(s.size()==g.size())
        {
            if(x<med)
                s.push(x),med=(double)s.top();
            else
                g.push(x),med=(double)g.top();
        }
        else
        {
            if(x>med)
            {
                s.push(g.top()),g.pop(),g.push(x);
            }
            else
            {
                s.push(x);
            }
            med=(s.top()+g.top())/2.0;
        }
        printf("%.1lf\n",med);
        //cout << fixed << setprecision(1) << med << "\n";
    }
    return 0;
}
