#include <bits/stdc++.h>

using namespace std;
char str[1010];
int mic[1010][1010];

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int len,maxLength=1,i,start=0,k,j;
    cin >> str;
    len = strlen(str);
    for(i=0;i<len;i++)
    {
        mic[i][i]=1;
    }
    for(i=len-1;i>0;i--)
    {
        if(str[i]==str[i-1])
        {
            mic[i-1][i]=1;
            start=i-1;
            maxLength=2;
        }
    }
    for(k=3;k<=len;++k)
    {
        for(i=0;i<len-k+1;++i)
        {
            j=i+k-1;
            if(mic[i+1][j-1]&&str[i]==str[j])
            {
                mic[i][j]=1;
                if(k>maxLength)
                {
                    start=i;
                    maxLength=k;
                }
            }
        }
    }
    for(i=start;i<=start+maxLength-1;++i)
    {
        cout << str[i];
    }
    cout << "\n";
    return 0;
}
