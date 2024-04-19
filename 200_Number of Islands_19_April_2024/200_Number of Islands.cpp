class Solution {
public:
    void dfs(vector<vector<char>>& grid , int i , int j ,vector<vector<bool>>&visited){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j] == '0' || visited[i][j] == true){
            return;
        }
        visited[i][j]=true;
        dfs(grid , i-1 , j , visited);
        dfs(grid , i , j+1 , visited);
        dfs(grid , i+1 , j , visited);
        dfs(grid , i , j-1 , visited);
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>>visited(n , vector<bool>(m,false));
        int islands=0;
        for(int i=0; i<n ; i++)
        {
            for(int j=0; j<m ; j++)
            {
                if(visited[i][j]==false && grid[i][j] == '1'){
                    dfs(grid , i , j , visited);
                    islands++;
                }
            }
        }
        return islands;
    }
};