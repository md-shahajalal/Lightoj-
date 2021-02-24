
#include<bits/stdc++.h>
using namespace std;
#define eps 0.00000001
int main()
{
    int t;
    double x,y,c;
    cin>>t;
    for(int i=1;i<=t;i++) {
        cin>>x>>y>>c;
        double lo=0,hi=min(x,y),mid;
        while(hi-lo>=eps) {
            mid=(lo+hi)/2.0;
            double h1=sqrt(abs((x*x)-(mid*mid)));
            double h2=sqrt(abs((y*y)-(mid*mid)));

            if(abs(((1/h1)+(1/h2))-(1/c))<=eps) {
                  //  cout<<h1 <<" " << h2<<" " <<c<<endl;
                cout<<"Case "<<setprecision(17)<<i<<": "<<mid<<endl;
                break;
            }
            if(((1/h1)+(1/h2))-(1/c)>eps)hi=mid;
            else lo=mid;
        }
    }
    return 0;
}
