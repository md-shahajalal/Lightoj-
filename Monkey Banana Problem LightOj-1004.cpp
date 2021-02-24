#include<bits/stdc++.h>
using namespace std;
#define sc scanf
#define pf printf
#define mset(a,s) memset(a,s,sizeof(a))
#define long long ll
int dp[200][101];
int main()
{
    int t,n,a;
    sc("%d",&t);
    for(int k=1;k<=t;k++)
    {
        sc("%d",&n);
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=i;j++) {
                sc("%d",&a);
                dp[i][j]=a;
            }
        }
           for(int i=n+1;i<2*n;i++) {
            for(int j=1;j<=2*n-i;j++) {
                sc("%d",&a);
                dp[i][j]=a;
            }
        }
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=i;j++) {
                dp[i][j]+=max(dp[i-1][j-1],dp[i-1][j]);
            }
        }
        for(int i=n+1;i<2*n;i++) {
            for(int j=1;j<=2*n-i;j++) {
                dp[i][j]+=max(dp[i-1][j],dp[i-1][j+1]);
            }
        }
        pf("Case %d: %d\n",k,dp[2*n-1][1]);
    }
    return 0;
}
