
#include<bits/stdc++.h>
using namespace std;
int dp[10000];
int give_result(int k)
{
    if(k==0)return 1;
    if(dp[k]!=-1)return dp[k];
    return  dp[k]=(1+((k%10000)*(give_result(k-1))%10000)%10000);
}
int main()
{
    int t,k;
    scanf("%d",&t);
    memset(dp,-1,sizeof(dp));
    dp[1]=2;
    for(int tc=1;tc<=t;tc++)
    {
        scanf("%d",&k);
        int m=k;
        k%=10000;
        int ans=give_result(k)%10000;
     //   cout<<ans<<endl;
        if(ans/10==0 && m>=7)printf("Case %d: 000%d\n",tc,ans);
        else if(ans/100==0 && m>=7)printf("Case %d: 00%d\n",tc,ans);
        else if(ans/1000==0 && m>=7)printf("Case %d: 0%d\n",tc,ans);
        else printf("Case %d: %d\n",tc,ans);

    }
    return 0;
}
