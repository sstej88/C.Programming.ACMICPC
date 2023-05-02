/*
 * ACM ICPC preparation
 * Author: Sai Tej Sunkara
 * Topic: 
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

void insert(list<int> &ls) {
    ls.push_back(5);
    ls.push_back(6);
    ls.push_back(7);
    ls.push_back(8);
    ls.push_back(0);
    ls.push_back(4);
}

vector<int> solve() {
    vector<int> r;
    
    list<int> ls;
    insert(ls);
    unordered_map<int, int> ump;
    
    while(!ls.empty()) {
        int key = ls.front();
        ls.pop_front();
        if(ls.empty()) {
            cout<<"No Cycles Found"<<endl;
        }
        else {
            int value = ls.front();
            if(ump.count(value)!=0) {
                cout<<"Cycle Found"<<endl;
                break;
            }
        else {
            ump[key] = value;
        }
        }
    }

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