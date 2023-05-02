/*
 * ACM ICPC preparation
 * Author: Sai Tej Sunkara
 * Topic: STL Hash Tables
 * 
 * Sequence Containers: Arrays, Vectors, Deque, Forward List, List
 * Associative Containers: Map, Set, Multimap, Multiset
 * Unordered Associative Containers: Unordered Map, Unordered Set, Unordered Multimap, Unordered Multiset
 * Container Adapters: Stack, Queue, Priority Queue
*/

#include<bits/stdc++.h>
#include<ctime>
#define int long long int
#define double long double
#define endl "\n"
#define RUN_LOCAL
using namespace std;

template<typename T>
inline T pow(T a, T b) {
    T x = 1;
    while(b) {
        if(b&1) x*=a;
        a*=a;
        b>>=1;
    }
    return x;
}

template<typename T>
T bug(T x) {
    cout<<"Bug: "<<x<<endl;
}

void insert(unordered_map<string, double> &umap) {
    pair<string, double> p;
    
    p.first = "Pizza";
    p.second = 5.26;
    umap.insert(p);
    
    p.first = "Idly";
    p.second = 3.19;
    umap.insert(p);
    
    p.first = "Dosa";
    p.second = 4.12;
    umap.insert(p);
    
    p.first = "Indian Tea";
    p.second = 1.16;
    umap.insert(p);
    
}

void display(unordered_map<string, double> umap) {
    if(umap.empty()) {
        cout<<"Hash Table is empty"<<endl;
    }
    else {
        cout<<"Displaying Hash Table: "<<endl;
        for(pair<string, double> x: umap) {
            cout<<x.first<<" - "<<x.second<<endl;
        }
        cout<<endl;
    }
}

void search(unordered_map<string, double> umap, string item) {
    if(umap.count(item)==0) {
        cout<<item+" is not present in hash table"<<endl;
    }
    else {
        cout<<"Search is successful: "+item+" - "<<umap[item]<<endl;
    }
}

void deleteItem(unordered_map<string, double> &umap, string item) {
    if(umap.count(item)==0) {
        cout<<item+" is not present in hash table to delete it"<<endl;
    }
    else {
        umap.erase(item);
        cout<<item+" is deleted. Updated Hash Table is as follows: "<<endl;
        display(umap);
    }
}

vector<int> solve() {
    vector<int> r;
    
    // Hash Tables - Unordered Map - Keys are not ordered in any particular fashion - Uses Hashing with separate chaining to store the key and value pair - So insertion takes O(1) time, Searching takes O(1) time, Deletion Takes O(1) time.
    unordered_map<string, double> umap;
    insert(umap);
    display(umap);
    search(umap, "Idly");
    search(umap, "Chicken");
    deleteItem(umap, "Dosa");
    deleteItem(umap, "Vada");

    // Similarly, when we use map, the elements are sorted and takes Log.n operation to insert, delete, search the items.

    return r;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);cerr.tie(0);
    clock_t initialTime = clock();
    #ifdef RUN_LOCAL
        freopen("../io/input.txt", "r", stdin);
        freopen("../io/output.txt", "w", stdout);
        freopen("../io/err.txt", "w", stderr);
    #endif
    int test = 1;
    cin>>test;
    while(test--) {
        vector<int> result = solve();
        for(auto x: result) {
            cout<<x<<" ";
        }
        cout<<endl;
    }
    cerr<<((double)clock()-initialTime)/CLOCKS_PER_SEC<<endl;
}