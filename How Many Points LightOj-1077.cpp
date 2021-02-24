
#include<bits/stdc++.h>
using namespace std;
long long gcd(long long a,long long b)
{
    if(a%b==0)return b;
    return gcd(b,a%b);
}
int main()
{
    long long t,x1,y1,x2,y2;
    scanf("%lld",&t);
    for(int tc=1;tc<=t;tc++)
    {
        scanf("%lld %lld %lld %lld",&x1,&y1,&x2,&y2);
        long long dx=x1-x2;
        long long dy=y1-y2;
        if(dx<0)dx*=-1;
        if(dy<0)dy*=-1;
        if(dx==0 && dy==0)
        {
             printf("Case %d: 1\n",tc);

        }
        else if(dx==0)
        {
            printf("Case %d: %lld\n",tc,dy+1);

        }
         else if(dy==0)
        {
            printf("Case %d: %lld\n",tc,dx+1);

        }
        else {
        long long val=gcd(dx,dy);
        long long ans=1+val;
        printf("Case %d: %lld\n",tc,ans);
        }
    }
    return 0;
}
