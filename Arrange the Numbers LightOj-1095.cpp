
#include<bits/stdc++.h>
using namespace std;
#define cnst 1000000007
long long dp[1001][1001];
long long f[1001];
long long ncr(int n,int r)
{
    if(n==r)return 1;
    if(r==1)return n;
    if(dp[n][r]!=-1)return dp[n][r];
    return dp[n][r]=((ncr(n-1,r-1)%cnst)+(ncr(n-1,r)%cnst))%cnst;
}
void fact()
{
    f[0]=1;
    for(long long i=1;i<=1000;i++)
    {
        f[i]=i*f[i-1];
        if(f[i]>=cnst)f[i]%=cnst;
    }
}
int main()
{
    int t,n,m,k;
    scanf("%d",&t);
    memset(dp,-1,sizeof(dp));
    fact();
    for(int tc=1;tc<=t;tc++)
    {
        scanf("%d %d %d",&n,&m,&k);
        long long val1=ncr(m,k);
        long long val=f[n-k];
        long long pos=0;
        long long neg=0;
        for(int i=1;i<=m-k;i++)
        {
            long long x=((ncr(m-k,i)%cnst)*(f[n-k-i]%cnst))%cnst;
            if(i%2)neg=(neg+x)%cnst;
            else val=(val+x)%cnst;
        }
        neg*=-1;
        val=(val+neg);
        if(val<0)
        {
            while(val<0)
            {
                val+=cnst;
            }
        }
        val=(val*val1)%cnst;
        printf("Case %d: %lld\n",tc,val);
    }
}
