bool checkForTarget(vector& nums, int target) {

    int left = 0;

    int right = nums.size() - 1;

    while (left < right) {

        int curr = nums[left] + nums[right];

        if (curr == target) {

            return true;

        }

        if (curr > target) {

            right--;

        } else {

            left++;

        }

    }

    return false;

}