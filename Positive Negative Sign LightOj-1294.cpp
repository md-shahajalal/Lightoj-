#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    long long n,m;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>n>>m;
        long long val=m*(n/2);
        cout<<"Case "<<i<<": "<<val<<endl;
    }
    return 0;
}
