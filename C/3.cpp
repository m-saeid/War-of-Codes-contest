#include <iostream>
#include <vector>
using namespace std;

bool targetSum(const vector<int>& nums, int target) {
    int n = nums.size();
    // بررسی تمام زیرمجموعه‌ها
    for (int i = 1; i < (1 << n); ++i) {
        int sum = 0;
        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) {
                sum += nums[j];
            }
        }
        if (sum == target) {
            return true;
        }
    }
    return false;
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    int target;
    cin >> target;

    if (targetSum(nums, target))
        cout << "yes\n";
    else
        cout << "no\n";
    
    return 0;
}
