#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<string>  v(2);
    cin >> v[0] >> v[1];

    sort(v.begin(), v.end());

    cout << v[0] << '\n' << v[1] << '\n';

    return 0;
}
