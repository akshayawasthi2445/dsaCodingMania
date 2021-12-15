class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==1)return 0;
        int initialstock = prices[0];
        int profit = 0;
        for(int i=1;i<prices.size();i++){
            if(prices[i]<initialstock){
                initialstock = prices[i];
            }
            else if(profit<(prices[i]-initialstock)){
                profit = prices[i]-initialstock;
            }
        }
        return profit;
    }
};