#include<bits/stdc++.h>
using namespace std;
#define CONST 1000003
#define MAX 1000000
long long fact[MAX+1];
long long x,y;
void factorial()
{
    fact[0]=1;

    for(int i=1;i<=MAX;i++) {
        fact[i]=(fact[i-1]*i)%CONST;
    }
}
void eEuclid(long long a,long long b)
{
    if(b==0) {

        x=1;
        y=0;
    }
    else {
        eEuclid(b,a%b);
        long long temp=x;
        x=y;
        y=temp-(y*(a/b));
    }
}
long long modinverse(long long a,long long b)
{
    eEuclid(a,b);

      return (x%b+b)%b;
}
int main()
{
    factorial();
    int t,n,k;
    cin>>t;
    for(int i=1;i<=t;i++) {
        scanf("%d %d",&n,&k);
        if(n==k || k==0) printf("Case %d: %d\n",i,1);
        else if(k==1)printf("Case %d: %d\n",i,n);

   else {
      long long factn=fact[n];
      long long factk=fact[k];
     long long factx=fact[(n-k)];

      long long val=((factk%CONST)*(factx%CONST))%CONST;

     long long result=(factn*modinverse(val,CONST))%CONST;

    printf("Case %d: %lld\n",i,result);

    }
    }

    return 0;
}
