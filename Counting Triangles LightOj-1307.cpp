#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,a;

    cin>>t;
    for(int i=1;i<=t;i++) {
             vector<int>arr;
        cin>>n;
        for(int j=0;j<n;j++) {
            cin>>a;
        arr.push_back(a);
        }
        sort(arr.begin(),arr.end());
        long long c=0;
        for(int j=0;j<n;j++)
        {
            for(int k=j+1;k<n;k++) {
                int val=arr[j]+arr[k];
            vector<int>:: iterator it;
                it=lower_bound(arr.begin(),arr.end(),val);
                int x=it-arr.begin()-1;
               // cout<<x<<endl;

                c+=max(0,x-k);
            }
        }
       cout<<"Case "<<i<<": "<<c<<endl;
    }
    return 0;
}

