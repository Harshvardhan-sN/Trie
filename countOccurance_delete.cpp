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
    int cntEnd = 0;
    int cntPrefix = 0;

    bool find(char ch) {
        return (links[ch - 'a'] != NULL);
    }

    Node *go(char ch) {
        return links[ch - 'a'];
    }

    void put(char ch, Node *node) {
        links[ch - 'a'] = node;
    }

    void incEnd() {
        cntEnd++;
    }

    void incPrefix() {
        cntPrefix++;
    }

    void decEnd() {
        cntEnd--;
    }

    void decPrefix() {
        cntPrefix--;
    }

    int getEnd() {
        return cntEnd;
    }

    int getPrefix() {
        return cntPrefix;
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
        for (int i = 0; i < word.size(); i++) {
            if (!node->find(word[i])) {
                node->put(word[i], new Node());
            }
            node = node->go(word[i]);
            node -> incPrefix();
        }
        node->incEnd();
        cout << word << " INSERTED\n";
    }

    int wordFreq(string word) {
        Node *node = root;
        for (int i = 0; i < word.size(); i++) {
            if (!node->find(word[i])) {
                return 0;
            }
            else {
                node = node->go(word[i]);
            }
        }
        return node->getEnd();
    }

    int prefixFreq(string word) {
        Node *node = root;
        for (int i = 0; i < word.size(); i++) {
            if (!node->find(word[i]))    return false;
            else {
                node = node->go(word[i]);
            }
        }
        return node->getPrefix();
    }

    void deleteWord(string word) {
        Node *node = root;
        for (int i = 0; i < word.size(); i++) {
            if (!node->find(word[i]))    return;
            else {
                node = node->go(word[i]);
                node->decPrefix();
            }
        }
        node->decEnd();
        cout << "1 occurance of " << word << " DELETED\n";
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Trie T;
    T.insert("apple");
    T.insert("apple");
    T.insert("apps");
    T.insert("apps");

    string s1 = "apps";
    cout << "Count Words Equal to " << s1 << " " << T.wordFreq(s1) << nl;
    s1 = "abc";
    cout << "Count words equal to " << s1 << " " << T.wordFreq(s1) << nl;
    s1 = "ap";
    cout << "Count words starting with " << s1 << " " << T.prefixFreq(s1) << nl;
    s1 = "appl";
    cout << "Count words starting with " << s1 << " " << T.prefixFreq(s1) << nl;
    s1 = "apps";
    T.deleteWord(s1);
    cout << "Count words equal to " << s1 << " " << T.wordFreq(s1) << nl;

    return 0;
}