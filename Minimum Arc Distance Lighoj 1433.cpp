#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,o1,o2,a1,a2,b1,b2;
    cin>>t;
    for(int i=1;i<=t;i++) {
        cin>>o1>>o2>>a1>>a2>>b1>>b2;
        double x=sqrt(((o1-a1)*(o1-a1))+((o2-a2)*(o2-a2)));
        double y=sqrt(((o1-b1)*(o1-b1))+((o2-b2)*(o2-b2)));
        double z=sqrt(((b1-a1)*(b1-a1))+((b2-a2)*(b2-a2)));
        double val=(x*x)+(y*y)-(z*z);
        double angle=acos(val/(2*x*y));
        printf("Case %d: %0.6f\n",i,angle*x);
    }
    return 0;
}
