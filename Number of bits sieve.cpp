/* [A][M][C][B][N] / [K][R][I][P][6][8] */
#include <bits/stdc++.h>
using namespace std;

int main() {
    int nmax = 50000;
    vector<int> bitcount(nmax + 1);
    for (int p = 0; (1 << p) <= nmax; ++p) {
        for (int i = (1 << p); i <= nmax; i += (1 << (p + 1))) {
            for (int j = 0; j < (1 << p) && i + j <= nmax; j++) {
                bitcount[i + j]++;
            }
        }
    }
    cout << bitcount[69];
}
