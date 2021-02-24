#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
     double s,x,r,a,b;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
         scanf("%lf : %lf", &a, &b);
        r=sqrt((a*a)+(b*b))/2.0;
        s=r*acos(1.0-((b*b)/(2.0*r*r)));
        x=400/((2.0*s)+(2.0*a));
        printf("Case %d: %0.10lf %0.10lf\n",i,a*x,b*x);
    }
    return 0;
}

