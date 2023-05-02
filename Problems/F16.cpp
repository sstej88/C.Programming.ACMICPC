/*
 * ACM ICPC preparation
 * Author: Sai Tej Sunkara
 * Topic: Two Sum LC
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

vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> result;
    result.reserve(2);

    unordered_map<int, int> ump;
    unordered_map<int, vector<int> > indices;

    int index = 0;
    for(auto x: nums) {
        indices[x].push_back(index);
        index++;
    }

    for(auto x: nums) {
        if(ump.count(target-x)) {
            if(x!=(target-x)) {
                result.push_back(indices[x].at(0));
                result.push_back(indices[target-x].at(0));
            }
            else {
                result.push_back(indices[x].at(0));
                result.push_back(indices[x].at(1));
            }
            break;
        }
        else {
            ump[x] = target-x;
        }
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

        int n, e, target;
        vector<int> nums;
        cin>>n;
        while(n--) {
            cin>>e;
            nums.push_back(e);
        }
        cin>>target;

        vector<int> result = twoSum(nums, target);
        for(auto x: result) {
            cout<<x<<" ";
        }
        cout<<endl;
    }
    cerr<<((double)clock()-initialTime)/CLOCKS_PER_SEC<<endl;
}