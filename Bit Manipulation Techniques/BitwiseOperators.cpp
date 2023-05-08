/*
 * ACM ICPC preparation
 * Author: Sai Tej Sunkara
 * Topic: Bitwise Operators - very fast compared to other operators in programming languages.
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

int andCheck(int a, int b) {
    return a&b;
}

int orCheck(int a, int b) {
    return a|b;
}

int xorCheck(int a, int b) {
    return a^b; // It both are same bits, give 0. Else will give 1.
}

int notCheck(int a) {
    return ~a; // Flips the sign bit also.
}

vector<int> solve() {
    vector<int> r;

    cout<<andCheck(5, 7)<<endl;
    cout<<orCheck(5, 7)<<endl;
    cout<<xorCheck(5, 7)<<endl;
    cout<<notCheck(0)<<endl;

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