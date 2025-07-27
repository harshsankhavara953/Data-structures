public class rot {
    public static void main(String[] args) {
        int nums[] = { 1, 2, 3, 4, 5, 6, 7 };
        int k = 3;
        int n = nums.length;
        k = k % n;

        int[] temp = new int[k];

        // Step 1: Copy last k elements into temp
        for (int i = 0; i < k; i++) {
            temp[i] = nums[n - k + i];
        }

        // Step 2: Shift remaining elements to the right
        for (int i = n - k - 1; i >= 0; i--) {
            nums[i + k] = nums[i];
        }

        // Step 3: Copy temp elements to the front
        for (int i = 0; i < k; i++) {
            nums[i] = temp[i];
        }

        // Print the rotated array
        for (int i = 0; i < n; i++) {
            System.out.print(nums[i] + " ");
        }
    }
}
