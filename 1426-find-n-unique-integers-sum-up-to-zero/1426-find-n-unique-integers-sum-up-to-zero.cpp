class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> results; 
        if(n%2!=0){
            results.push_back(0);
        }
        for(int i =1; i<=n/2;i++){
            results.push_back(i);
            results.push_back(-i);
        }
        return results;
    }
};