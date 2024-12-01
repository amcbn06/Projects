const int ALPHABET = 26;
const char FIRST = 'a';
struct AhoCorasik {
    struct Node {
        int next[ALPHABET], go[ALPHABET], ends = false;
        int par = -1, last, link = -1;
        Node(int par = -1, char last = '$') : par(par), last(last) {
            fill(next, next + ALPHABET, -1);
            fill(go, go + ALPHABET, -1);
        }
    };
    vector<Node> nodes;
    vector<int> which;
    AhoCorasik() {
        nodes.emplace_back();
    }
    void add_string(const string& str) {
        int u = 0;
        for (auto& ch : str) {
            int c = ch - FIRST;
            if (nodes[u].next[c] == -1) {
                nodes[u].next[c] = nodes.size();
                nodes.emplace_back(u, ch);
            }
            u = nodes[u].next[c];
        }
        nodes[u].ends = true;
        // vedem in ce nod se termina fiecare string
        which.push_back(u);
    }
    void build() {
        for (int u = 0; u < nodes.size(); ++u) {
            get_link(u);
            for (int c = 0; c < ALPHABET; ++c) {
                go(u, c + FIRST);
            }
        }
    }
    int go(int u, char ch) {
        int c = ch - FIRST;
        if (nodes[u].go[c] == -1) {
            if (nodes[u].next[c] != -1) {
                nodes[u].go[c] = nodes[u].next[c];
            }
            else {
                // mergem pe suffix link si incerca din nou
                nodes[u].go[c] = u ? go(get_link(u), ch) : 0;
            }
        }
        return nodes[u].go[c];
    }
    int get_link(int u) {
        if (nodes[u].link == -1) {
            if (u == 0 || nodes[u].par == 0) {
                nodes[u].link = 0;
            }
            else {
                nodes[u].link = go(get_link(nodes[u].par), nodes[u].last);
            }
        }
        return nodes[u].link;
    }
};
