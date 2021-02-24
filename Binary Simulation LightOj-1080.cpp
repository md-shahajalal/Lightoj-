
#include<bits/stdc++.h>
using namespace std;
struct info
{
    int val=0;
    int prop=0;
}tree[500005];
void init(char str[],int node,int b,int e)
{
    if(b==e)
    {
        tree[node].val=str[b]-'0';
       // cout<<"node "<<node<<"b ="<<b<<endl;
        return;
    }
    int left=node<<1;
    int right=left+1;
    int mid=(b+e)>>1;
    init(str,left,b,mid);
    init(str,right,mid+1,e);
}
void update(int node,int b,int e,int x,int y)
{
    if(b>y || e<x)return;
    if(b>=x && e<=y)
    {
        tree[node].prop+=1;
       // cout<<"node "<<node<<" b "<<b<<" e "<<e<<endl;
        return;
    }
    int left=node<<1;
    int right=left+1;
    int mid=(b+e)>>1;
    update(left,b,mid,x,y);
    update(right,mid+1,e,x,y);
}
int query(int node,int b,int e,int x,int carry)
{
    if(x>e || x<b)return 0;
    if(x==b && x==e)
    {
        //cout<<"carry "<<carry<<endl;
        carry+=tree[node].prop;
       // cout<<"b "<<b <<" e "<<e<<" carry "<<carry<<endl;
        if(!(carry%2))return tree[node].val;
         else {
            if(tree[node].val)return 0;
            return 1;
         }
    }
    int left=node<<1;
    int right=left+1;
    int mid=(b+e)>>1;
    int p1=0,p2=0;
   // cout<<"b "<<b <<" e "<<e<<" carry "<<carry<<endl;
    p1=query(left,b,mid,x,carry+tree[node].prop);
    p2=query(right,mid+1,e,x,carry+tree[node].prop);
    if(p1 || p2)return 1;
    return 0;
}
int main()
{
   // ios_base::sync_with_stdio(false);
    int t,n,q;
    char ch;
    char str[100001];
    int x,y;
    cin>>t;
    for(int tc=1;tc<=t;tc++) {
             scanf(" %s",&str);
            scanf("%d",&q);
           n=strlen(str);
          // cout<<n<<endl;
            for(int i=0;i<=5*n;i++)
            {
                tree[i].val=0;
                tree[i].prop=0;
            }
            init(str,1,0,n-1);
           // for(int i=1;i<=100;i++)cout<<"node "<<i<<": "<<tree[i].val<<" "<<tree[i].prop<<endl;
            printf("Case %d:\n",tc);
            while(q--)
            {
              scanf(" %c %d",&ch,&x);

               if(ch=='I')
               {
                  scanf("%d",&y);
                   update(1,0,n-1,x-1,y-1);

               }
               else {
                int ans=query(1,0,n-1,x-1,0);
                printf("%d\n",ans);
               }
            }
    }
    return 0;
}
