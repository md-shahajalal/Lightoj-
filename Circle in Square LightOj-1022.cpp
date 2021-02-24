#include<bits/stdc++.h>
using namespace std;
int main()
{
    double r;
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++) {
        scanf("%lf",&r);
         double val=((2*r)*2*r)-(2*acos(0.0)*r*r);
         cout<<"Case "<<i<<": ";
        printf("%0.2lf\n",val);
    }
}
