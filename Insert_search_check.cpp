#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long

#define all(x) x.begin(),x.end()
#define nl endl
#define FOR(i,n) for(int i = 0; i < n; i++)
#define pb push_back

const int N = 1e7 + 10;
const ll MOD = 1e7 + 1;

struct Node {
    Node *links[26];
    bool b1 = false;

    // Check if refrence trie is present or not
    bool find(char ch) {
        return (links[ch - 'a'] != NULL);
    }

    // creating refrence trie;
    void put(char ch, Node *node) {
        links[ch - 'a'] = node;
    }

    // next node for traversal
    Node *go(char ch) {
        return links[ch - 'a'];
    }

    // Set flag true at the end
    void setEnd() {
        b1 = true;
    }

    // Check if word is completed or not
    bool isEnd() {
        return b1;
    }
};

class Trie {
private:
    Node *root;

public:
    Trie() {
        root = new Node();
    }

    void insert(string word) {
        // initialize dummy node pointing root node
        Node *node = root;
        for (int i = 0; i < word.size(); i++) {
            if (!node->find(word[i])) {
                node->put(word[i], new Node());
            }
            node = node->go(word[i]);
        }
        node->setEnd();
    }

    bool search(string word) {
        Node *node = root;
        for (int i = 0; i < word.size(); i++) {
            if (!node->find(word[i])) {
                return false;
            }
            node = node->go(word[i]);
        }
        return node->isEnd();
    }

    bool startWith(string prefix) {
        Node *node = root;
        for (int i = 0; i < prefix.size(); i++) {
            if (!node->find(prefix[i])) {
                return false;
            }
            node = node->go(prefix[i]);
        }
        return true;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n = 5;
    int q[5] = {1, 1, 2, 3, 2};
    string val[5] = {"hello", "help", "help", "hel", "hel"};

    Trie trie;

    for (int i = 0; i < 5; i++) {
        if (q[i] == 1) {
            trie.insert(val[i]);
            cout << val[i] << " inserted in trie\n";
        }
        else if (q[i] == 2) {
            if (trie.search(val[i]))     cout << val[i] << " is present in trie\n";
            else                        cout << val[i] << " Not present\n";
        }
        else {
            if (trie.startWith(val[i]))  cout << "Yes there exist words starting with " << val[i] << nl;
            else                        cout << val[i] << " Not present\n";
        }
    }

    return 0;
}