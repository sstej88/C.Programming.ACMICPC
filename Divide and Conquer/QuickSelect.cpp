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

void merge(vector<int> &nums, int i, int k, int j, int l, vector<int> &output) {
    if(i>k) {
        for(int index=j; index<=l; index++) {
            output.push_back(nums.at(index));
        }
        return;
    }
    else if(j>l) {
        for(int index=i; index<=k; index++) {
            output.push_back(nums.at(index));
        }
        return;
    }
    else {
        if(nums.at(i)<=nums.at(j)) {
            output.push_back(nums.at(i));
            merge(nums, i+1, k, j, l, output);
        }
        else if(nums.at(j)<=nums.at(i)) {
            output.push_back(nums.at(j));
            merge(nums, i, k, j+1, l, output);
        }
    }
}

void mergeSort(vector<int> &nums, int s, int e) {
    if(s>=e) {
        return;
    }
    else {
        vector<int> aux;
        int mid = s+(e-s)/2;
        mergeSort(nums, s, mid);
        mergeSort(nums, mid+1, e);
        merge(nums, s, mid, mid+1, e, aux);
        
        // aux auxillary array is has sorted values of nums from s to e. So copy them to nums array
        int j = 0;
        for(int i=s; i<=e; i++) {
            nums.at(i) = aux.at(j);
            j++;
        }
    }
}

void swap(vector<int> &nums, int i, int j) {
    int temp = nums.at(i);
    nums.at(i) = nums.at(j);
    nums.at(j) = temp;
}

void quickSelect(vector<int> &nums, int start, int end, int pivot, int k) {
    int i = start;
    int j = start+1;
    if(nums.at(start)>pivot) {
        swap(nums, start, pivot);
    }
    else {
        for(j=j; j<=end; j++) {
            if(nums.at(j)<nums.at(pivot)) {
                i++;
                swap(nums, i, j);
            }
        }
        if(nums.at(i+1)>nums.at(pivot)) {
            swap(nums, i+1, pivot);
            pivot = i+1;
        }
        for(auto x: nums) {
            cout<<x<<" ";
        }
        cout<<endl;
    }
    cout<<i<<" - "<<nums.size()-k<<" - "<<pivot<<" - "<<" - "<<j<<endl;
    if(pivot==nums.size()-k) {
        cout<<nums.at(pivot)<<endl;
        return;
    }
    else if(pivot>nums.size()-k) {
        quickSelect(nums, start, pivot-2, pivot-1, k);
    }
    else {
        quickSelect(nums, pivot+1, end, end+1, k);
    }
}

void kthLargestNumber(vector<int>& nums, int k) {
    quickSelect(nums, 0, nums.size()-2, nums.size()-1, 1);
}

vector<int> solve() {
    vector<int> r;

    int n;
    int e;
    vector<int> nums;
    cin>>n;
    while(n--) {
        cin>>e;
        nums.push_back(e);
    }

    kthLargestNumber(nums, 3); // Find 4th largest element in an array

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