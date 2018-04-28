{\rtf1\ansi\ansicpg936\cocoartf1561\cocoasubrtf100
{\fonttbl\f0\fnil\fcharset0 Menlo-Regular;\f1\fswiss\fcharset0 Helvetica;}
{\colortbl;\red255\green255\blue255;\red0\green116\blue0;\red255\green255\blue255;\red100\green56\blue32;
\red196\green26\blue22;\red170\green13\blue145;\red0\green0\blue0;\red28\green0\blue207;}
{\*\expandedcolortbl;;\csgenericrgb\c0\c45600\c0;\csgray\c100000;\csgenericrgb\c39100\c22000\c12500;
\csgenericrgb\c77000\c10200\c8600;\csgenericrgb\c66500\c5200\c56900;\csgenericrgb\c0\c0\c0;\csgenericrgb\c11000\c0\c81000;}
\paperw11900\paperh16840\margl1440\margr1440\vieww10800\viewh8400\viewkind0
\deftab543
\pard\tx543\pardeftab543\pardirnatural\partightenfactor0

\f0\fs22 \cf2 \cb3 //Kruskal
\f1\fs24 \cf0 \

\f0\fs22 \cf4 #include \cf5 <iostream>
\f1\fs24 \cf0 \

\f0\fs22 \cf4 #include \cf5 <cstdio>
\f1\fs24 \cf0 \

\f0\fs22 \cf4 #include \cf5 <algorithm>
\f1\fs24 \cf0 \

\f0\fs22 \cf6 using\cf7  \cf6 namespace\cf7  std;
\f1\fs24 \cf0 \

\f0\fs22 \cf6 typedef\cf7  \cf6 long\cf7  \cf6 long\cf7  ll;
\f1\fs24 \cf0 \

\f0\fs22 \cf6 const\cf7  \cf6 int\cf7  maxn=\cf8 1e5\cf7 +\cf8 10\cf7 ;
\f1\fs24 \cf0 \

\f0\fs22 \cf6 int\cf7  f[maxn],cnt[maxn];
\f1\fs24 \cf0 \

\f0\fs22 \cf6 struct\cf7  ty\{
\f1\fs24 \cf0 \

\f0\fs22 \cf7     \cf6 int\cf7  u,v;
\f1\fs24 \cf0 \

\f0\fs22 \cf7     ll cost;
\f1\fs24 \cf0 \

\f0\fs22 \cf7 \}p[maxn];
\f1\fs24 \cf0 \

\f0\fs22 \cf6 int\cf7  n,m;
\f1\fs24 \cf0 \
\

\f0\fs22 \cf6 bool\cf7  cmp(ty a,ty b)\{
\f1\fs24 \cf0 \

\f0\fs22 \cf7     \cf6 return\cf7  a.cost<b.cost;
\f1\fs24 \cf0 \

\f0\fs22 \cf7 \}
\f1\fs24 \cf0 \
\

\f0\fs22 \cf6 void\cf7  Init()\{
\f1\fs24 \cf0 \

\f0\fs22 \cf7     \cf6 for\cf7 (\cf6 int\cf7  i=\cf8 0\cf7 ;i<maxn;i++)\{
\f1\fs24 \cf0 \

\f0\fs22 \cf7         f[i]=i;cnt[i]=\cf8 1\cf7 ;
\f1\fs24 \cf0 \

\f0\fs22 \cf7     \}
\f1\fs24 \cf0 \

\f0\fs22 \cf7 \}
\f1\fs24 \cf0 \
\

\f0\fs22 \cf6 int\cf7  Find(\cf6 int\cf7  x)\{
\f1\fs24 \cf0 \

\f0\fs22 \cf7     \cf6 return\cf7  x==f[x]?x:f[x]=Find(f[x]);
\f1\fs24 \cf0 \

\f0\fs22 \cf7 \}
\f1\fs24 \cf0 \
\

\f0\fs22 \cf6 void\cf7  Union(\cf6 int\cf7  x,\cf6 int\cf7  y)\{
\f1\fs24 \cf0 \

\f0\fs22 \cf7     \cf6 int\cf7  a=Find(x),b=Find(y);
\f1\fs24 \cf0 \

\f0\fs22 \cf7     \cf6 if\cf7 (a==b) \cf6 return\cf7  ;
\f1\fs24 \cf0 \

\f0\fs22 \cf7     \cf6 if\cf7 (cnt[a]<cnt[b]) swap(a,b);
\f1\fs24 \cf0 \

\f0\fs22 \cf7     f[b]=a;
\f1\fs24 \cf0 \

\f0\fs22 \cf7     cnt[a]+=cnt[b];
\f1\fs24 \cf0 \

\f0\fs22 \cf7 \}
\f1\fs24 \cf0 \
\

\f0\fs22 \cf7 ll kruskal()\{
\f1\fs24 \cf0 \

\f0\fs22 \cf7     sort(p+\cf8 1\cf7 ,p+n,cmp);
\f1\fs24 \cf0 \

\f0\fs22 \cf7     ll res=\cf8 0\cf7 ;
\f1\fs24 \cf0 \

\f0\fs22 \cf7     \cf6 for\cf7 (\cf6 int\cf7  i=\cf8 1\cf7 ;i<n;i++)\{
\f1\fs24 \cf0 \

\f0\fs22 \cf7         \cf6 if\cf7 (Find(p[i].u)!=Find(p[i].v))\{
\f1\fs24 \cf0 \

\f0\fs22 \cf7             Union(p[i].u, p[i].v);
\f1\fs24 \cf0 \

\f0\fs22 \cf7             res+=p[i].cost;
\f1\fs24 \cf0 \

\f0\fs22 \cf7         \}
\f1\fs24 \cf0 \

\f0\fs22 \cf7     \}
\f1\fs24 \cf0 \

\f0\fs22 \cf7     \cf6 return\cf7  res;
\f1\fs24 \cf0 \

\f0\fs22 \cf7 \}
\f1\fs24 \cf0 \
\

\f0\fs22 \cf6 int\cf7  main() \{
\f1\fs24 \cf0 \

\f0\fs22 \cf7     ios::sync_with_stdio(\cf6 false\cf7 );
\f1\fs24 \cf0 \

\f0\fs22 \cf7     cin.tie(\cf8 0\cf7 );
\f1\fs24 \cf0 \

\f0\fs22 \cf7     \cf6 while\cf7 (cin>>m&&m)\{
\f1\fs24 \cf0 \

\f0\fs22 \cf7         Init();
\f1\fs24 \cf0 \

\f0\fs22 \cf7         n=\cf8 1\cf7 ;
\f1\fs24 \cf0 \

\f0\fs22 \cf7         \cf6 for\cf7 (\cf6 int\cf7  i=\cf8 0\cf7 ;i<m-\cf8 1\cf7 ;i++)\{
\f1\fs24 \cf0 \

\f0\fs22 \cf7             \cf6 char\cf7  from,to;\cf6 int\cf7  k,d;
\f1\fs24 \cf0 \

\f0\fs22 \cf7             cin.get();
\f1\fs24 \cf0 \

\f0\fs22 \cf7             cin>>from>>k;
\f1\fs24 \cf0 \
\

\f0\fs22 \cf7             \cf6 for\cf7 (\cf6 int\cf7  i=\cf8 0\cf7 ;i<k;i++)\{
\f1\fs24 \cf0 \

\f0\fs22 \cf7                 cin.get();
\f1\fs24 \cf0 \

\f0\fs22 \cf7                 cin>>to>>d;
\f1\fs24 \cf0 \

\f0\fs22 \cf7                 p[n].u=from-\cf8 'A'\cf7 ;p[n].v=to-\cf8 'A'\cf7 ;p[n].cost=d;
\f1\fs24 \cf0 \

\f0\fs22 \cf7                 n++;
\f1\fs24 \cf0 \

\f0\fs22 \cf7             \}
\f1\fs24 \cf0 \

\f0\fs22 \cf7         \}
\f1\fs24 \cf0 \

\f0\fs22 \cf7         cout<<kruskal()<<endl;
\f1\fs24 \cf0 \

\f0\fs22 \cf7     \}
\f1\fs24 \cf0 \

\f0\fs22 \cf7     \cf6 return\cf7  \cf8 0\cf7 ;
\f1\fs24 \cf0 \

\f0\fs22 \cf7 \}}