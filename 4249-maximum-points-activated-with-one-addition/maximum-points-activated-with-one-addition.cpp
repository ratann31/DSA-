class Solution {
public:
    
    vector<int> parent, sz;
    
    int find(int x) {
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    
    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        
        if(a != b) {
            if(sz[a] < sz[b]) swap(a, b);
            parent[b] = a;
            sz[a] += sz[b];
        }
    }
    
    int maxActivated(vector<vector<int>>& points) {
        int n = points.size();
        
        parent.resize(n);
        sz.resize(n, 1);
        
        for(int i = 0; i < n; i++) parent[i] = i;
        
        unordered_map<int, int> x_map, y_map;
        
        // Build components
        for(int i = 0; i < n; i++) {
            int x = points[i][0];
            int y = points[i][1];
            
            if(x_map.count(x)) {
                unite(i, x_map[x]);
            } else {
                x_map[x] = i;
            }
            
            if(y_map.count(y)) {
                unite(i, y_map[y]);
            } else {
                y_map[y] = i;
            }
        }
        
        // Count component sizes
        unordered_map<int, int> comp;
        
        for(int i = 0; i < n; i++) {
            int root = find(i);
            comp[root]++;
        }
        
        int max1 = 0, max2 = 0;
        
        // Find two largest components
        for(auto &it : comp) {
            int s = it.second;
            if(s > max1) {
                max2 = max1;
                max1 = s;
            } else if(s > max2) {
                max2 = s;
            }
        }
        
        // If only one component
        if(comp.size() == 1) return n + 1;
        
        return max1 + max2 + 1;
    }
};