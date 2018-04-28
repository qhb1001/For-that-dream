{\rtf1\ansi\ansicpg936\cocoartf1561\cocoasubrtf100
{\fonttbl\f0\fnil\fcharset0 Menlo-Regular;\f1\fswiss\fcharset0 Helvetica;}
{\colortbl;\red255\green255\blue255;\red0\green116\blue0;\red255\green255\blue255;\red100\green56\blue32;
\red196\green26\blue22;\red170\green13\blue145;\red0\green0\blue0;\red28\green0\blue207;}
{\*\expandedcolortbl;;\csgenericrgb\c0\c45600\c0;\csgray\c100000;\csgenericrgb\c39100\c22000\c12500;
\csgenericrgb\c77000\c10200\c8600;\csgenericrgb\c66500\c5200\c56900;\csgenericrgb\c0\c0\c0;\csgenericrgb\c11000\c0\c81000;}
\paperw11900\paperh16840\margl1440\margr1440\vieww10800\viewh8400\viewkind0
\deftab543
\pard\tx543\pardeftab543\pardirnatural\partightenfactor0

\f0\fs22 \cf2 \cb3 //priority_queue + prim
\f1\fs24 \cf0 \

\f0\fs22 \cf4 #include \cf5 <iostream>
\f1\fs24 \cf0 \

\f0\fs22 \cf4 #include \cf5 <cstdio>
\f1\fs24 \cf0 \

\f0\fs22 \cf4 #include \cf5 <cstring>
\f1\fs24 \cf0 \

\f0\fs22 \cf4 #include \cf5 <queue>
\f1\fs24 \cf0 \

\f0\fs22 \cf4 #include \cf5 <set>
\f1\fs24 \cf0 \

\f0\fs22 \cf6 using\cf7  \cf6 namespace\cf7  std;
\f1\fs24 \cf0 \

\f0\fs22 \cf6 const\cf7  \cf6 int\cf7  maxn=\cf8 30\cf7 ;
\f1\fs24 \cf0 \

\f0\fs22 \cf6 int\cf7  mmap[maxn][maxn];
\f1\fs24 \cf0 \

\f0\fs22 \cf6 bool\cf7  vis[maxn];
\f1\fs24 \cf0 \

\f0\fs22 \cf6 int\cf7  ans,n;
\f1\fs24 \cf0 \

\f0\fs22 \cf6 struct\cf7  ty\{
\f1\fs24 \cf0 \

\f0\fs22 \cf7     \cf6 int\cf7  to,dis;
\f1\fs24 \cf0 \

\f0\fs22 \cf7     \cf6 bool\cf7  \cf6 operator\cf7 <(\cf6 const\cf7  ty& b)\cf6 const\cf7 \{
\f1\fs24 \cf0 \

\f0\fs22 \cf7         \cf6 return\cf7  dis>b.dis;
\f1\fs24 \cf0 \

\f0\fs22 \cf7     \}
\f1\fs24 \cf0 \

\f0\fs22 \cf7 \};
\f1\fs24 \cf0 \
\

\f0\fs22 \cf7 priority_queue<ty>q;
\f1\fs24 \cf0 \

\f0\fs22 \cf6 void\cf7  prim()\{
\f1\fs24 \cf0 \

\f0\fs22 \cf7     \cf6 while\cf7 (!q.empty()) q.pop();
\f1\fs24 \cf0 \

\f0\fs22 \cf7     vis[\cf8 0\cf7 ]=\cf8 1\cf7 ;
\f1\fs24 \cf0 \

\f0\fs22 \cf7     \cf6 int\cf7  now=\cf8 0\cf7 ,k=\cf8 1\cf7 ;
\f1\fs24 \cf0 \

\f0\fs22 \cf7     \cf6 while\cf7 (k<n)\{
\f1\fs24 \cf0 \

\f0\fs22 \cf7         \cf6 for\cf7 (\cf6 int\cf7  j=\cf8 0\cf7 ;j<n;j++)\{
\f1\fs24 \cf0 \

\f0\fs22 \cf7             \cf6 if\cf7 (mmap[now][j])\{
\f1\fs24 \cf0 \

\f0\fs22 \cf7                 ty tmp;tmp.to=j;tmp.dis=mmap[now][j];
\f1\fs24 \cf0 \

\f0\fs22 \cf7                 q.push(tmp);
\f1\fs24 \cf0 \

\f0\fs22 \cf7             \}
\f1\fs24 \cf0 \

\f0\fs22 \cf7         \}
\f1\fs24 \cf0 \
\

\f0\fs22 \cf7         \cf6 while\cf7 (vis[q.top().to]) q.pop();
\f1\fs24 \cf0 \

\f0\fs22 \cf7         \cf2 //            cout<<(char)(now+'A')<<"->";
\f1\fs24 \cf0 \

\f0\fs22 \cf7         now=q.top().to;\cf6 int\cf7  d=q.top().dis;
\f1\fs24 \cf0 \

\f0\fs22 \cf7         q.pop();
\f1\fs24 \cf0 \

\f0\fs22 \cf7         \cf2 //            cout<<(char)(now+'A')<<" "<<d<<" ";
\f1\fs24 \cf0 \

\f0\fs22 \cf7         ans+=d;
\f1\fs24 \cf0 \

\f0\fs22 \cf7         \cf2 //            cout<<ans<<" "<<k<<endl;
\f1\fs24 \cf0 \

\f0\fs22 \cf7         vis[now]=\cf8 1\cf7 ;
\f1\fs24 \cf0 \

\f0\fs22 \cf7         k++;
\f1\fs24 \cf0 \

\f0\fs22 \cf7     \}
\f1\fs24 \cf0 \

\f0\fs22 \cf7 \}
\f1\fs24 \cf0 \

\f0\fs22 \cf6 int\cf7  main() \{
\f1\fs24 \cf0 \

\f0\fs22 \cf7     ios::sync_with_stdio(\cf6 false\cf7 );
\f1\fs24 \cf0 \

\f0\fs22 \cf7     cin.tie(\cf8 0\cf7 );
\f1\fs24 \cf0 \

\f0\fs22 \cf7     \cf6 while\cf7 (cin>>n&&n)\{
\f1\fs24 \cf0 \

\f0\fs22 \cf7         ans=\cf8 0\cf7 ;
\f1\fs24 \cf0 \

\f0\fs22 \cf7         memset(mmap,\cf8 0\cf7 ,\cf6 sizeof\cf7 (mmap));
\f1\fs24 \cf0 \

\f0\fs22 \cf7         memset(vis,\cf8 0\cf7 ,\cf6 sizeof\cf7 (vis));
\f1\fs24 \cf0 \
\

\f0\fs22 \cf7         \cf6 for\cf7 (\cf6 int\cf7  i=\cf8 0\cf7 ;i<n-\cf8 1\cf7 ;i++)\{
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

\f0\fs22 \cf7                 mmap[from-\cf8 'A'\cf7 ][to-\cf8 'A'\cf7 ]=mmap[to-\cf8 'A'\cf7 ][from-\cf8 'A'\cf7 ]=d;
\f1\fs24 \cf0 \

\f0\fs22 \cf7             \}
\f1\fs24 \cf0 \

\f0\fs22 \cf7         \}
\f1\fs24 \cf0 \
\

\f0\fs22 \cf7         \cf2 //        for(int i=0;i<n;i++)\{
\f1\fs24 \cf0 \

\f0\fs22 \cf7         \cf2 //            for(int j=0;j<n;j++)\{
\f1\fs24 \cf0 \

\f0\fs22 \cf7         \cf2 //                cout<<mmap[i][j]<<" ";
\f1\fs24 \cf0 \

\f0\fs22 \cf7         \cf2 //            \}
\f1\fs24 \cf0 \

\f0\fs22 \cf7         \cf2 //            cout<<endl;
\f1\fs24 \cf0 \

\f0\fs22 \cf7         \cf2 //        \}
\f1\fs24 \cf0 \
\

\f0\fs22 \cf7         prim();
\f1\fs24 \cf0 \

\f0\fs22 \cf7         cout<<ans<<endl;
\f1\fs24 \cf0 \

\f0\fs22 \cf7     \}
\f1\fs24 \cf0 \

\f0\fs22 \cf7     \cf6 return\cf7  \cf8 0\cf7 ;
\f1\fs24 \cf0 \

\f0\fs22 \cf7 \}
\f1\fs24 \cf0 \
}