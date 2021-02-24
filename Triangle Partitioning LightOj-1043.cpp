#include<bits/stdc++.h>
using namespace std;
#define eps 0.00000000001
int main()
{
    int t;
    double ab,ac,bc,r,x;
    cin>>t;
    for(int i=1;i<=t;i++) {
        cin>>ab>>ac>>bc>>r;
        double lo=0,hi=ab;

        while(hi-lo>=eps) {
            double mid=(lo+hi)/2.0;
          // cout<<mid<<endl;
            if(!mid)break;
            if(abs((r/(r+1))-((mid*mid)/((ab)*(ab))))<=eps)
            {
              //  cout<<"ratio ->"<<r/(r+1)<<endl<<"Result ->"<<(mid*mid)/((ab)*(ab))<<endl;
                cout<<"Case "<<i<<": "<<setprecision(17)<<mid<<endl;
                break;
            }
            if((r/(r+1))-((mid*mid)/((ab)*(ab)))>eps){
                lo=mid;
            }
            else hi=mid;
        }
    }
    return 0;
}

