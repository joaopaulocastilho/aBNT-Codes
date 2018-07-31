#include <string>
#include <iostream>

constexpr int maxlen = 100;
constexpr int maxwords = 100;
constexpr int maxdict = 1'000;

constexpr char nl = '\n';

int edit_dist(const std::string &s1, const std::string &s2) {
    int D[maxlen + 1][maxlen + 1];
    for (int i = 0; i < maxlen + 1; ++i) D[0][i] = D[i][0] = i;
    for (int i = 1; i < static_cast<int>(s1.length() + 1); ++i) {
        for (int j = 1; j < static_cast<int>(s2.length() + 1); ++j) {
            int change_cost = D[i - 1][j - 1] + (s1[i - 1] != s2[j - 1]);
            int delete_cost = D[i - 1][j] + 1;
            int insert_cost = D[i][j - 1] + 1;
            D[i][j] = std::min(change_cost, std::min(delete_cost, insert_cost));
        }
    }
    return D[s1.length()][s2.length()];
}

int main() {
    std::string *outwords[maxwords];
    int dict_size = 0, word_count = 0;
    std::string dict[maxdict], inwords[maxwords];

    std::cin >> dict_size;
    for (int i = 0; i < dict_size; ++i) std::cin >> dict[i];

    std::cin >> word_count;
    for (int i = 0; i < word_count; ++i) std::cin >> inwords[i];

    for (int i = 0; i < word_count; ++i) {
        int mindist_j = 0;
        int mindist = maxlen + 1; // all edit distance <= maxlen
        const std::string& inword = inwords[i];

        for (int j = 0; j < dict_size; ++j) {
            const int dist = edit_dist(inword, dict[j]);

            if (dist == 0) { // word is correct
                mindist_j = j;
                break;
            } else if (dist < mindist) {
                mindist = dist;
                mindist_j = j;
            }
        }
        outwords[i] = &dict[mindist_j];
    }

    for (int i = 0; i < word_count; ++i)
        std::cout << *outwords[i] << (i + 1 < word_count ? ' ' : nl);
}
