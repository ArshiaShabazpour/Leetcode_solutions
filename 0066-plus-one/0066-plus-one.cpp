class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry =0;
        int n = digits.size()-1;

        while(digits[n]==9 && n>0){
            digits[n]=0;
            n--;
        }
        if(n ==0 && digits[n]==9){
            digits[n]=0;
            digits.insert(digits.begin(),1);
        }
        else{
            digits[n] +=1;
        }
        return digits;
    }
};