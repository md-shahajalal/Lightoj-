#include<bits/stdc++.h>
using namespace std;
int main()
{
    std :: ios :: sync_with_stdio(false);
    int t,n;
    int arr[50];
    cin>>t;
    map<int,int>mp;
    for(int i=1;i<=t;i++) {
        cin>>n;
        for(int j=0;j<n;j++) {
            cin>>arr[j];
            mp[arr[j]]++;
        }
        long long ans=0;
    map<int,int> ::iterator it;

    for(it=mp.begin();it!=mp.end();it++){
     int val1=it->first;
     int val2=it->second;

     if(val2%(val1+1)==0)ans+=((val1+1)*(val2/(val1+1)));
     else ans+=((val1+1)*((val2/(val1+1))+1));

    // cout<<val1<<"  "<<val2<<endl;
    }
    cout<<"Case "<<i<<": "<<ans<<endl;
    mp.clear();
    }
    return 0;
}

