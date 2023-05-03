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
#include<unordered_set>
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

vector<int> solve(string s) {
    vector<int> r;
    
    unordered_map<char, vector<int> > index;
    unordered_map<char, int> adders;
    for(int i=0; i<s.length(); i++) {
        index[s.at(i)].push_back(i);
        if(adders.count(s.at(i))) {
            adders[s.at(i)]++;
        }
        else {
            adders[s.at(i)] = 1;
        }
    }

    set<int> min;
    for(auto x: adders) {
        if(x.second==1) {
            min.insert(index[x.first].at(0));
        }
    }
    
    if(min.size()) {
        r.push_back(*min.begin());
    }
    else {
        r.push_back(-1);
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
        string s;
        cin>>s;

        vector<int> result = solve(s);
        for(auto x: result) {
            cout<<x<<" ";
        }
        cout<<endl;
    }
    cerr<<((double)clock()-initialTime)/CLOCKS_PER_SEC<<endl;
}