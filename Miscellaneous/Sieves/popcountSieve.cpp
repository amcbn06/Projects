// Precomputes the popcount for each number in the range [0, valmax]
// Works by iterating each bit from 0 to log2(valmax) and then iterating through each number that contains it
// Time complexity: O(valmax / 2 + valmax / 4 + valmax / 8 + ...) = O(valmax)
// Space complexity: O(valmax)

const int valmax = 1'000'000;
int popcount[valmax + 1];

void precompute(){
    for (int p = 0; (1 << p) <= valmax; ++p) {
        for (int i = (1 << p); i <= valmax; i += (1 << (p + 1))) {
            // bit p is present in the range [i, i + (1 << p) - 1]
            popcount[i]++;
            if (i + (1 << p) <= valmax) {
                popcount[i + (1 << p)]--;
            }
        }
    }
    for (int i = 1; i <= valmax; ++i){
        popcount[i] += popcount[i - 1];
    }
}
