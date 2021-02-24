#include<bits/stdc++.h>
using namespace std;
#define cnst 10056
long long ncr[1001][1001];
long long dp[1001];
long long func(int n,int r)
{
    if(r==1)return n;
    if(r==0)return 1;
    if(n==r)return 1;
    if(ncr[n][r]!=-1)return ncr[n][r];
    return ncr[n][r]=((func(n-1,r-1)%cnst)+(func(n-1,r)%cnst))%cnst;
}
long long give_ans(int n)
{
     if(n==1)return 1;
     if(n==0)return 1;
     if(dp[n]!=-1)return dp[n];
     long long x=0;
     for(int i=1;i<=n;i++) {
            x=x%cnst + (func(n,i)%cnst) *(give_ans(n-i)%cnst);
            x%=cnst;
     }
     return dp[n]=x;
}

int main()
{
    int t,n;
    scanf("%d",&t);
    memset(ncr,-1,sizeof(ncr));
    memset(dp,-1,sizeof(dp));
    for(int tc=1;tc<=t;tc++)
    {
       scanf("%d",&n);
       printf("Case %d: %lld\n",tc,give_ans(n));
    }
    return 0;
}
