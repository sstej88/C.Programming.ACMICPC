/*
 * ACM ICPC preparation
 * Author: Sai Tej Sunkara
 * Topic: Quick Select
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

void swap(vector<int>& arr, int i, int j) {
    int temp = arr.at(i);
    arr.at(i) = arr.at(j);
    arr.at(j) = temp;
}

int quickSelect(vector<int>& arr, int left, int right, int k) {
        int pivot = arr.at(right);
        int pointer = left;
        int greater = left;
        bool isGreaterSet = false;
        for(int i=left; i<right; i++) {
            if(arr.at(i)<=pivot) {
                if(i>greater) {
                    swap(arr, greater, i);
                    greater = i;
                }
                pointer++;
            }
            else if(!isGreaterSet) {
                greater = i;
                isGreaterSet = true;
            }
        }
        if(arr.at(pointer)>arr.at(right)){
            swap(arr, pointer, right);
        }
        if(pointer==arr.size()-k) {
            return arr.at(pointer);
        }
        else if(pointer>arr.size()-k) {
            return quickSelect(arr, left, pointer-1, k);
        }
        else { // if(pointer<arr.size()-k)
            // if(pointer!=right) {
                    return quickSelect(arr, pointer+1, right, k);
            // }
        }
}

int findKthLargest(vector<int>& nums, int k) {
    return quickSelect(nums, 0, nums.size()-1, k);
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
        int n, e, k;
        cin>>n;
        while(n--) {
            cin>>e;
            nums.push_back(e);
        }
        cin>>k;
        int result = findKthLargest(nums, k);
        cout<<result<<endl;
    }
    cerr<<((double)clock()-initialTime)/CLOCKS_PER_SEC<<endl;
    return 0;
}