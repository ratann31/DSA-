class Solution {
public:
    vector<int>parent,size;
    
    void make(int v){
    parent[v]=v;
    size[v]=1;
    }

    int find(int v){
        if(v==parent[v]){
            return v;
        }
        //path compression
        return parent[v]=find(parent[v]);
    }

    void Union(int a,int b){
        a=find(a);
        b=find(b);
        if(a!=b){
            //union by size
            if(size[a]<size[b]){
                swap(a,b);
            }
            parent[b]=a;
            size[a]+=size[b];
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        if((connections.size())<n-1) return -1;
        parent.resize(n);
        size.resize(n);
        //made independent nodes
        for(int i=0;i<n;i++){
            make(i);
        }
        //do union for combining and making components as per the given in question
        for(int i=0;i<connections.size();i++){
            int u=connections[i][0];
            int v=connections[i][1];
            Union(u,v);
        }
        //now find the number of components using find()
        int cmp=0;
        for(int i=0;i<n;i++){
            if(find(i)==i){
                cmp++;
            }
        }
        return cmp-1;
    }
};