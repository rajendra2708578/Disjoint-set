#include<bits/stdc++.h>
using namespace std;
class DisjointSet{
    vector<int>size,rank,parent;
public:
    DisjointSet(int n)
    {
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
            size[i]=1;
        }
    }
    int findUPar(int n))
    {
        if(parent[n]==n)
        return n;
        parent[n]=findUPar(parent[n]);
    }
    void unionByRank(int u,int v)
    {

        int ulp_u=findUPar(u);
        int ulp_v=findUPar(v);
        if(rank[ulp_u]<rank[ulp_v])
        {

            parent[ulp_u]=ulp_v;
        }
        else if(rank[ulp_u]>rank[ulp_v])
        {

            parent[ulp_v]=ulp_u;
        }
        else
        {
            parent[ulp_u]=ulp_v;
            rank[ulp_v]++;

        }

    }
    void unionBySize(int u,int v)
    {

        int ulp_u=findUPar(u);
        int ulp_v=findUPar(v);
        if(size[ulp_u]<size[ulp_v])
        {

            parent[ulp_u]=ulp_v;
            rank[ulp_v]+=rank[ulp_u];
        }
        else
        {

            parent[ulp_v]=ulp_u;
            rank[ulp_u]+=rank[ulp_v];
        }
    }

};
