class Solution {

public:

    int maxProfit(vector<int>& prices) {

    int left = 0;

    int right = 1;

    int sum = 0;

    if(prices.size()==2){

        return max(0,prices[right]-prices[left]);

    }

    while (right< prices.size()-1){

    if(prices[right]> prices[right+1]){

        if(prices[left]< prices[right]){

        sum += prices[right] - prices[left];

        }

        left = right;

    }

    if(prices[right]<prices[left]){

        left = right;

    }

    right++;

    if(right == prices.size()-1){

        sum += max(0,prices[right]-prices[left]);

    }

}

return sum;

}

};