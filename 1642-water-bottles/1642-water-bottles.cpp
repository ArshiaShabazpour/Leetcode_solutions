class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int sum =0;
        while(numBottles/numExchange>0){
            int temp = numBottles%numExchange;
            sum +=numBottles -temp;
            numBottles /= numExchange;
            numBottles +=temp;
        }
        return sum+numBottles ;
    }
};