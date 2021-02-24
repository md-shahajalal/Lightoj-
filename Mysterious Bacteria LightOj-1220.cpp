#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    long long x;
    scanf("%d",&t);
    for(int tc=1;tc<=t;tc++)
    {
        scanf("%lld",&x);
        int w=0;
        if(x<0)w=1;
        x=abs(x);
        long long root=sqrt(x);
        int ind=1;
        for(int i=2;i<=root;i++)
        {
            int cnt=0;
            long long a=x;
            if(a%i==0)
            {
                while(a%i==0)
                {
                    cnt++;
                    a/=i;
                }
                if(a==1 && !w)
                {
                    printf("Case %d: %lld\n",tc,cnt);
                    ind=0;
                    break;
                }
                else if(w)
                {
                    if(cnt%2==0)continue;
                    else
                    {
                        printf("Case %d: %lld\n",tc,cnt);
                        ind=0;
                        break;
                    }
                }
            }
        }
        if(ind)printf("Case %d: %d\n",tc,1);
    }
    return 0;
}
