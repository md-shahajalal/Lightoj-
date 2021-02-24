
#include<bits/stdc++.h>
using namespace std;
#define cnst 1000000
bool isprime[1000005];
vector<long long>v;
void sieve()
{
    int limit=floor(sqrt(cnst))+1;
    isprime[1]=true;
    v.push_back(2);

    for(int i=4;i<=cnst;i+=2)isprime[i]=true;

    for(int i=3;i<=cnst;i+=2) {
        if(!isprime[i]) {
            v.push_back(i);
             if(i<=limit) {
                for(int j=i*i;j<=cnst;j+=2*i) {
                    isprime[j]=true;
                }
             }
        }
    }
   // cout<<v.size()<<endl;

}
int main()

{
    sieve();
    int s=v.size();
    int t;
    long long n;
    cin>>t;
    for(int i=1;i<=t;i++) {
        scanf("%lld",&n);




         long long divisor=1;
        if(n<=1000000 && !isprime[n]) {
         printf("Case %d: %lld\n",i,divisor);
        }
        else {
        for(long long j=0;v[j]*v[j]<=n && j<s;j++) {
                long long c=0;
            while(n%v[j]==0) {
                n/=v[j];
                c++;
            }
        divisor*=(c+1);

        if(n<1000000 && !isprime[n] && n>0) {
            divisor*=2;
            n=1;
            break;
        }
        }
        if(n!=1) {
            divisor*=2;
        }
        printf("Case %d: %lld\n",i,divisor-1);
        }


    }

    return 0;
}
