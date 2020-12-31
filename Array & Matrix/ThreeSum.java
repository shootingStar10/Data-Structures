class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> res = new ArrayList<> ();

        if(nums.length < 3) {
                return res;
        }

        Arrays.sort (nums);

        for (int i = 0; i < nums.length-2; i++) {
            if (i == 0 || (i > 0 && nums[i] != nums[i-1])) {
                int sum = 0 - nums[i];
                int left = i + 1;
                int right = nums.length - 1;

                while (left < right) {
                    int tmpSum = nums[left] + nums[right];
                    if (tmpSum > sum) {
                            right--;
                    } else if (tmpSum < sum) {
                            left++;
                    } else {
                        List<Integer> tmpRes = new ArrayList<> ();
                        tmpRes.add (nums[i]);
                        tmpRes.add (nums[left]);
                        tmpRes.add (nums[right]);

                        res.add (tmpRes);

                        while (left < right && nums[left] == nums[left + 1]) {
                                left++;
                        }

                        while (left < right && nums[right] == nums[right - 1]) {
                                right--;
                        }

                        left++;
                        right--;
                    }
                }
            }
        }

        return res;
    }
}