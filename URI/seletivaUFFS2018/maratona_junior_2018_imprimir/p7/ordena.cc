#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<pair<string, string> >  v(N);
    for(auto & p : v) {
        cin >> p.second;
        p.first = p.second;
        std::transform(p.second.begin(), p.second.end(), p.first.begin(), ::tolower);
    }

    sort(v.begin(), v.end());

    for(auto & p : v) {
        cout << p.second << '\n';
    }

    return 0;
}
