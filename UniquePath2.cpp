class Solution {
public:
    void findPath(vector<vector<int>>& obstacleGrid,int i,int j,int& countPath){
        if(i==obstacleGrid.size() || j==obstacleGrid[0].size())return;
        if(obstacleGrid[i][j]==1)return;
        if(i==obstacleGrid.size()-1 && j==obstacleGrid[0].size()-1){
            countPath+=1;
            return;
        }
        
        findPath(obstacleGrid,i,j+1,countPath);
        findPath(obstacleGrid,i+1,j,countPath);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int countPath = 0;
        findPath(obstacleGrid,0,0,countPath);
        return countPath;
    }
};