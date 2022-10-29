class Solution {
public:
    int countArrangement(int n) {
        std::vector<int> nums(n);
        
        std::iota(nums.begin(), nums.end(), 1);
        
        int res = 0;
        
        std::function<void (std::vector<int>&, int)> dfs = [&res, &dfs, n](std::vector<int> &nums, int i)
        {
            if (i == n + 1)
            {
                res += 1;
                return;
            }
            
            for (int j = 0; j < nums.size(); ++j)
            {
                if (not (i % nums[j] and nums[j] % i))
                {
                    std::vector<int> copy_v = nums;
                    copy_v.erase(copy_v.begin() + j);
                    dfs(copy_v, i + 1);
                }
            }
        };
        
        dfs(nums, 1);
        
        return res;
    }
};
