class Solution {
public:   
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        //connections
         vector<vector<int>> graphr(k);
        vector<vector<int>> graphc(k);

        for (auto& cond : rowConditions) {
            int u = cond[0] - 1, v = cond[1] - 1;
            graphr[u].push_back(v);
            //indegree[v]++;
        }
        for (auto& cond : colConditions) {
            int u = cond[0] - 1, v = cond[1] - 1;
            graphc[u].push_back(v);
            //indegree[v]++;
        }
        vector<int> indegreeRow(k);
        for(auto &i:graphr){
            for(auto j: i){
                indegreeRow[j]++;
            }
        }

        vector<int> indegreeCol(k);
        for(auto &i:graphc){
            for(auto j: i){
                indegreeCol[j]++;
            }
        }

        queue<int>q1;
        for(int i=0;i<k;i++){
            if(indegreeRow[i]==0){
                q1.push(i);
            }
        }
        queue<int>q2;
        for(int i=0;i<k;i++){
            if(indegreeCol[i]==0){
                q2.push(i);
            }
        }

        vector<int>row;
        //front=q.front();
        while(!q1.empty()){
            int front=q1.front();
            q1.pop();

            //ans store
            row.push_back(front);

            for(auto &neighbour:graphr[front]){
                indegreeRow[neighbour]--;
                if(indegreeRow[neighbour]==0){
                    q1.push(neighbour);
                }
            }
        }
        vector<int>col;
        //front=q.front();
        while(!q2.empty()){
            int front=q2.front();
            q2.pop();

            //ans store
            col.push_back(front);

            for(auto &neighbour:graphc[front]){
                indegreeCol[neighbour]--;
                if(indegreeCol[neighbour]==0){
                    q2.push(neighbour);
                }
            }
        }

        if (row.size() != k || col.size() != k) {
            return {}; // Return an empty matrix if we can't sort all nodes
        }
        
        vector<int> rowPos(k), colPos(k);
        for(int i = 0; i < k; i++) {
            rowPos[row[i]] = i;
            colPos[col[i]] = i;
        }

        vector<vector<int>> res(k, vector<int>(k, 0));
        for(int i = 0; i < k; i++) {
            res[rowPos[i]][colPos[i]] = i + 1;
        }

    return res;

    }
};