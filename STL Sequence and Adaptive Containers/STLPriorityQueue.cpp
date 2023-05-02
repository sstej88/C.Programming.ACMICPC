/*
 * ACM ICPC preparation
 * Author: Sai Tej Sunkara
 * Topic: STL Priority Queue, Max Heap, Min Heap, Custom Heap
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

class Compare {
    public:
    bool operator()(int a, int b) {
        if((a&1)==0) {
            if((b&1)==0) {
                return a<b;
            }
            else {
                return a>b;
            }
        }
        else if((b&1)==0) {
            return a>b;
        }
        else {
            return a<b;
        }
    }
};

void insert(priority_queue<int> &heap) {
    heap.push(10);
    heap.push(30);
    heap.push(50);
    heap.push(20);
    heap.push(25);
    heap.push(22);
    heap.push(45);
    heap.push(21);
}

void insertMinHeap(priority_queue<int, vector<int>, greater<int> > &heap) {
    heap.push(10);
    heap.push(30);
    heap.push(50);
    heap.push(20);
    heap.push(25);
    heap.push(22);
    heap.push(45);
    heap.push(21);
}

void insertCustomHeap(priority_queue<int, vector<int>, Compare> &heap) {
    heap.push(10);
    heap.push(30);
    heap.push(51);
    heap.push(20);
    heap.push(25);
    heap.push(22);
    heap.push(45);
    heap.push(21);
}

void display(priority_queue<int> heap) {
    cout<<"Displaying Priority Queue Max Heap: "<<endl;
    while(!heap.empty()) {
        cout<<heap.top()<<" ";
        heap.pop();
    }
    cout<<endl;
}

void displayMinHeap(priority_queue<int, vector<int>, greater<int> > heap) {
    cout<<"Displaying Priority Queue Min Heap: "<<endl;
    while(!heap.empty()) {
        cout<<heap.top()<<" ";
        heap.pop();
    }
    cout<<endl;
}

void displayCustomHeap(priority_queue<int, vector<int>, Compare> heap) {
    cout<<"Displaying Priority Queue Custom Heap: "<<endl;
    while(!heap.empty()) {
        cout<<heap.top()<<" ";
        heap.pop();
    }
    cout<<endl;
}

vector<int> solve() {
    vector<int> r;
    
    priority_queue<int> heap;
    insert(heap);
    display(heap);

    priority_queue<int, vector<int>, greater<int> > minHeap;
    insertMinHeap(minHeap);
    displayMinHeap(minHeap);

    priority_queue<int, vector<int>, Compare> customHeap;
    insertCustomHeap(customHeap);
    displayCustomHeap(customHeap);

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