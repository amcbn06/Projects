// stack alike Range Minimum Querry
// - push x: adds and `x` to the end of the array
// ~ Time compexity: logarithmic in size
// - pop: removes the element at the end of the array
// ~ Time compexity: logarithmic in size
// - querry i j: returns the minimum value in the range [i, j]
struct stackRMQ {
    vector<int> rmq[21];
    int len = 0;
    stackRMQ() {}
    void push(int x) {
        rmq[0].push_back(x);
        for (int i = 1; (1 << i) <= len + 1; ++i) 
            rmq[i].push_back(min(rmq[i - 1][len - (1 << i) + 1], rmq[i - 1][len - (1 << (i - 1)) + 1]));
        len++;
    }
    void pop() {
        assert(len > 0);
        for (int i = 0; (1 << i) <= len; ++i)
            rmq[i].pop_back();
        len--;
    }
    int querry(int i, int j) {
        assert(0 <= i && i <= n && 0 <= j && j <= n);
        int k = log2(j - i + 1);
        return min(rmq[k][i], rmq[k][j - (1 << k) + 1]);
    }
};
