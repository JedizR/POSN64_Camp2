#include <bits/stdc++.h>

using namespace std;
int aa[100100],p[100100];
int fr(int i){
    if(p[i]==i) return i;
    return p[i]=fr(p[i]);
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int i,n,m,a,b,pa,pb;
    cin >> n >> m;
    for(i=1;i<=n;i++)
    {
        p[i]=i;
    }
    for(i=1;i<=n;i++)
    {
        cin >> aa[i];
    }
    while(m--)
    {
        cin >> a >> b;
        pa=fr(a),pb=fr(b);
        if(pa==pb)
            cout << "-1" << "\n";
        else
        {
            if(aa[pa]>aa[pb])
            {
                cout << pa << "\n";
                aa[pa]+=aa[pb]/2;
                p[pb]=pa;
            }
            else if(aa[pb]>aa[pa])
            {
                cout << pb << "\n";
                aa[pb]+=aa[pa]/2;
                p[pa]=pb;
            }
            else if(pa<pb)
            {
                cout << pa << "\n";
                aa[pa]+=aa[pb]/2;
                p[pb]=pa;
            }
            else
            {
                cout << pb << "\n";
                aa[pb]+=aa[pa]/2;
                p[pa]=pb;
            }
        }
    }

    return 0;
}
