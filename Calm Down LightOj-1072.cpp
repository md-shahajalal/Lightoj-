
#include<bits/stdc++.h>
using namespace std;
int main()
{
    double R,a,r;
    int t,n;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>R>>n;
        a=sin((acos(-1))/n);
        r=(R*a)/(1+a);
        printf("Case %d: %0.10lf\n",i,r);
    }
    return 0;
}
