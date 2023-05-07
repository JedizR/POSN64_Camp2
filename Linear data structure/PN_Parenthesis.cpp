#include<bits/stdc++.h>

using namespace std;
stack<char> st;
char a[1010];
int main()
{
    int n,len,i,ch,cnt=0;
    cin >> n;
    cin >> a;
    for(i=0;i<n;i++)
    {
        if(a[i]=='(')
        {
            st.push(a[i]);
        }
        else if(!st.empty()&&st.top()=='('&&a[i]==')')
        {
            st.pop();
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}
