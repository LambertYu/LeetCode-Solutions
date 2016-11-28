/*
 *Given an array of integers, return indices of the two numbers such that they add up to a specific target.
 *You may assume that each input would have exactly one solution.
 *Example:
 *Given nums = [2,3,4,5,6,9,11,23,30,32], target = 10,
 *Because nums[2] + nums[4] = 4 + 6 = 10,
 *return [2, 4].
 *UPDATE (2016/2/13):
 *The return format had been changed to zero-based indices. Please read the above updated description carefully
 *Tag: Array, Hash Table
 
 *Author: Ethan YU
*/

#include <vector>
#include <iostream>

class Solution {
public:
	std::vector<int> twoSum(std::vector<int>& nums, int target);
};

/*
Look for the right pair starts from both ends.
Time:    O(n)
Space:    O(n)
*/
std::vector<int> Solution::twoSum(std::vector<int>& nums, int target) {
        std::vector<int> copy = nums;
        std::vector<int> answer;
        unsigned int start = 0, end = nums.size() - 1;
        sort(nums.begin(),nums.end());
        while( start != end){
            int sum = nums[start] + nums[end];
            if(sum == target){
                for(unsigned int i = 0; i < copy.size(); i++){
                    if(copy[i] == nums[start] || copy[i] == nums[end]){
                        answer.push_back(i);
                    }
                }
                return answer;
            }else if(sum > target){
                end--;
            }else{
                start++;
            }
        }
        return answer;
    }

int main(){
	int vec[10] = {2,3,4,5,6,9,11,23,30,32};
	int target = 10;
	std::vector<int> nums(vec, vec+10);
	Solution solu;
	std::vector<int> answer = solu.twoSum(nums,target);
    std::cout << "[" ;
	for (int i = 0; i < 2; ++i)
	{
		std::cout << answer[i];
        if(i == 0) std::cout << ",";
	}
	std::cout << "]" << std::endl;
	return 0;
}