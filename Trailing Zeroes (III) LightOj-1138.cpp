#include<bits/stdc++.h>
using namespace std;
int k;
bool check(int val,int n)
{
    int f=5,c=0;
    while(val>=f) {
        c+=val/f;
        f*=5;
    }
    if(c==n)k=1;
    return (c>=n);
}
int trailing_zero(int n)
{
    int lo=0,high=5*n+1,mid;
    while(lo<high){
        mid=(lo+high)>>1;
        if(check(mid,n)) {
            high=mid;
        }
        else lo=mid+1;
    }
    return lo;
}
int main()
{
    int t,n;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        scanf("%d",&n);
        k=0;
       int val= trailing_zero(n);
       if(!k)cout<<"Case "<<i<<": "<<"impossible"<<endl;
       else cout<<"Case "<<i<<": "<<val<<endl;
    }
    return 0;
}
