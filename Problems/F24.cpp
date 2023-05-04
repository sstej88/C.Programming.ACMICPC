/*
 * ACM ICPC preparation
 * Author: Sai Tej Sunkara
 * Topic: One Integer
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

int solve(vector<int> nums) {
    int result = 0;
    while(nums.size() != 1) {
        sort(nums.begin(), nums.end());
        int sum = nums.at(0) + nums.at(1);
        result += nums.at(0);
        nums.erase(nums.begin());
        result += nums.at(0);
        nums.erase(nums.begin());
        nums.push_back(sum);
    }
    return result;
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
        vector<int> nums;
        int n, e;
        cin>>n;
        while(n--) {
            cin>>e;
            nums.push_back(e);
        }
        cout<<solve(nums);
    }
    cerr<<((double)clock()-initialTime)/CLOCKS_PER_SEC<<endl;
}