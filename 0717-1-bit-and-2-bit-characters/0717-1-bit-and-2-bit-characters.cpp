class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        bits.pop_back();
        int n = bits.size();

        if (n == 0 || bits.back() == 0)
            return true;

        int ones = 0;        
        for (int i = n - 1; i >= 0 && bits[i] == 1; i--)
            ones++;

        return ~ones & 1;
    }
};
