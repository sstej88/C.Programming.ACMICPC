/*
 * ACM ICPC preparation
 * Author: Sai Tej Sunkara
 * Topic: Traveling Salesman
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
inline T isEven(T a) {
    if(a&1) return false;
    else return true;
}

template<typename T>
inline T isTwoPower(T a) {
    if((a&(a-1))==0) return true;
    else return false;
}

template<typename T>
T bug(T x) {
    cout<<"Bug: "<<x<<endl;
}

int tsp(vector< vector<int> > weights, int visited, int toVisit) {
    visited = visited|(1<<toVisit);
    if(visited==((1<<4)-1)) {
        return weights[toVisit][0];
    }
    else {
        int ans = INT_MAX;
        for(int i=0; i<4; i++) {
            int subMin = weights[toVisit][i] + tsp(weights, visited, i);
            ans = min(ans, subMin);
        }
        return ans;
    }
}

vector<int> solve() {
    vector<int> r;

    vector< vector<int> > weights;

    for(int i=0; i<4; i++) {
        vector<int> nums;
        int e;
        for(int i=0; i<4; i++) {
            cin>>e;
            nums.push_back(e);
        }
        weights.push_back(nums);
    }

    int min = tsp(weights, 0, 0);
    cout<<min<<endl;

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