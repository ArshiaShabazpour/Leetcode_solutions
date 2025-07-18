#include <vector>
#include <unordered_map>
#include <functional>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> pre;
        for (auto &e : prerequisites)
            pre[e[0]].push_back(e[1]);

        vector<int> state(numCourses, 0); // 0 unvisited, 1 visiting, 2 done

        function<bool(int)> dfs = [&](int course) -> bool {
            if (!pre.count(course) || pre[course].empty()) {
                state[course] = 2;
                return true;
            }
            if (state[course] == 1) return false; 
            if (state[course] == 2) return true;

            state[course] = 1;
            for (int p : pre[course]) {
                if (!dfs(p)) return false;
            }
            pre[course].clear();
            state[course] = 2;
            return true;
        };

        for (int c = 0; c < numCourses; ++c)
            if (!dfs(c)) return false;

        return true;
    }
};
