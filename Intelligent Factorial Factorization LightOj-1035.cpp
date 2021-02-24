#include<bits/stdc++.h>
using namespace std;
int prime[]={2,3,5,7,11,13,17,19,23,29,31,37,39,41,43,47,53,59,61,67,71,73,79,83,89,91,97};
int main()
{
    int t,n;
    cin>>t;
    for(int i=1;i<=t;i++) {
        scanf("%d",&n);
         map<int,int>mp;
         int x=-12;

        for(int k=2;k<=n;k++) {
                int val=k;
        for(int j=0;j<27 && prime[j]<=val;j++) {

              int cnt=0;
                while(val%prime[j]==0) {
                    val/=prime[j];
                    cnt++;
                }
                if(cnt!=0) {
                        mp[prime[j]]+=cnt;
                        if(prime[j]>x)x=prime[j];

                }

             }
        }
        map<int,int>::iterator it;

        printf("Case %d: %d = ",i,n);

    for(it=mp.begin();it!=mp.end();it++) {
        if(it->first !=x)printf("%d (%d) * ",it->first,it->second);
        else printf("%d (%d)\n",it->first,it->second);

    }

    }
    return 0;
}
