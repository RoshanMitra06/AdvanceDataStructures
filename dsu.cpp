#include<bits/stdc++.h>
using namespace std;
 
//keep coding
//-Roshan Mitra (SIT Pune) 
typedef vector <int> vi;
typedef pair< int ,int > pii;
#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 struct dsu
 {
     vi par;
     vi rank;
     dsu(int n){
         par=vi(n+2);
         rank=vi(n+2,0);
         for(int i=1;i<=n;i++)
            par[i]=i,rank[i]=0;
     }

     int findpar(int node){
         if(node==par[node]) return node;

         return par[node]=findpar(par[node]);
     }

     void unions(int u,int v){
         int p1=findpar(u);
         int p2=findpar(v);
         if(p1==p2) return;

         int r1=rank[p1];
         int r2=rank[p2];
         if(r1<r2){
             par[p1]=p2;
             rank[p2]++;
         }
         else{
             par[p2]=p1;
             rank[p1]++;
         }
     }

 };
 
signed main()
{
     OJ;
    int n,m;
    cin>>n>>m;
    dsu s(n);
    for(int i = 0;i<m;i++) {
        int p,q;
        cin >> p >> q;
        s.unions(p, q); 
    }
    set<int>se;
    for(int i=1;i<n;i++)
        se.insert(s.findpar(i));

   
}