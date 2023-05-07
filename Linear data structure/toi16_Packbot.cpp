#include <bits/stdc++.h>

using namespace std;
int mul[7]={0,104,108,116};
stack<int> ans,a;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int len,opr1,i,opr2,now;
    char str[20000];
    cin >> str;
    len=strlen(str);
    for(i=0;i<len;i++)
    {
        if(isalpha(str[i]))
            ans.push(20);
        else if(str[i]=='[')
            a.push(-1);
        else if(str[i]==']')
        {
            while(!a.empty()&&a.top()!=-1)
            {
                opr2=ans.top();
                ans.pop();
                opr1=ans.top();
                ans.pop();
                ans.push((opr2+opr1)*mul[a.top()]/100);
                a.pop();
            }
            a.pop();
        }
        else if(isdigit(str[i]))
        {
            now=str[i]-'0';
            while(!a.empty()&&now<=a.top())
            {
                opr2=ans.top();
                ans.pop();
                opr1=ans.top();
                ans.pop();
                ans.push((opr2+opr1)*mul[a.top()]/100);
                a.pop();
            }
            a.push(now);
        }
    }
    while(!a.empty())
    {
        opr2=ans.top();
        ans.pop();
        opr1=ans.top();
        ans.pop();
        ans.push((opr2+opr1)*mul[a.top()]/100);
        a.pop();
    }
    cout << ans.top() << "\n";
    return 0;
}
