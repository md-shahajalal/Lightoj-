#include<bits/stdc++.h>
using namespace std;
int decimal(int a)
{
    int i=0;
    int r;
    int deci=0;
    while(a) {
        r=a%10;
        a/=10;
        if(r==1)deci+=r*pow(2,i);
        ++i;
    }
    //cout<<deci<<endl;
    return deci;

}
int main()
{
    int t,a,b,c,d;
    int w,x,y,z;
    char ch;
    cin>>t;
    for(int i=1;i<=t;i++) {
        cin>>a>>ch>>b>>ch>>c>>ch>>d;
        cin>>w>>ch>>x>>ch>>y>>ch>>z;
       // cout<<decimal(w)<<" "<<decimal(x)<<" "<<decimal(y)<<" "<<decimal(z)<<endl;
        if(decimal(w)==a && decimal(x)==b && decimal(y)==c && decimal(z)==d){
            cout<<"Case "<<i<<": "<<"Yes"<<endl;
        }
        else cout<<"Case "<<i<<": "<<"No"<<endl;
    }
    return 0;
}
