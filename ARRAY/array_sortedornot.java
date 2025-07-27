public class array_sortedornot {
    public static void main(String[] args) {
        int arr[] = { 1, 2, 3, 4, 5 };
        int flag = 0;
        for (int i = 1; i < arr.length; i++) {
            if (arr[i] >= arr[i - 1]) {
                flag = 1;
            } else {
                flag = 0;
            }
        }
        if (flag == 1) {
            System.out.println("aray is sorted:");
        } else if (flag == 0) {
            System.out.println("array is not sorted:");
        }

    }
}
