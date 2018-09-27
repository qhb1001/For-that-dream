#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<string>
#include<map>
#include<set>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
const double eps=1e-6;
int dcmp(double x)
{
    return fabs(x)<eps?0:(x>0?1:-1);
}
struct Point3
{
    double x,y,z;
    Point3(double x,double y,double z):x(x),y(y),z(z){}
    Point3() {}
    void in()
    {
        cin>>x>>y>>z;
    }
};
typedef Point3 Vector3;
Vector3 operator +(Vector3 A,Vector3 B)
{
    return Vector3(A.x+B.x,A.y+B.y,A.z+B.z);
}
Vector3 operator -(Vector3 A,Vector3 B)
{
    return Vector3(A.x-B.x,A.y-B.y,A.z-B.z);
}
Vector3 operator * (Vector3 A,double p)
{
    return Vector3(A.x*p,A.y*p,A.z*p);
}
Vector3 operator / (Vector3 A,double p)
{
    return Vector3(A.x/p,A.y/p,A.z/p);
}
bool operator == (Vector3 A,Vector3 B)
{
    return !dcmp(A.x-B.x)&&!dcmp(A.y-B.y)&&!dcmp(A.z-B.z);
}
double Dot(Vector3 A,Vector3 B)
{
    return A.x*B.x+A.y*B.y+A.z*B.z;
}
double Length(Vector3 A)
{
    return sqrt(Dot(A,A));
}
double Angle(Vector3 A,Vector3 B)
{
    return acos(Dot(A,B)/Length(A)/Length(B));
}
double DistanceToPlane(Point3 p,Point3 p0,Vector3 n)
{
    return fabs(Dot(p-p0,n)/Length(n));
}
Point3 GetPlaneProjection(Point3 p,Point3 p0,Vector3 n)
{
    double d=Dot(p-p0,n)/Length(n);
    return p+n*d;
}
Point3 LinePlaneIntersection(Point3 p1,Point3 p2,Point3 p3,Point3 p0,Vector3 n)
{
    Vector3 v=p2-p1;
    double t=(Dot(n,p0-p1)/Dot(n,p2-p1));
    return p1+v*t;
}
Vector3 Cross(Vector3 A,Vector3 B)
{
    return Vector3(A.y*B.z-A.z*B.y,A.z*B.x-A.x*B.z,A.x*B.y-A.y*B.x);
}
double  Area2(Point3 A,Point3 B,Point3 C)
{
    return Length(Cross(B-A,C-A));
}
bool PointInTri(Point3 P,Point3 P0,Point3 P1,Point3 P2)
{
    double area1=Area2(P,P0,P1);
    double area2=Area2(P,P1,P2);
    double area3=Area2(P,P2,P0);
    return dcmp(area1+area2+area3-Area2(P0,P1,P2))==0;
}
bool TriSegIntersection(Point3 P0,Point3 P1,Point3 P2,Point3 A,Point3 B,Point3 &P)
{
    Vector3 n=Cross(P1-P0,P2-P0);
    if(dcmp(Dot(n,B-A)==0)) return false;
    else
    {
        double t=Dot(n,P0-A)/Dot(n,B-A);
        if(dcmp(t)<0||dcmp(t-1)>0) return false;
        P=A+(B-A)*t;
        return PointInTri(P,P0,P1,P2);
    }
}
double DistaceToLine(Point3 P,Point3 A,Point3 B)
{
    Vector3 v1=B-A,v2=P-A;
    return Length(Cross(v1,v2)/Length(v1));
}
double DistaceToSegment(Point3 P,Point3 A,Point3 B)
{
    if(A==B) return Length(P-A);
    Vector3 v1=B-A,v2=P-A,v3=P-B;
    if(dcmp(Dot(v1,v2))<0) return Length(v2);
    else if(dcmp(Dot(v1,v3))>0) return Length(v3);
    else return Length(Cross(v1,v2))/Length(v1);
}
double Volume6(Point3 A,Point3 B,Point3 C,Point3 D)
{
    return Dot(D-A,Cross(B-A,C-A));
}
struct Face
{
    int v[3];
    Vector3 normal(Point3 *P)const
    {
        return Cross(P[v[1]]-P[v[0]],P[v[2]]-P[v[0]]);
    }
    int cansee(Point3 *P,int i) const
    {
        return Dot(P[i]-P[v[0]],normal(P))>0?1:0;
    }
};
vector<Face> CH3D(Point3 *P,int n)
{
    int vis[100][100];
    memset(vis,0,sizeof(vis));
    vector<Face> cur;
    cur.push_back((Face) {{0,1,2}});
    cur.push_back((Face) {{2,1,0}});
    for(int i=3;i<n;i++)
    {
        vector<Face> next;
        for(int j=0;j<cur.size();j++)
        {
            Face &f=cur[j];
            int res=f.cansee(P,i);
            if(!res) next.push_back(f);
            for(int k=0;k<3;k++) vis[f.v[k]][f.v[(k+1)%3]]=res;
        }
        for(int j=0;j<cur.size();j++)
            for(int k=0;k<3;k++)
            {
                int a=cur[j].v[k],b=cur[j].v[(k+1)%3];
                if(vis[a][b]!=vis[b][a]&&vis[a][b])
                next.push_back((Face) {{a,b,i}});
            }
            cur=next;
    }
    return cur;
}
double rand01() {return rand()/(double)RAND_MAX;}
double randeps() {return (rand01()-0.5)*eps;}
Point3 add_noise(Point3 p)
{
    return Point3(p.x+randeps(),p.y+randeps(),p.z+randeps());
}
bool TriTriIntersection(Point3 *T1,Point3 *T2)
{
    Point3 P;
    for(int i=0;i<3;i++)
    {
        if(TriSegIntersection(T1[0],T1[1],T1[2],T2[i],T2[(i+1)%3],P))
            return true;
        if(TriSegIntersection(T2[0],T2[1],T2[2],T1[i],T1[(i+1)%3],P))
            return true;
    }
    return false;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        Point3 T1[3],T2[3];
        for(int i=0;i<3;i++)
            T1[i].in();
        for(int i=0;i<3;i++)
            T2[i].in();
        printf("%s\n",TriTriIntersection(T1,T2)?"YES":"NO");
    }
    return 0;
}

