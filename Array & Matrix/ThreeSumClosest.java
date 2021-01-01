class Solution {
    public int threeSumClosest(int[] nums, int target) {
        if(nums.length < 3) {
                return 0;
        }

        Arrays.sort (nums);
        int minDiff = Integer.MAX_VALUE, ans = 0;
        for (int i = 0; i < nums.length-2; i++) {
                
                        int diff = target-nums[i];
                        int left = i + 1;
                        int right = nums.length - 1;

                        while (left < right) {
                                int tmpSum = nums[left] + nums[right];
                                int sum = nums[i]+nums[left]+nums[right];
                                
                            if (tmpSum > diff) {
                                        right--;
                                } else if (tmpSum < diff) {
                                        left++;
                                } else {
                                        return sum;
                                }

                                if(minDiff > Math.abs (diff-tmpSum)) {
                                        ans = sum;
                                        minDiff = Math.abs (diff-tmpSum);
                                }
                        }
                
        }

        return ans;
    }
}