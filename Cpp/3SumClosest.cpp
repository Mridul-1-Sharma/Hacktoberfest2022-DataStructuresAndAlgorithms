class Solution
{
	public:
	int threeSumClosest(vector<int>& nums, int target)
	{
		if(nums.size() < 3)
		{
			return INT_MAX;
		}
		sort(nums.begin(), nums.end());
		
		//int sum = accumulate(nums.begin(), nums.begin() + 3, 0);
		int sum = nums[0] + nums[1] + nums[2];

		vector<int>::size_type i, j, k;
		for(i = 0; i < nums.size(); ++i)
		{
			j = i + 1;
			k = nums.size() - 1;
			
			while(j < k)
			{
				int curSum = nums[i] + nums[j] + nums[k];
				if((curSum - target) > 0)
				{
					--k;
				}
				else if((curSum-target)==0)
				{
					return curSum;
				}
				else
				{
					++j;
				}
				if(abs(curSum - target) < abs(sum - target))
				{
					sum = curSum;
				}
			}//while
		}//for
		return sum;
	}
};
