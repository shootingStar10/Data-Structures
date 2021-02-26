class Solution {
    public int[] plusOne(int[] digits) {
        List<Integer> res = new ArrayList<>();
        boolean carry = false;
        int n = digits.length;

        if(digits[n-1]+1 < 10) {
            res.add(digits[n-1]+1);
        } else {
            res.add(0);
            carry = true;
        }

        for(int i = n-2; i >= 0; i--) {
            if (carry) {
                if(digits[i]+1 < 10) {
                    res.add(digits[i]+1);
                    carry = false;
                } else {
                    res.add(0);
                    carry = true;
                }
            } else {
                res.add(digits[i]);
            }
        }

        int[] arr;

        if(res.get(res.size()-1) == 0) {
            arr = new int[res.size()+1];
            res.add(1);
        } else {
            arr = new int[res.size()];
        }

        int j = 0;

        for(int i = res.size()-1; i >= 0; i--) {
            arr[j++] = res.get(i);
        }

        return arr;
    }
}