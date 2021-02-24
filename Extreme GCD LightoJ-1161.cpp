#include<bits/stdc++.h>
 using namespace std;
 long long nc4(long long n)
 {
     return n*(n-1)*(n-2)*(n-3)/24;
 }
 int main()
 {
     int t,n,k;
     cin>>t;
     for(int tc=1;tc<=t;tc++)
     {
         cin>>n;
         long long gcd[10001];
         memset(gcd,0,sizeof(gcd));
         int maxi=0;
         while(n--)
         {
             cin>>k;
             for(int i=1;i*i<=k;i++)
             {
                 if(k%i==0)
                 {
                     gcd[i]++;
                     //cout<<"i "<<i<<endl;
                 }
                 if(k%i==0 and k/i !=i) {
                    gcd[k/i]++;
                   // cout<<"k/i "<<k/i<<endl;
                 }
             }
             maxi=max(maxi,k);
         }
       //  for(int i=1;i<=maxi;i++)cout<<"gcd["<<i<<"] "<<gcd[i]<<endl;
         for(int i=maxi;i>=1;i--)
         {
              gcd[i]=nc4(gcd[i]);
             for(int j=i+i;j<=maxi;j+=i)
             {
                 gcd[i]-=gcd[j];
             }
           //  cout<<gcd[i]<<endl;
         }
         cout<<"Case "<<tc<<": "<<gcd[1]<<endl;

     }
     return 0;
 }
