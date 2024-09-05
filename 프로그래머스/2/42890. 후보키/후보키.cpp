#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int solution(vector<vector<string>> relation) {
    int n = relation[0].size();
    vector<int> candidates;

    for (int i = 1; i < (1 << n); ++i) {
        set<string> s;
        bool unique = true;

        for (int j = 0; j < relation.size(); ++j) {
            string temp = "";
            for (int k = 0; k < n; ++k) {
                if (i & (1 << k)) temp += relation[j][k];
            }
            if (s.find(temp) != s.end()) {
                unique = false;
                break;
            }
            s.insert(temp);
        }

        if (unique) candidates.push_back(i);
    }

    vector<int> final_candidates;
    for (int i = 0; i < candidates.size(); ++i) {
        bool minimal = true;
        for (int j = 0; j < final_candidates.size(); ++j) {
            if ((candidates[i] & final_candidates[j]) == final_candidates[j]) {
                minimal = false;
                break;
            }
        }
        if (minimal) final_candidates.push_back(candidates[i]);
    }

    return final_candidates.size();
}
