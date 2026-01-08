#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm> // for std::max

using namespace std;

int main() {
    vector<int> owo {5, 8, 2, 3, 1, 10, 12, 14, 13, 4, 5, 6};
    
    if (owo.empty()) return 0;

    int longest = 0;
    unordered_set<int> hehe;

    // Put all elements into the set
    for (auto iwi : owo) {
        hehe.insert(iwi);
    }

    for (auto uwu : hehe) {
        // Only start a sequence if 'uwu' is the start of a sequence
        // (i.e., uwu-1 is not in the set)
        if (hehe.find(uwu - 1) == hehe.end()) {
            int cnt = 1;
            int x = uwu;

            while (hehe.find(x + 1) != hehe.end()) {
                x = x + 1;
                cnt++;
            }
            
            // Update longest only when a sequence is found
            longest = max(longest, cnt);
        }
    }

    cout << "Longest consecutive sequence length: " << longest << endl;

    return 0;
}