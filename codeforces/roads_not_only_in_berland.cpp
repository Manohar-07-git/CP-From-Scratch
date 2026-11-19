#include <cstddef>
#include<utility>
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
        iota(parent.begin(), parent.end(), 0); // equivalent of parent[i] =i+1
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
        x = a;
        y= b;
    }
    bool operator<(const Edge& other) const {
    if (x != other.x) return x < other.x;
    return y < other.y;
    }

};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<pair<int,int>> extra;

    int n;
    cin>>n;
    DSU dsu(n);
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        if(dsu.unite(a-1, b-1))continue;
        extra.push_back({a-1,b-1});
    }
    //sort(extra.begin(),extra.end());
    int comp = dsu.components;
    vector<int> roots;

    for (int i = 0; i < n; i++) {
        if (dsu.parent[i] == i) {
            roots.push_back(i);
        }
    }

    cout<<comp-1<<'\n';

    for(int i=1;i<roots.size();i++){
        cout<<extra[i-1].first+1<<" "<<extra[i-1].second+1<<" ";
        cout<<roots[i-1]+1<<" "<<roots[i]+1;
        cout<<'\n';
    }



}