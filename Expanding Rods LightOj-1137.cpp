#include<bits/stdc++.h>
using namespace std;
#define eps 1e-8;
int main()
{
    int t;
    double n,l,c,l1;
    scanf("%d",&t);
    for(int tc=1;tc<=t;tc++)
    {
        int p=0;
      cin>>l>>n>>c;
        l1=(1.0+n*c)*l;
        //cout<<"l1 "<<l1<<endl;
        double b=0.0,e=l,mid,r,x;
        double cnst=l*0.5;
        while(e>b)
        {
            //cout<<"b "<<b<<" e "<<e<<endl;
            mid=(b+e)*0.5;
          //  cout<<"mid "<<mid<<endl;
            r=(((cnst*cnst)/(2*mid))+(mid*0.5));
            //cout<<"r "<<r<<endl;
            //cout<<"c "<<cnst<<endl;
            x=asin(cnst/r);

            x*=2*r;
             //printf(" x= %0.16f\n",x);
           if(x==l1)
           {
               printf("Case %d: %0.10f\n",tc,mid);
               p=1;
               break;
           }
           else if(x>l1)
            {
                e=mid;
            }
            else  b=mid;
        }
        if(!p)printf("Case %d: %0.10f\n",tc,0.0);
       // cout<<mid<<endl;
    }
    return 0;
}
