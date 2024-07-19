class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> row;
        vector<int> column;

        // For Rows: Find the minimum value in each row
        for (int i = 0; i < matrix.size(); ++i) {
            int ansr = INT_MAX;
            for (int j = 0; j < matrix[i].size(); ++j) {
                ansr = min(ansr, matrix[i][j]);
            }
            row.push_back(ansr);
        }

        // For Columns: Find the maximum value in each column
        for (int j = 0; j < matrix[0].size(); ++j) {
            int ansc = INT_MIN;
            for (int i = 0; i < matrix.size(); ++i) {
                ansc = max(ansc, matrix[i][j]);
            }
            column.push_back(ansc);
        }
        vector<int> ans;
        for(int i=0;i<row.size();i++){
            auto it = find(column.begin(),column.end(),row[i]);
            if(it != column.end()){
                ans.push_back(row[i]);
            }
        }
        
        return ans;
    }
};