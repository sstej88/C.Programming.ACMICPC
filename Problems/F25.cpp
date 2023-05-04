/*
 * ACM ICPC preparation
 * Author: Sai Tej Sunkara
 * Topic: Maximum Score From Removing Elements
 * 
 * Sequence Containers: Arrays, Vectors, Deque, Forward List, List
 * Associative Containers: Map, Set, Multimap, Multiset
 * Unordered Associative Containers: Unordered Map, Unordered Set, Unordered Multimap, Unordered Multiset
 * Container Adapters: Stack, Queue, Priority Queue
*/

#include<bits/stdc++.h>
#include<unordered_set>
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

int maximumScore(int a, int b, int c) {
    vector<int> piles;
    piles.reserve(3);

    int score = 0;

    piles.push_back(a);
    piles.push_back(b);
    piles.push_back(c);

    priority_queue<int> pq;
    int numberOfZeros = 0;

    for(int i=0; i<3; i++) {
        if(piles.at(i)==0) numberOfZeros++;
    }
    // cout<<numberOfZeros<<endl;

    while(numberOfZeros<2) {
        for(int i=0; i<3; i++) {
            pq.push(piles.at(i));
        }

        int max = pq.top();
        pq.pop();
        int mid = pq.top();
        pq.pop();
        int min = pq.top();
        pq.pop();

        if(min!=0) {
            score++;
            max--;
            min--;
        }
        else {
            score++;
            max--;
            mid--;
        }

        piles.clear();
        piles.push_back(max);
        piles.push_back(mid);
        piles.push_back(min);

        // cout<<score<<endl;
        // for(auto x: piles) {
        //     cout<<x<<" ";
        // }
        // cout<<endl;

        numberOfZeros = 0;
        for(int i=0; i<3; i++) {
            if(piles.at(i)==0) numberOfZeros++;
        }

    }

    return score;
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
        int a, b, c;
        cin>>a>>b>>c;
        cout<<maximumScore(a, b, c)<<endl;
    }
    cerr<<((double)clock()-initialTime)/CLOCKS_PER_SEC<<endl;
}