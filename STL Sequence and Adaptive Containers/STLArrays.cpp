/*
 * ACM ICPC preparation
 * Author: Sai Tej Sunkara
 * Topic: STL Arrays
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

void display(const array<int, 6> arr) { // Here const is used because this function need not change the values in an array.
    cout<<"Displaying array"<<endl;
    for(int i=0; i< arr.size(); i++) {
        cout<<arr.at(i)<<" ";
    }
    cout<<endl;
}

void update(array<int, 6> &pArr, int index, int data) { // here pArr is reference variable. So actual array will be changed.
    pArr.at(index) = data;
}

vector<int> solve() {
    vector<int> r;
    
    array<int, 6> arr = {1, 2, 3, 4, 5, 6};
    display(arr); // array is passed by value.

    update(arr, 3, 12); // array is updated because it is passed as reference.
    display(arr);

    // Since we are passing entire array object, array size need not be defined in main and sent to function.

    // Iterators uses arr.begin() and arr.end() which gives starting address and ending address.

    sort(arr.begin(), arr.end());
    display(arr);

    array<int, 6> arrFill;
    arrFill.fill(5);
    display(arrFill);

    cout<<"Displaying array through for each loop"<<endl;
    for(auto x: arr) {
        cout<<x<<" ";
    }
    cout<<endl;

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