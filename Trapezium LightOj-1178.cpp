
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    double a,b,c,d;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>a>>b>>c>>d;
        double x=(d*d-b*b+(a-c)*(a-c))/(2*abs(a-c));
        double h=sqrt(d*d-x*x);
        double ans=0.5*(a+c)*h;
        cout<<"Case "<<i<<": "<<setprecision(17)<<ans<<endl;
    }
        return 0;
}
