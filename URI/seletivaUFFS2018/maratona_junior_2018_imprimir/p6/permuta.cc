#include <iostream>
#include <vector>
using namespace std;

const uint64_t MPF = 1e9+7;

uint64_t expbin(uint64_t a, uint64_t e, uint64_t m, uint64_t acc) {
    if (e == 0) return acc;
    if (e % 2 == 1) return expbin(a, e-1, m, (acc * a) % m);
    return expbin((a * a) % m, e/2, m, acc);
}

int main() {
    string s;
    cin >> s;

    vector<uint64_t> freqs(26, 0);
    vector<uint64_t> facs(s.size()+1);
    facs[0] = 1;
    for(uint64_t i = 1; i < facs.size(); ++i) {
        facs[i] = (facs[i-1] * i) % MPF;
    }

    for(char c : s) {
        freqs[c - 'a']++;
    }


    uint64_t numer = facs[s.size()];
    uint64_t denom = 1;

    for(uint64_t f : freqs) {
        denom = (denom * facs[f]) % MPF;
    }

    uint64_t result = numer * expbin(denom, MPF-2, MPF, 1L);

    cout << (result % MPF) << '\n';


    return 0;
}
