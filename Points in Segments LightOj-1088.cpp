 #include<bits/stdc++.h>
 using namespace std;
 #define cons 100001
 int v[cons];
 int main()
 {
     int t,a,b,n,q;
     scanf("%d",&t);
     for(int i=1;i<=t;i++)
     {
         scanf("%d %d",&n,&q);
         for(int j=0;j<n;j++)
         {
             scanf("%d",&v[j]);
         }
         cout<<"Case "<<i<<":"<<endl;
         for(int j=1;j<=q;j++)
         {
             scanf("%d %d",&a,&b);
              int *low=lower_bound(v,v+n,a);
              int *high=upper_bound(v,v+n,b);
              printf("%d\n",(high-v)-(low-v));
         }
     }
     return 0;
 }

