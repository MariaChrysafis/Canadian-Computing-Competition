#include <bits/stdc++.h>
using namespace std;
struct Node {
    Node (char c) {
        this->child[0] = this->child[1] = nullptr;
        this-> c = c;
    }
    Node () {
        this->child[0] = this->child[1] = nullptr;
    }
    Node*child[2];
    char c;
};
Node* root;
void add_node (char c, string s) {
    Node *cur = root;
    for (int i = 0; i < s.size(); i++) {
        if (cur->child[s[i] - '0'] == nullptr) {
            if (i + 1 != s.size()) cur->child[s[i] - '0'] = new Node();
            else cur->child[s[i] - '0'] = new Node(c);
        }
        cur = cur->child[s[i] - '0'];
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    root = new Node();
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        string s;
        cin >> s;
        add_node(c, s);
    }
    string s;
    cin >> s;
    Node* cur = root;
    for (int i = 0; i < s.size(); i++) {
         cur = cur->child[s[i] - '0'];
         //cout << s[i] - '0' << '\n';
        if (i == s.size() - 1 || cur->child[s[(i + 1)] - '0'] == nullptr) {
            cout << cur->c;
            cur = root;
        }
    }
}
