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

vector<int> singleNumber(vector<int>& nums) {
    if(nums.size()>2) {
        vector<int> result;
        result.reserve(2);

        int subXor = 0;
        for(auto x: nums) {
            subXor^=x;
        }
        int pos = 0;
        int i = 0;
        while(subXor) {
            if(subXor&1) {
                pos = i;
                break;
            }
            subXor>>=1;
            i++;
        }
        vector<int> sub1;
        vector<int> sub2;
        for(auto x: nums) {
            int bck=x;
            x>>=pos;
            if(x&1) {
                sub1.push_back(bck);
            }
            else {
                sub2.push_back(bck);
            }
        }

        int r1=0, r2=0;
        for(auto x: sub1) {
            r1^=x;
        }
        for(auto x: sub2) {
            r2^=x;
        }
        result.push_back(r1);
        result.push_back(r2);

        return result;
    }
    else {
        return nums;
    }
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
        vector<int> result = singleNumber(nums);
        for(auto x: result) {
            cout<<x<<" ";
        }
        cout<<endl;
    }
    cerr<<((double)clock()-initialTime)/CLOCKS_PER_SEC<<endl;
}