#include<bits/stdc++.h>
using namespace std;
map<char,int>mp;
struct node
{
    int endmark;
    int c;
    int l;
    node* next[4];
    node()
    {
        l=0;
        endmark=0;
        c=0;
        for(int i=0;i<4;i++)
        {
            next[i]=NULL;
        }
    }
}* root;

int ans;
void init(char str[],int len)
{
    node* curr=root;
    for(int i=0;i<len;i++)
    {
        int id=mp[str[i]];
        int lx=curr->l;
        if(curr->next[id]==NULL)
        {
          curr->next[id]=new node();
        }
         curr=curr->next[id];
         curr->c+=1;
         curr->l=lx+1;
         //cout<<"ID "<<id<<" c "<<curr->c<<" l "<<curr->l<<endl;
    }
    curr->endmark=1;
}
int give_ans(node* curr)
{
    ans=max(ans,(curr->c) * (curr->l));
   // cout<<"ans "<<ans<<endl;
    for(int i=0;i<4;i++)
    {
        if(curr->next[i])
        {
            ans=max(ans,give_ans(curr->next[i]));
        }
    }
    return ans;
}
void del(node* curr)
{
    for(int i=0;i<4;i++)
        if(curr->next[i])del(curr->next[i]);
    delete(curr);
}
int main()
{
    int t,n;
    scanf("%d",&t);
    mp['A']=0;
    mp['C']=1;
    mp['G']=2;
    mp['T']=3;
    for(int tc=1;tc<=t;tc++)
    {
        scanf("%d",&n);
        char str[50];
        root=new node();
        ans=0;
        while(n--)
        {
            scanf(" %s",&str);
            init(str,strlen(str));
        }
        int ans1=give_ans(root);
        printf("Case %d: %d\n",tc,ans1);
        del(root);
    }
    return 0;
}
