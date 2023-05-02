/*
 * ACM ICPC preparation
 * Author: Sai Tej Sunkara
 * Topic: Classical Arrays
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

void updateData(int *arr, int index, int data) {
    arr[index] = data;
}

vector<int> solve() {
    vector<int> r;
    
    int arr[] = {1, 2, 3, 4, 5, 6, 8, 7};
    int n = sizeof(arr)/sizeof(int);
    cout<<n<<endl;

    cout<<arr<<endl;
    cout<<*arr<<endl;

    cout<<arr+1<<endl;
    cout<<*(arr+1)<<endl;

    updateData(arr, 0, 12);
    cout<<arr[0]<<endl;

    cout<<((*(arr+1))==arr[1])<<endl;

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