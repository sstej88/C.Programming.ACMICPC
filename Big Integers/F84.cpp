/*
 * ACM ICPC preparation
 * Author: Sai Tej Sunkara
 * Topic: Big Integers Additions
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

inline string addStrings(string num1, string num2) {
    string result = "";

    vector<int> n1;
    vector<int> n2;

    int size = (num1.size()>num2.size()?num1.size():num2.size())+1;
    int carry = 0;
    
    for(int i=num1.size()-1; i>=0; i--) {
        n1.push_back((int)(num1.at(i))-48);
    }
    for(int i=num2.size()-1; i>=0; i--) {
        n2.push_back((int)(num2.at(i))-48);
    }

    while(n1.size()<size) {
        n1.push_back(0);
    }
    while(n2.size()<size) {
        n2.push_back(0);
    }

    for(int i=0; i<size; i++) {
        int sum = n1.at(i)+n2.at(i)+carry;
        result = to_string(sum%10)+result;

        carry = 0;
        if(sum>=10) {
            carry = 1;
        }
    }

    if(result.size()>1 && result.at(0)=='0') {
        result = result.substr(1);
    }

    return result;
}

vector<string> solve() {
    vector<string> r;

    string a, b;
    a="1111111111111111111111111111111111111111111111111111111111111111111111";
    b="2222222222222222222222222222222222222222222222222222222222222222222222";
    r.push_back(addStrings(a, b));
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
        vector<string> result = solve();
        for(auto x: result) {
            cout<<x<<" ";
        }
        cout<<endl;
    }
    cerr<<((double)clock()-initialTime)/CLOCKS_PER_SEC<<endl;
}