#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;



uint64_t gcd(uint64_t a, uint64_t b) {
    while (b != 0) {
        uint64_t x = b;
        b = a % b;
        a = x;
        //tie(a, b) = make_tuple(b, a % b);
    }
    return a;
}
 
uint64_t lcm(uint64_t a, uint64_t b) {
    return a * b / gcd(a, b);
}
 
/*
int main() {
    printf("%d %d %d\n", 3, 5, lcm(3, 5));
}
*/



int main() {
    int N;
    cin >> N;

    vector<pair<uint64_t, uint64_t> > tasks(N);

    for(int i = 0; i < N; ++i) {
        cin >> tasks[i].first  >> tasks[i].second;
    }

    uint64_t x = 1;
    for(int i = 0; i < N; ++i) {
        x = lcm(tasks[i].second, x);
    }
    //printf("lcm %llu\n", x);


    uint64_t y = 0;
    for(int i = 0; i < N; ++i) {
        y += tasks[i].first * (x / tasks[i].second);
    }

    //printf("y = %llu\n", y);
    bool result = y <= x;

    cout << (result ? "OK\n" : "FAIL\n");


}
