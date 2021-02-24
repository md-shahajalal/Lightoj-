#include<bits/stdc++.h>
using namespace std;
vector<int>prime;
#define cnst 10000000
bool isprime[10000005];


void sieve()
{
    int limit=floor(sqrt(cnst))+1;
    isprime[1]=true;
    prime.push_back(2);

    for(int i=4;i<=cnst;i+=2)isprime[i]=true;

    for(int i=3;i<=cnst;i+=2) {
        if(!isprime[i]) {

        prime.push_back(i);
            if(i<=limit) {
            for(long long j=i*i;j<=cnst;j+=2*i)  {
                 isprime[j]=true;
            }
        }
        }
    }

}
int  main()
{
    sieve();
    int t,n;
    cin>>t;
    for(int i=1;i<=t;i++) {
            int counter=0;
        scanf("%d",&n);

        for(int j=0;prime[j]<=n/2;j++) {
            if(!isprime[n-prime[j]])counter++;
        }
    printf("Case %d: %d\n",i,counter);
    }
    return 0;
}
