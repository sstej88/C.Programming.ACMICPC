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

void insert(vector<int> &v) {
    // Uses dynamic memory allocation

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(50);
    v.push_back(60);
    v.push_back(40);
    v.push_back(25);
    v.push_back(13);
    v.push_back(23);
}

void checkSize(vector<int> &v) { // Capacity cannot be printed if passed by value. When passed by value, unallocated places are not passed.
    cout<<"Size of vector : "<<v.size()<<" and capacity: "<<v.capacity()<<endl;
}

void display(vector<int> v) {
    cout<<"Displaying Vector: "<<endl;
    while(!v.empty()) {
        cout<<v.back()<<" ";
        v.pop_back();
    }
    cout<<endl;
}

vector<int> solve() {
    vector<int> v;

    insert(v);
    checkSize(v);

    display(v);

    vector<int> v1;
    v1.reserve(100);
    insert(v1);
    checkSize(v1);
    display(v1);

    array<int, 6> arr = {1, 2, 3, 4, 5, 6};
    vector<int> v2(arr.begin(), arr.end());
    display(v2);

    vector<int> v3(4, 6);
    display(v3);

    //clear method will remove all elements in a vector. However, capacity remains same. Size becomes zero as usual.
    // erasing 4th element. erase takes location of number to be erased as input.

    v.erase(v.begin()+3);
    display(v);

    return v;
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
        cout<<endl;
        for(auto x: result) {
            cout<<x<<" ";
        }
        cout<<endl;
    }
    cerr<<((double)clock()-initialTime)/CLOCKS_PER_SEC<<endl;
}