class Solution {
    public void nextPermutation(int[] nums) {
        if(nums.length == 1) {
                return;
        }

        int i;
        for(i = nums.length-1; i > 0; i--) {
                if(nums[i-1] < nums[i]) {
                        break;
                }
        }

        if(i==0) {
                Arrays.sort (nums);
        } else {
                int min = i;
                for (int j = i + 1; j < nums.length; j++)
                {
                        if (nums[j] > nums[i-1] && nums[j] < nums[min])
                        {
                                min = j;
                        }
                }

                int temp = nums[i-1];
                nums[i-1] = nums[min];
                nums[min] = temp;

                Arrays.sort(nums, i, nums.length);
        }
    }
}