class Solution {
public:
     int area(vector<int>& heights) {
        int n = heights.size();
        vector<int> leftSmall(n), rightSmall(n);
        stack<int> st;

        //filling left small
        for(int i = 0; i < n; i++){
            // removing elements greater than current element
            while(!st.empty() && heights[i] <= heights[st.top()]){
                st.pop();
            }
            if(st.empty()){
                leftSmall[i] = 0;
            }else{
                leftSmall[i] = st.top() + 1;
            }
            st.push(i);
        }

        while(!st.empty()){
            st.pop();
        }

        //filling for right small
        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && heights[i] <= heights[st.top()]){
                st.pop();
            }
            if(st.empty()){
                rightSmall[i] = n-1;
            }else{
                rightSmall[i] = st.top() - 1;
            }
            st.push(i);
        }

        int maxArea = INT_MIN;
        for(int i = 0; i < n; i++){
            maxArea = max(maxArea, (rightSmall[i] - leftSmall[i] + 1) * heights[i]);
        }

        return maxArea;
    }
    // 3 1 3 2 2
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int mx=0;
        vector<int>his(m);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
              if(matrix[i][j]=='1'){
                  his[j]+=1;
              }
              else{
                  his[j]=0; 
              }
            }
           
            mx=max(mx,area(his));
            
        }
        return mx;
    }
};