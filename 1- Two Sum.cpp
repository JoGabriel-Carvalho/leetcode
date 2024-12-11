#include <iostream>
#include <vector>
using namespace std;

vector<int> twoSum(const vector<int>& nums, const int target) {
    for (int i = 0; i < nums.size(); i++) {
        for (int j = 0; j < nums.size(); j++) {
            if (nums[i] + nums[j] == target) {
                return {i, j};
            }
        }
    }

    return {-1, -1};
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 13;

    vector<int> result = twoSum(nums, target);

    cout << result[0] << " " << result[1];

    return 0;
}
