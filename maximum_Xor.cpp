#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long

#define all(x) x.begin(),x.end()
#define nl endl
#define FOR(i, k, n) for(int i = k; i < n; i++)
#define pb push_back

const int N = 1e7+10;
const ll MOD = 1e7+1;

struct Node{
    Node *links[2];

    bool find(int x){
        return (links[x]!=NULL);
    }
    Node *go(int x){
        return links[x];
    }
    void put(int x, Node *node){
        links[x] = node;
    }
};

class Trie{
private:
    Node *root;
public:
    Trie(){
        root = new Node();
    }

    void insert(int n){     //.. Inserting the integer in binary form from msb to lsb
        Node *node = root;
        for(int i=31; i >= 0;i--){
            int bit = (n>>i) & 1;   //.. Checking all the bits set or not
            if(!node->find(bit)){
                node->put(bit, new Node());
            }
            node = node->go(bit);
        }
    }

    int getMax(int n){
        Node *node = root;
        int maxi = 0;
        for(int i=31;i>=0;i--){
            bool bit = (n>>i) & 1;
            if(node->find(!bit)){
                maxi = maxi | (1<<i);
                node = node->go(!bit);
            }
            else{
                node = node->go(bit);
            }
        }
        return maxi;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test_case;
    cin>>test_case;
    while(test_case--){
        Trie T;
        int maxi = INT_MIN;
        int n,m;    cin>>n>>m;
        vector<int> v2(m);
        FOR(i, 0, n) {
            int x;  cin>>x;
            T.insert(x);
        }
        FOR(i, 0, m){
            int x;  cin>>x;
            maxi = max(maxi,T.getMax(x));
        }
        cout<<maxi<<nl;
    }


    return 0;
}