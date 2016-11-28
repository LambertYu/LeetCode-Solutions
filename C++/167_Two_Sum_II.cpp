/*
*Given an array of integers that is already sorted in ascending order, 
*find two numbers such that they add up to a specific target number.
*The function twoSum should return indices of the two numbers such that 
*they add up to the target, where index1 must be less than index2. 
*Please note that your returned answers (both index1 and index2) are not zero-based.

*You may assume that each input would have exactly one solution.

*Input: numbers={2, 7, 11, 15}, target=9
*Output: index1=1, index2=2

*Tag: Array, Two Pointers, Binary Search
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
Space:    O(1)
*/
std::vector<int> Solution::twoSum(std::vector<int>& nums, int target) {
        std::vector<int> answer;
        unsigned int start = 0, end = nums.size() - 1;
        while( start != end){
            int sum = nums[start] + nums[end];
            if(sum == target){
                answer.push_back(start+1);
                answer.push_back(end+1);
                return answer;
            }else if(sum > target){
                end--;
            }else{
                start++;
            }
        }
        // no solution found
        if(start == end) {
            std::cout << "No two sum solution" << std::endl;
            exit(1);
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