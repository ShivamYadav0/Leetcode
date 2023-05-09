class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int sr=0 , er=matrix.size()-1 , sc=0 , ec=matrix[0].size()-1 ;
        vector<int>ans;
        while(sr<=er&&sc<=ec){
            for(int i=sc;sr<=er&&i<=ec;i++){
                ans.push_back(matrix[sr][i]);
            }
            sr++;
             for(int i=sr;sc<=ec&&i<=er;i++){
                 ans.push_back(matrix[i][ec]);
            }
            ec--;
            for(int i=ec;sr<=er&&i>=sc;i--){
                 ans.push_back(matrix[er][i]);
            }
            er--;
            for(int i=er;sc<=ec&&i>=sr;i--){
                 ans.push_back(matrix[i][sc]);
            }
            sc++;
            
        }
        return ans;
    }
};