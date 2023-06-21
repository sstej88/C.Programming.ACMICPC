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

struct segmentTree {
    int numberOfNodes;
    bool isTreeBuilt;
    vector<int> tree;

    void initializeTree(vector<int> leafNodes) {
        this->numberOfNodes = leafNodes.size()-1;
        this->tree.resize(4*leafNodes.size(), 0);
        buildTree(leafNodes, 0, leafNodes.size()-1, 0);
        this->isTreeBuilt = true;
    }
    void buildTree(vector<int> leafNodes, int low, int high, int node) {
        int mid = low+(high-low)/2;
        if(low==high) {
            this->tree.at(node) = leafNodes.at(mid);
            return;
        }
        buildTree(leafNodes, low, mid, 2*node+1);
        buildTree(leafNodes, mid+1, high, 2*node+2);
        // logic for finding sum in range
        this->tree.at(node) = this->tree.at(2*node+1)+this->tree.at(2*node+2);
    }

    int searchTree(int lowerBound, int upperBound, int low, int high, int node) {
        if(low > upperBound || high < lowerBound) { // No Overlapping
            return 0;
        }
        if(low >= lowerBound && high <= upperBound) { // Complete Overlapping
            return this->tree.at(node);
        }
        // Partial Overlapping
        int mid = low+(high-low)/2;
        int leftSidedNode = searchTree(lowerBound, upperBound, low, mid, 2*node+1);
        int rightSidedNode = searchTree(lowerBound, upperBound, mid+1, high, 2*node+2);
        return leftSidedNode+rightSidedNode;
    }

    int query(int lowerBound, int upperBound) {
        return searchTree(lowerBound, upperBound, 0, numberOfNodes, 0);
    }

    void traverseAndUpdateTree(int low, int high, int node, int value, int index) {
        if(low==high) {
            if(low==index) {
                this->tree.at(node) = value;
            }
            return;
        }
        int mid = low+(high-low)/2;
        traverseAndUpdateTree(low, mid, 2*node+1, value, index);
        traverseAndUpdateTree(mid+1, high, 2*node+2, value, index);
        this->tree.at(node) = this->tree.at(2*node+1)+this->tree.at(2*node+2);
    }
    void updateLeafNode(int index, int value) {
        traverseAndUpdateTree(0, numberOfNodes, 0, value, index);
    }

    void display() {
        for(int i=0; i<tree.size(); i++) {
            cout<<this->tree.at(i)<<" ";
        }
        cout<<endl;
    }
};

struct fenwickTree {
    vector<int> tree;
    int size;

    void build(vector<int> nums) {
        this->size = nums.size()+1;
        tree.resize(size, 0);
        for(int i=0; i<nums.size(); i++) {
            buildFenwickTree(i, nums.at(i));
        }
    }

    void buildFenwickTree(int x, int n) {
        x++;
        while(x<=size) {
            this->tree.at(x) += n;
            x += (x&(-x));
        }
    }

    int query(int x, int y) {
        x++;
        y++;
        int sumX = 0;
        int sumY = 0;
        while(x>0) {
            sumX += this->tree.at(x);
            x-=(x&(-x));
        }
        while(y>0) {
            sumY += this->tree.at(y);
            y-=(y&(-y));
        }
        return sumY-sumX;
    }
};

struct squareRootDecomposition {
    int size;
    int blockSize;
    int numberOfBlocks;
    vector<int> blocksValue;
    vector<int> nums;

    void init(vector<int> arr) {
        this->nums = arr;
        this->size = arr.size();
        blockSize = sqrt(arr.size());
        numberOfBlocks = (arr.size()/blockSize) + 1;
        int sum = 0;
        for(int i=0; i<arr.size(); i++) {
            sum+=arr.at(i);
            if((i+1)%blockSize==0) {
                blocksValue.push_back(sum);
                sum = 0;
            }
        }
    }

    int query(int low, int high) {
        int result = 0;
        for(int i=low; i<=high;) {
            if((i+1)%blockSize==0 && (i+blockSize+1)<=high) {
                result+=nums.at(i);
                result += blocksValue.at((i+1)/blockSize);
                i+=blockSize+1;
            }
            else {
                result+=nums.at(i);
                i++;
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

void mergeTwoSortedArrays(vector<int> &nums, int low1, int high1, int low2, int high2, vector<int> &output) {
    if(low1>high1) {
        for(int i=low2; i<=high2; i++) {
            output.push_back(nums.at(i));
        }
        return;
    }
    if(low2>high2) {
        for(int i=low1; i<=high1; i++) {
            output.push_back(nums.at(i));
        }
        return;
    }
    int i = low1;
    int j = low2;
    if(nums.at(i)>nums.at(j)) {
        output.push_back(nums.at(j));
        mergeTwoSortedArrays(nums, low1, high1, low2+1, high2, output);
    }
    if(nums.at(i)<=nums.at(j)) {
        output.push_back(nums.at(i));
        mergeTwoSortedArrays(nums, low1+1, high1, low2, high2, output);
    }
}

void mergeSort(vector<int> &nums, int low, int high) {
    vector<int> output;
    if(low>=high) {
        return;
    }
    int mid = low+(high-low)/2;
    mergeSort(nums, low, mid);
    mergeSort(nums, mid+1, high);
    mergeTwoSortedArrays(nums, low, mid, mid+1, high, output);

    int i = low;
    for(auto x: output) {
        nums.at(i) = x;
        i++;
    }
}

class Graph {
    public:
    int numberOfNodes;
    list<int> *l;

    Graph(int n) {
        this->numberOfNodes = n;
        l = new list<int>[numberOfNodes];
    }

    void addEdge(int i, int j, bool unDirected = true) {
        l[i].push_back(j);
        if(unDirected) {
            l[j].push_back(i);
        }
    }

    void displayGraph() {
        for(int i=0; i<numberOfNodes; i++) {
            cout<<i<<" -> ";
            for(auto x: l[i]) {
                cout<<x<<" ";
            }
            cout<<endl;
        }
    }

    unordered_map<int, bool> visited;
    void bfs(queue<int> &q) {
        if(visited.size()==numberOfNodes) {
            while(!q.empty()) {
                cout<<q.front()<<" ";
                q.pop();
            }
            return;
        }
        visited[q.front()] = true;
        for(auto x: l[q.front()]) {
            if(visited.count(x)==0) {
                q.push(x);
                visited[x] = true;
            }
        }
        cout<<q.front()<<" ";
        q.pop();
        bfs(q);
    }

    void dfs(int node) {
        if(visited.size()==numberOfNodes) {
            cout<<node<<" ";
            return;
        }
        visited[node] = true;
        for(auto x: l[node]) {
            if(visited.count(x)==0) {
                visited[x] = true;
                dfs(x);
            }
        }
        cout<<node<<" ";
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void displayGraph(TreeNode* root) {
        if(root==NULL) {
            return;
        }
        displayGraph(root->left);
        displayGraph(root->right);
        TreeNode *temp = root->left;
        root->left = root->right;
        root->right = temp;
    }
    TreeNode* invertTree(TreeNode* root) {
        displayGraph(root);
        return root;
    }
};

vector<int> solve() {
    vector<int> nums;

    

    return nums;
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