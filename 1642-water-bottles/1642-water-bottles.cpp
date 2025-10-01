class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int sum =0;
        while(numBottles/numExchange>0){
            int temp = numBottles%numExchange;
            sum +=numBottles -temp;
            cout <<"temp: " <<temp << endl;
            numBottles /= numExchange;
            numBottles +=temp;
            cout <<"numBottles: " <<numBottles << endl;
        }
        return sum+numBottles ;
    }
};