#include<bits/stdc++.h>
using namespace std;
int m,n;
int odd,even;
long long give_gcd(long long a,long long b)
{
    if(a%b==0)return b;
    return give_gcd(b,a%b);
}
long long solve(int arr[],int power)
{
    for(int counter=1;counter<power;counter++)
    {
        long long gcd;
        long long lcm=0;
        for(int i=0;i<m;i++)
        {
            if(counter & (1<<i))
            {
               if(!lcm)lcm=arr[i];
               else {
                long long val=lcm*arr[i];
                gcd=give_gcd(lcm,arr[i]);
                lcm=(val/gcd);
               }
            }
            // cout<<lcm<<endl;
        }
        if (__builtin_popcount(counter) & 1){
            odd+=(n/lcm);
        }
        else even+=(n/lcm);
    }
    return odd-even;
}
int main()
{
    int t,a;
    cin>>t;
    for(int tc=1;tc<=t;tc++)
    {
        odd=0;
        even=0;
        cin>>n>>m;
        int arr[m];
        for(int i=0;i<m;i++)
            cin>>arr[i];
        int power=1<<m;
        int ans=solve(arr,power);
        cout<<"Case "<<tc<<": "<<n-ans<<endl;
    }
    return 0;
}

