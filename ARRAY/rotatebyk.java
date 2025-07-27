public class rotatebyk {
    public static void main(String[] args) {
        int nums[] = { 1, 2, 3, 4, 5, 6, 7 };
        int k = 3;
        k = k % nums.length;

        int[] temp = new int[k];

        for (int i = 0; i < k; i++) {
            temp[i] = nums[i];
        }

        for (int i = k; i < nums.length; i++) {
            nums[i - k] = nums[i];
        }
        for (int i = nums.length - k; i < nums.length; i++) {
            nums[i] = temp[i - (nums.length - k)];
        }

        for (int i = 0; i < nums.length; i++) {
            System.out.print(nums[i] + " ");
        }
    }
}