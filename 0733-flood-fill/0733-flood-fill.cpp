class Solution {
public:
    void dfs(int row,int col,vector<vector<int>>& ans,int color,int inic,vector<vector<int>>& image,int n,int m,int drow[],int dcol[])
    {
        ans[row][col]=color;
        for(int i = 0;i<4;i++)
        {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol]==inic && ans[nrow][ncol]!=color)
            {
                dfs(nrow,ncol,ans,color,inic,image,n,m,drow,dcol);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc]==color) return image;
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>> ans = image;
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        ans[sr][sc] = color;
        int inic = image[sr][sc];
        
        dfs(sr,sc,ans,color,inic,image,n,m,drow,dcol);
        return ans;
    }
};