class Solution {
public:
    int min(int a,int b){
        if(a<b)return a;
        else return b;
    }
    int findCost(vector<int>& position,int label){
        int cost = 0;
        if(label==0){
            for(int i=0;i<position.size();i++){
                if(position[i]%2!=0)
                    cost+=1;
            }
        }
        else{
            for(int i=0;i<position.size();i++){
                if(position[i]%2==0)
                    cost+=1;
            }
        } 
        return cost;
    }
    int minCostToMoveChips(vector<int>& position) {
        int evenpossteps = findCost(position,0);
        int oddpossteps = findCost(position,1);
        return min(evenpossteps,oddpossteps);
    }
};