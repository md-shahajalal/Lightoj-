#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,b;
    double val;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        scanf("%d %d",&n,&b);
        if(n==0)printf("Case %d: 1\n",i);
      else {
      val=(n*log10(n/exp(1))/log10(b))+(0.5*log10(2*acos(-1)*n)/log10(b));
        printf("Case %d: %d\n",i,(int)val+1);
    }
    }
    return 0;
}
