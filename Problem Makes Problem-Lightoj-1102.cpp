
#include<bits/stdc++.h>
using namespace std;

#define cnst 1000000007
int fact[2*1000001];
long long mod(long long x,int a,int m)
{
    if(a==0)return 1%m;
     long long p=mod(x,a>>1,m);
    p=(p*p)%m;
    if(a%2==1)p=(p*x)%m;
    return p;
}
void cal_fact()
{
    fact[0]=1;
    long long x;
    for(int i=1;i<=2000000;i++) {
            x=fact[i-1];
        x=(x*i)%cnst;
        fact[i]=x;
    }
}
long long solve(int n,int r)
{
    long long val1=1,val2=1,val3=1;

    val1=fact[n];
    val2=fact[r];
    val3=fact[n-r];
    val2=(val2*val3)%cnst;

    val2=mod(val2,cnst-2,cnst);
   // cout<<val2<<endl;
    return (val1*val2)%cnst;
}
int main()
{
    int t,n,k;
    scanf("%d",&t);
    cal_fact();
    for(int tc=1;tc<=t;tc++)
    {
        scanf("%d %d",&n,&k);
       // memset(dp,-1,sizeof(dp));
        long long ans=solve(n+k-1,k-1);
        printf("Case %d: %lld\n",tc,ans);
    }
    return 0;
}
