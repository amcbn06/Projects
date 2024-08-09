template<char FIRST = 'a', int ALPHABET = 26>
struct Trie {
    struct TrieNode {
        int words = 0; // how many words end in the current node
        int suffixes = 0; // how many words have the current prefix
        TrieNode* next[ALPHABET] = {};
    } *root;
    Trie() : root(new TrieNode) {}
    // insert the string `str` in the Trie
    void insert(const string& str) {
        TrieNode* cur = root;
        cur->suffixes++;
        for (auto& ch : str) {
            if (cur->next[ch - FIRST] == nullptr) {
                cur->next[ch - FIRST] = new TrieNode;
            }
            cur = cur->next[ch - FIRST];
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
            cur = cur->next[ch - FIRST];
            cur->suffixes--;
        }
        cur->words--;
    }
    // how many occurences does the string `str` have in the Trie
    int count(const string& str) {
        TrieNode* cur = root;
        for (auto& ch : str) {
            if (cur->next[ch - FIRST] == nullptr) {
                return 0;
            }
            cur = cur->next[ch - FIRST];
        }
        return cur->words;
    }
    // the length of the longest common prefix of string `str` with a word from the Trie
    int lcp(const string& str) {
        TrieNode* cur = root;
        if (cur->suffixes == 0) { // no words in Trie
            return 0;
        }
        int length = 0;
        for (auto& ch : str) {
            if (cur->next[ch - FIRST] == nullptr) {
                break;
            }
            cur = cur->next[ch - FIRST];
            if (cur->suffixes == 0) { // no words with the current prefix in Trie
                break;
            }
            length++;
        }
        return length;
    }
    void print_all(TrieNode* cur = root, string str = "") {
        if (cur->words > 0) {
            cout << str << sp << cur->words << nl;
        }
        for (int i = 0; i < ALPHABET; ++i) {
            if (cur->next[i] != nullptr) {
                str += char(FIRST + i);
                print_all(cur->next[i], str);
                str.pop_back();
            }
        }
    }
};

using string_trie = Trie<'a', 26>;
using digit_trie = Trie<'0', 10>;
using bit_trie = Trie<'0', 2>;
