#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int i=1;i<=t;i++) {
            int p=0;
        string a;
        int b;
        cin>>a>>b;
        long long x=0;
        if(a[0]=='-')p=1;
        for(int j=p;j<a.size();j++) {
            long long val=x*10+(a[j]-'0');

           // if(val>b)cout<<val<<endl;
            //cout<<val<<endl;
            x=val%b;
        }
        if(x==0)cout<<"Case "<<i<<": divisible"<<endl;
        else cout<<"Case "<<i<<": not divisible"<<endl;
    }
    return 0;
}
