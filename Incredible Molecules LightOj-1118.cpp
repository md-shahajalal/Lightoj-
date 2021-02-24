#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    double x1,y1,x2,y2,r1,r2,g1,g2,c1,c2,X1,f1,f2,area;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>x1>>y1>>r1>>x2>>y2>>r2;
        double soto,boro;
        if(r1>=r2)
        {
            soto=r2;
            boro=r1;
        }
        else{
            soto=r1;
            boro=r2;
        }
        double dist_between_center=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
        if(dist_between_center>=(r1+r2))
        {
            area=0;
            printf("Case %d: %0.10f\n",i,area);
            continue;
        }
        else if(dist_between_center+soto<=boro)
        {
            area=acos(-1)*soto*soto;
            printf("Case %d: %0.10f\n",i,area);
            continue;
        }
        else{



        //X2=((g1-g2)*x2+(f1-f2)*y2+(c1-c2))/m;
       // cout<<"X1 "<<X1<<endl;

        //cout<<"X1 "<<X1<<endl;

       // cout<<"D "<<D<<endl;
        double p1=(((r1*r1)+(dist_between_center*dist_between_center)-(r2*r2))/(2*r1*dist_between_center));
        double p2=(((r2*r2)+(dist_between_center*dist_between_center)-(r1*r1))/(2*r2*dist_between_center));
        double theta1=2*acos(p1);
        double theta2=2*acos(p2);
        //cout<<"p1 "<<p1<<endl;
        //cout<<theta1<<" "<<theta2<<endl;

        area=(theta1*r1*r1*0.5)+(theta2*r2*r2*0.5);
        area-=((0.5*r1*r1*sin(theta1))+(0.5*r2*r2*sin(theta2)));
        //cout<<"area "<<area<<endl;
        printf("Case %d: %0.10f\n",i,area);
        }

    }
}
