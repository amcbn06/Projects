// Precomputes the most significant bit (MSB) for each number in the range [0, valmax]
// Works by the clever observation that msb(x) = log2(x), and log2(x) = log2(x / 2) + 1
// Time complexity: O(valmax)
// Space complexity: O(valmax)

const int valmax = 1'000'000;
int msb[valmax + 1];

void precompute(){
    for (int i = 2; i <= valmax; ++i){
        msb[i] = msb[i >> 1] + 1;
    }
}
