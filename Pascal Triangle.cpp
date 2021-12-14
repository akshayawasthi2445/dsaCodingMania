class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows==1)return {{1}};
        if(numRows==2)return {{1},{1,1}};
        vector<vector<int>>V;
        vector<int>temp;
        temp.push_back(1);
        V.push_back(temp);
        temp.insert(temp.begin(),1);
        V.push_back(temp);
        vector<int> base;
        base = temp;
        vector<int>prev;
        prev=base;
        for(int k=3;k<=numRows;k++){
            vector<int>current = base;
            int i=0,j=1;
            while(j<k-1){
                current.insert(current.begin()+j,prev[i]+prev[j]);
                i++;j++;
            }
            prev = current;
            V.push_back(current);
        }
        return V;
        // vec.insert(vec.begin()+i,8);
    }
};