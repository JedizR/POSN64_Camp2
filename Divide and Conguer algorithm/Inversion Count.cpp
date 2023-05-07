#include <bits/stdc++.h>

using namespace std;
long long a[100100],b[100100],ans=0;
void mergesort(long long l,long long r)
{
    if(l>=r) return ; //base case
    long long mid=(l+r)/2; //mid
    mergesort(l,mid);
    mergesort(mid+1,r);
    long long i=l,j=mid+1,k=l; //two pointer
    while(i<=mid&&j<=r)
    {
        if(a[i]<=a[j]) b[k++]=a[i++];
        else b[k++]=a[j++],ans+=mid-i+1;
    }
    while(i<=mid) b[k++]=a[i++]; //right end
    while(j<=r) b[k++]=a[j++]; //left end
    for(i=l;i<=r;i++) a[i]=b[i];
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    long long n,i;
    cin >> n;
    for(i=0;i<n;i++) cin >> a[i];
    mergesort(0,n-1);
    cout << ans << "\n";
    return 0;
}
