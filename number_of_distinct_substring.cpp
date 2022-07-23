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

int sum = 0;
struct Node {
    Node *links[26];

    bool find(char ch) {
        return (links[ch - 'a'] != NULL);
    }
    void put(char ch, Node *node) {
        links[ch - 'a'] = node;
    }
    Node *go(char ch) {
        return links[ch - 'a'];
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
        Node *node = root;
        for (char &ch : word) {
            if (!node->find(ch)) {
                node->put(ch, new Node());
                sum++;
            }
            node = node->go(ch);
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Making class
    int test_case = 0;
    // cin>>test_case;
    while (test_case--) {
        Trie T;
        sum = 1;
        string s;   cin >> s;
        for (int i = 0; i < s.size(); i++) {
            T.insert(string(s.substr(i)));
        }
        cout << sum << nl;
    }

    // Without making class
    string s1 = "harsh";
    Node *root = new Node();
    int count = 1;  // 1 for empty substr
    int n = s1.length();

    for (int i = 0; i < n; i++) {
        Node *node = root;
        for (int j = i; j < n; j++) {
            if (!node->find(s1[j])) {
                node->put(s1[j], new Node());
                count++;
            }
            node = node->go(s1[j]);
        }
    }
    cout << count << nl;

    return 0;
}