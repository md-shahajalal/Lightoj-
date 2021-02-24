#include<bits/stdc++.h>
using namespace std;
void result(long long w,int i)
{
    long long val=1;
    while(w%2==0) {
        val*=2;
        w/=2;
    }
    cout<<"Case "<<i<<": "<<w<<" "<<val<<endl;
}
int main()
{
    int t;
    long long w;
    scanf("%d",&t);
    for(int i=1;i<=t;i++) {
        scanf("%lld",&w);
        if(w%2)cout<<"Case "<<i<<": "<<"Impossible"<<endl;
        else result(w,i);
    }
    return 0;
}

