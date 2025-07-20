#include <string>
#include <vector>
#include <queue>
#include <utility>

class Solution {
public:
    int minMutation(std::string startGene, std::string endGene, std::vector<std::string>& bank) {
        if (startGene == endGene) return 0;
        bool found = false;
        for (const auto& gene : bank) {
            if (gene == endGene) {
                found = true;
                break;
            }
        }
        if (!found) return -1;

        std::queue<std::pair<std::string, int>> q;
        q.push({startGene, 0});

        while (!q.empty()) {
            auto [word, steps] = q.front();
            q.pop();

            for (int i = 0; i < bank.size(); ++i) {
                int diff = 0;
                for (int j = 0; j < word.size(); ++j) {
                    if (bank[i][j] != word[j]) {
                        ++diff;
                        if (diff > 1) break;
                    }
                }
                if (diff == 1) {
                    if (bank[i] == endGene) return steps + 1;

                    q.push({bank[i], steps + 1});
                    bank[i] = bank.back();
                    bank.pop_back();
                    --i; 
                }
            }
        }

        return -1;
    }
};
