#include<bits/stdc++.h>
 #define n 5000000
using namespace std;
int phi[n+1];
unsigned long long cumulative[n+1];
void sievephi()
{
    for(int i=2;i<=n;i++)
    {
        phi[i]=i;
    }
    for(int i=2;i<=n;i++) {
            if(phi[i]==i) {
            for(int j=i;j<=n;j+=i) {
                phi[j]-=phi[j]/i;
            }
    }
        }
    for(int i=2;i<=n;i++) {
    cumulative[i]=phi[i];
    cumulative[i]*=phi[i];
    cumulative[i]+=cumulative[i-1];
    }
}
int main()
{
    sievephi();
    int t,a,b;
    scanf("%d",&t);
    for(int i=1;i<=t;i++) {
        scanf("%d %d",&a,&b);
        printf("Case %d: %llu\n",i,cumulative[b]-cumulative[a-1]);
    }
    return 0;
}

