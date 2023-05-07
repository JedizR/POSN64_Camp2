#include <bits/stdc++.h>

using namespace std;
queue<int> qu;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int q;
    cin >> q;
    while(q--)
    {
        string s;
        int k,sz=0,cnt=0,mx=-1;
        cin >> s >> k;
        int len = s.size();
        for(int i=0;i<len;i++)
        {
            if(s[i]=='A')
            {
                qu.push(1);
                sz++;
            }
            else if(s[i]=='B'&&cnt<k)
            {
                qu.push(0);
                sz++,cnt++;
            }
            else
            {
                while(qu.front()!=0)
                {
                    qu.pop();
                    sz--;
                }
                qu.pop();
                qu.push(0);
            }
            mx=max(mx,sz);
        }
        cout << mx << endl;
        while(!qu.empty())
            qu.pop();
    }
    return 0;
}
