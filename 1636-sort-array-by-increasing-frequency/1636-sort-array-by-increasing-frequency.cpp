class Solution 
{
public:
    vector<int> frequencySort(vector<int>& nums) 
    {
         std::unordered_map<int,int> value_frequency_map{};
         for(const int value : nums)
         {
            ++value_frequency_map[value];
         }   

         std::sort(nums.begin(), nums.end(), [&value_frequency_map]
         (int value_A, int value_B) -> bool
         {
            if(value_frequency_map[value_A] == 
               value_frequency_map[value_B])
            {
                return value_A > value_B;
            }
            
            return 
            value_frequency_map[value_A] < 
            value_frequency_map[value_B];
         });

         return nums;
    }
};