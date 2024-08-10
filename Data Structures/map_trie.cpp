struct Trie {
    struct TrieNode {
        int words = 0; // how many words end in the current node
        int suffixes = 0; // how many words have the current prefix
        map<char, TrieNode*> next;
    } *root;
    Trie() : root(new TrieNode) {}
    // insert the string `str` in the Trie
    void insert(const string& str) {
        TrieNode* cur = root;
        cur->suffixes++;
        for (auto& ch : str) {
            if (!cur->next.count(ch)) {
                cur->next[ch] = new TrieNode;
            }
            cur = cur->next[ch];
            cur->suffixes++;
        }
        cur->words++;
    }
    // erase the string `str` from the Trie -> no actual memory deletion occurs
    void erase(const string& str) {
        if (this->count(str) == 0) { // no occurence in Trie
            return;
        }
        TrieNode* cur = root;
        cur->suffixes--;
        for (auto& ch : str) {
            cur = cur->next[ch];
            cur->suffixes--;
        }
        cur->words--;
    }
    // how many occurences does the string `str` have in the Trie
    int count(const string& str) {
        TrieNode* cur = root;
        for (auto& ch : str) {
            if (!cur->next.count(ch)) {
                return 0;
            }
            cur = cur->next[ch];
        }
        return cur->words;
    }
    // prints all words in Trie
    void print_all(TrieNode* cur, string str) {
        if (cur->words > 0) {
            cout << "  " << str << nl;
        }
        for (auto& it : cur->next) {
            str += it.first;
            print_all(it.second, str);
            str.pop_back();
        }
    }
};
