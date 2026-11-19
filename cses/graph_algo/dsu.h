#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

struct DSU {

    vector<int> parent, sz;
    int components;
    DSU(int n) {
        parent.resize(n);
        sz.assign(n, 1);
        iota(parent.begin(), parent.end(), 0); // equivalent of parent[i] =i
        components=n;
    }

    // Find with path compression
    int find(int x) {
        // TODO: Implement
        if(parent[x]==x) return x;
        return parent[x]=find(parent[x]);
    }

    // Union by size
    bool unite(int a, int b) {
        // TODO: Implement
        // ret false if find(a) = find(b)
        int par_a = find(a);
        int par_b = find(b);
        if(par_a==par_b) return false;
        int sza = sz[par_a];
        int szb = sz[par_b];
        if(sza>szb){
            parent[par_b] = par_a;
            sz[par_a]+=szb;
        }
        else if(szb>sza){
            parent[par_a] = par_b;
            sz[par_b]+=sza;
        }
        // bigger as parent
        else if(sza==szb && par_a>par_b){
            parent[par_b] = par_a;
            sz[par_a]+=szb;
        }
        else{
            parent[par_a] = par_b;
            sz[par_b]+=sza;
        }
        components--;
        return true;
    }

    bool connected(int a, int b) {
        return find(a) == find(b);
    }

    int size(int x) {
        return sz[find(x)];
    }
};

struct Edge{
    int x,y;
    Edge(int a,int b){
        x = min(a,b);
        y= max(a,b);
    }
    bool operator<(const Edge& other) const {
    if (x != other.x) return x < other.x;
    return y < other.y;
    }

};

// remember one thing before using this assumes the nodes are numbered from 0 to n-1 
// if not in actual initalise the edge with a-1,b-1
