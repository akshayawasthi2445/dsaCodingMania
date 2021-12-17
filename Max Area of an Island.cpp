class Solution {
public:
    
    int maxFind(int a,int b){
        if(a>=b)
            return a;
        else
            return b;
    }
    
    void checker(vector<vector<int>>& grid,int i,int j,int& currmax){
        if(i>=grid.size() || j>=grid[0].size() || i<0 || j<0 || grid[i][j]!=1) return;
        
        grid[i][j] = -1;
        currmax+=1;
        
        
        checker(grid,i-1,j,currmax);
        checker(grid,i+1,j,currmax);
        checker(grid,i,j+1,currmax);
        checker(grid,i,j-1,currmax);
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxval = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                int currmax = 0;
                if(grid[i][j]==1){
                    checker(grid,i,j,currmax);
                    maxval = max(maxval,currmax);
                } 
            }
        }
        return maxval;
    }
};