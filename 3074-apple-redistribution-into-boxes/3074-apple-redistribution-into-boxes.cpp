class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(capacity.begin(),capacity.end(),std::greater<int>());
        int sum = 0;
        int counter =0;
        for(auto& fruit:apple){
            sum+=fruit;
        }
        while(sum>0){
            sum -=capacity[counter];
            counter++;
        }
        return counter;
    }
};