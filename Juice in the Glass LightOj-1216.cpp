#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,r1,r2,h,p;
    cin>>t;
    for(int i=1;i<=t;i++) {
        cin>>r1>>r2>>h>>p;
        double r=r2+(r1-r2)*((double)p/h);
        //cout<<r<<endl;
        double ans=(double)(1/3.0)*acos(-1)*((r*r)+(r2*r2)+(r*r2))*p;
        cout<<"Case "<<i<<": "<<setprecision(20)<<ans<<endl;
     //  printf("Case %d: %lf\n",i,ans);
    }
    return 0;
}
