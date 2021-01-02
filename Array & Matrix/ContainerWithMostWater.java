class Solution {
    public int maxArea(int[] height) {
        int max = Integer.MIN_VALUE, left = 0, right = height.length-1, water = 0;
        
        while(left < right) {
            water = Math.min(height[left], height[right]);
            int sum = (right-left)*water;
            
            if(water == height[left]) {
                left++;
            } else {
                right--;
            }
            
            if(sum > max) {
                max = sum;
            }
        }
        
        return max;
    }
}