class KthLargest {
public:
   priority_queue<int,vector<int>,greater<int>> pq;
    int K;
    KthLargest(int k, vector<int>& nums) {
        K=k;
        for(int i=0;i<nums.size();i++)
        {
            pq.push(nums[i]);
            if(pq.size()>k) pq.pop();  //min element will be poped
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size()>K) pq.pop();  //min element will be poped
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */