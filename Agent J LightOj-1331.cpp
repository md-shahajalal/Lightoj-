#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    double r1,r2,r3;
    cin>>t;
    for(int i=1;i<=t;i++) {
        cin>>r1>>r2>>r3;
        double l1=r1+r2;
        double l2=r1+r3;
        double l3=r2+r3;
        double val1=(l1*l1)+(l2*l2)-(l3*l3);
        double a=acos(val1/(2*l1*l2));
         double val2=(l3*l3)+(l2*l2)-(l1*l1);
         double b=acos(val2/(2*l3*l2));
          double val3=(l3*l3)+(l1*l1)-(l2*l2);
         double c=acos(val3/(2*l1*l3));

       //  cout<<a<<" "<<b<<" "<<c<<endl;

         double A=((a*(r1*r1))/2)+((b*(r3*r3))/2)+((c*(r2*r2))/2);
         double B=0.5*l1*l2*sin(a);
       printf("Case %d: %0.15f\n",i,B-A);



    }
    return 0;
}
