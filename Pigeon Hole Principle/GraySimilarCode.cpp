/*
 * ACM ICPC preparation
 * Author: Sai Tej Sunkara
 * Topic: Grays Codes are something which numbers in sequence such that a[n] will differ by 1 bit position than a[n-1]
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

const int mod = 1e9+7;

template<typename T>
inline T pow(T a, T b) {
    T x = 1;
    while(b) {
        if(b&1) x*=a; x = x%mod;
        a*=a; a = a%mod;
        b>>=1;
    }
    return x;
}

template<typename T>
inline T fastMultiplication(T a, T b) {
    T x = 0;
    while(b) {
        if(b&1) x+=a; x = x%mod;
        a+=a; a = a%mod;
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

bool graySimilarCode(vector<int> &arr) {
    if(arr.size()>=130) {
        return true; // Came from Pigeon Hole Principle
    }
    else { // It only runs if size is <130, that means O(n^4) == O(10^8) which is acceptable
        for(int i=0; i<arr.size(); i++) {
            for(int j=i+1; j<arr.size(); j++) {
                for(int k=j+1; k<arr.size(); k++) {
                    for(int l=k+1; l<arr.size(); l++) {
                        if(arr.at(i)^arr.at(j)^arr.at(k)^arr.at(l) == 0) {
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    }
}

vector<int> solve() {
    vector<int> r;

    int n, e;
    cin>>n;
    vector<int> arr;
    while(n--) {
        cin>>e;
        arr.push_back(e);
    }

    cout<<graySimilarCode(arr)<<endl;

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