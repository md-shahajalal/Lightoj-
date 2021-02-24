
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    double v1,v2,v3,a1,a2;
    cin>>t;
    for(int i=1;i<=t;i++) {
        cin>>v1>>v2>>v3>>a1>>a2;
        double d=((v1*v1)/(2*a1))+((v2*v2)/(2*a2));
        double t=max((v1/a1),(v2/a2));
        double s=v3*t;
        printf("Case %d: %0.10f %0.10f\n",i,d,s);
    }
    return 0;
}
