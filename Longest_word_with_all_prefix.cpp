#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long

#define all(x) x.begin(),x.end()
#define nl endl
#define FOR(i,n) for(int i = 0; i < n; i++)
#define pb push_back

const int N = 1e7+10;
const ll MOD = 1e7+1;

struct Node{
    Node *links[26];
    bool b1 = false;

    bool find(char ch){
        return (links[ch - 'a'] != NULL);
    }
    void put(char ch, Node *node){
        links[ch - 'a'] = node;
    }
    Node *go(char ch){
        return links[ch - 'a'];
    }
    void setEnd(){
        b1 = true;
    }
    bool isEnd(){
        return b1;
    }
};

class Trie{
private:
    Node *root;
public:
    Trie(){
        root = new Node();
    }

    void insert(string word){
        Node *node = root;
        for(char &ch: word){
            if(!node->find(ch)){
                node->put(ch, new Node());
            }
            node = node->go(ch);
        }
        node->setEnd();
    }

    // Check for every prefix if true
    bool longest_word(string word){
        Node *node = root;
        for(char &ch: word){
            if(node->find(ch)){
                node = node->go(ch);
                if(!node->isEnd())      return false;
            }
            else    return false;
        }
        return true;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Trie trie;

    // input
    int n;  cin>>n;
    vector<string> words;
    for(int i=0;i<n;i++){
        string s;   cin>>s;
        words.pb(s);
        trie.insert(s);
    }

    string ans = "";
    // check every string
    for(auto &s: words){
        if(trie.longest_word(s)){
            if(s.size()>ans.size())     ans = s;    // for longest string
            else if(s.size()==ans.size())     ans = min(ans,s);     // if size is same then we want lexicographically small string
        }
    }

    if (ans=="")    ans = "None\n";
    cout<<ans;

    return 0;
}