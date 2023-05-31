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

const int mod = 1e9+7;
// Why are we maintaining every value less than 1e+7 although we have a space till 1e18? When we are multiplying 2 numbers of 1e9+7, then they can get stored in 1e18.
const int N = 1000000;

template<typename D, typename I>
inline D binaryExponentiation(D a, I b) {
    D r = 1;
    while(b) {
        if(b&1) r*=a; r%=mod;
        a*=a; a%=mod;
        b = b>>1;
    }
    return r;
}

template<typename D, typename I>
inline D powExponentiation(D a, I b) { // Binary Exponentiation
    if(b>=0) {
        return binaryExponentiation(a, b);
    }
    else {
        b = -b;
        D r = binaryExponentiation(a, b);
        return 1/r;
    }
}

template<typename T>
vector<bool> primeSieve(T N) {
    vector<bool> sieve(N, true);

    sieve[0] = false;
    sieve[1] = false;

    for(T i=2; i<=N; i++) {
        if(sieve[i]) {
            for(T j=i*i; j<=N; j=j+i) {
                sieve[j] = false;
            }
        }
        
    }

    return sieve;
}

template<typename T>
inline T fastMultiplication(T a, T b) {
    T r = 0;
    b%=mod;
    while(b) {
        if(b&1) r+=a; r%=mod;
        a+=a;
        a%=mod;
        b>>=1;
    }
    return r;
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

const int matSize = 2;
struct Mat {
    int mat[matSize][matSize];
    Mat() {
        for(int i=0; i<matSize; i++) {
            for(int j=0; j<matSize; j++) {
                mat[i][j] = 0;
            }
        }
    }
    void identity() {
        Mat();
        for(int i=0; i<matSize; i++) {
            mat[i][i] = 1;
        }
    }
    void display() {
        cout<<"Displaying Matrix: "<<endl;
        for(int i=0; i<matSize; i++) {
            for(int j=0; j<matSize; j++) {
                cout<<mat[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }

    Mat operator* (Mat a) {
        Mat result;
        for(int i=0; i<matSize; i++) {
            for(int j=0; j<matSize; j++) {
                for(int k=0; k<matSize; k++) {
                    result.mat[i][j] = result.mat[i][j] + mat[i][k]*a.mat[k][j];
                    result.mat[i][j]%=mod;
                }
            }
        }
        return result;
    }
};

int fibonacci(int n) {
    // Here we don't need F(n) and F(n+1) matrices. We just need them on paper. We will work on powers on T and then by intution, we get the values of F(n) by multiplying by [[1], [0]] 
    Mat r;
    Mat a;
    
    r.identity();
    for(int i=0; i<matSize; i++) {
        for(int j=0; j<matSize; j++) {
            int e;
            cin>>e;
            a.mat[i][j] = e;
        }
    }

    while(n) {
        if(n&1) {
            r = r*a;
        }
        a = a*a;
        n>>=1;
    }

    return (r.mat[0][0]+r.mat[0][1])%mod;
}

template<typename T>
inline T gcd(T min, T max) {
    if(min==0) {
        return max;
    }
    return gcd(max%min, min);
}

template<typename T>
vector< vector<T> > buildPascalTriangle(T n) { // Pascal Triangle gives NCR
    n = n+1;
    vector< vector<T> > pascal(n, vector<T>(n, 0));
    pascal.at(0).at(0) = 1;

    for(int i=1; i<n; i++) {
        for(int j=0; j<=(i/2); j++) {
            pascal.at(i).at(j) = pascal.at(i).at(i-j) = (pascal.at(i-1).at(j)+ ((j-1)>=0?pascal.at(i-1).at(j-1):0)); // NCR = NC(N-R)
        }
    }

    return pascal;
}

template<typename T>
T binomialCoefficient(T a, T b) {
    if(a>b) {
        vector< vector<T> > coefficients = buildPascalTriangle(a);
        return coefficients.at(a).at(b);
    }
    else {
        return -1;
    }
}

template<typename T>
void swap(vector<T> &input, int i, int j) {
    int temp = input.at(i);
    input.at(i) = input.at(j);
    input.at(j) = temp;
}

template<typename T>
void permutations(vector<T> &input, vector<vector<T> > &output, int i) {
    if(i==input.size()-1) {
        output.push_back(input);
        return;
    }
    else {
        for(int j=i; j<input.size(); j++) {
            swap(input, i, j);
            permutations(input, output, i+1);
            swap(input, i, j);
        }
    }
}

template<typename T>
void subsets(vector<T> &input, vector<vector<T> > &output, vector<T> subset, int i) {
    if(i==input.size()) {
        output.push_back(subset);
        return;
    }
    else {
        subset.push_back(input.at(i));
        subsets(input, output, subset, i+1);
        subset.pop_back(); // Backtracking
        subsets(input, output, subset, i+1);
    }
}

bool could_eat(vector<int>&piles,int h,int speed)
{
    for(int i=0;i<piles.size();i++)
    {
        if(piles[i]%speed==0)
        {
            h-=(piles[i]/speed);
        }
        else
        {
            h-=(piles[i]/speed)+1;
        }
        if(h<0)
        {
            return false;
        }
    }
    return true;
}
int minEatingSpeed(vector<int>&piles,int h) 
{
    int left=1,right=INT_MIN;
    for(auto j:piles)
    {
        right=max(right,j);
    }
    while(left<=right)
    {
        int mid=(left+right)/2;
        if(could_eat(piles,h,mid))
        {
            right=mid-1;
        }
        else
        {
            left=mid+1;
        }
    }
    return left;
}

vector<int> solve() {
    vector<int> r;

    int n, e;
    vector<int> piles;
    cin>>n;
    while(n--) {
        cin>>e;
        piles.push_back(e);
    }
    cin>>e;
    r.push_back(minEatingSpeed(piles, e));

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