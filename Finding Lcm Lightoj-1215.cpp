#include<bits/stdc++.h>
using namespace std;


int main()
{
    int t;
    scanf("%d",&t);
    long long a,b,l;
    for(int i=1;i<=t;i++) {
            int ind=0;
        scanf("%lld %lld %lld",&a,&b,&l);
        long long val=((a*b)/__gcd(a,b));
        vector<long long>v;
        for(long long j=1;j*j<=l;j+=1) {
            if(l%j==0) {
                    v.push_back(l/j);
                    //cout<<l/j<<endl;
                if((j*val)/__gcd(j,val)==l) {
                    printf("Case %d: %lld\n",i,j);
                    ind=1;
                    break;
                }
            }
        }
        int sz=v.size();
        //cout<<sz<<endl;
        if(!ind) {
    for(long long j=sz-1;j>=0;j--)
        if(l%v[j]==0) {
                if((v[j]*val)/__gcd(v[j],val)==l) {
                    printf("Case %d: %lld\n",i,v[j]);
                    ind=1;
                    break;
                }
            }
    }
    if(!ind) {
         printf("Case %d: impossible\n",i);
    }
    }
    return 0;
}

