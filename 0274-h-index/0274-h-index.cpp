class Solution {
public:
    int hIndex(vector<int>& citations) {
        std::map<int, int> frequency;
        for (int c : citations) {
            if (c > 0)
                frequency[c]++;
        }
        
        int runningSum = 0;  
        for (auto it = frequency.rbegin(); it != frequency.rend(); ++it) {
            int key = it->first; 
            int count = it->second; 
            runningSum += count;   
            if (runningSum >= key) {
                return key;
            }

            auto nextIt = std::next(it);
            if (nextIt != frequency.rend()) {
                int nextKey = nextIt->first;
                if (runningSum > nextKey && runningSum < key) {
                    return runningSum;
                }
            }
        }
        

        return runningSum;
    }
};
