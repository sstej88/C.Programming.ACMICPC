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

void swap(vector<int> &arr, int i, int j) {
    int temp = arr.at(i);
    arr.at(i) = arr.at(j);
    arr.at(j) = temp;
}

void quicksort(vector<int> &arr, int left, int right) {
    if(left<right) {
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
        swap(arr, pointer, right);
        quicksort(arr, left, pointer-1);
        quicksort(arr, pointer+1, right);
    }
    else {
        return;
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
        int n, e;
        vector<int> arr;
        cin>>n;
        while(n--) {
            cin>>e;
            arr.push_back(e);
        }
        quicksort(arr, 0, arr.size()-1);
        for(auto x: arr) {
            cout<<x<<" ";
        }
        cout<<endl;
    }
    cerr<<((double)clock()-initialTime)/CLOCKS_PER_SEC<<endl;
}