 #include<bits/stdc++.h>
 using namespace std;
 #define cnst 100000007
 int n,k;
 int coin[100];
 int dp[10005];
 int ways()
 {
     for(int i=0;i<n;i++) {
        for(int j=1;j<=k;j++) {
            if(j>=coin[i])dp[j]=((dp[j]%cnst)+(dp[j-coin[i]]))%cnst;
        }
     }
     return dp[k];
 }
 int main()
 {
     int t;
     scanf("%d",&t);
     for(int i=1;i<=t;i++) {
        scanf("%d %d",&n,&k);
        for(int j=0;j<n;j++) {
            scanf("%d",&coin[j]);
        }
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        int val=ways();
        cout<<"Case "<<i<<": "<<val<<endl;
     }
     return 0;
 }
