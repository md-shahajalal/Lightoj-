#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    double l,w,x1,ans1,x2,ans2;
    cin>>t;
    for(int i=1;i<=t;i++) {
        cin>>l>>w;
        x1=((4*(l+w))-sqrt((16*(l+w)*(l+w))-(48*w*l)))/24;
        x2=((4*(l+w))+sqrt((16*(l+w)*(l+w))-(48*w*l)))/24;
        ans1=(w-(2*x1))*(l-(2*x1))*x1;
        ans2=(w-(2*x2))*(l-(2*x2))*x2;
        //cout<<"Case "<<i<<": "<<ans<<endl;
        if(ans1-ans2>0)printf("Case %d: %0.10f\n",i,ans1);
        else printf("Case %d: %0.8f\n",i,ans2);
    }
    return 0;
}
