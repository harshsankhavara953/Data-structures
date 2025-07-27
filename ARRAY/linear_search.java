public class linear_search {

    public static int linearSearch(int[] arr, int num) {
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] == num) {
                return i;  
            }
        }
        return -1; 
    }

    public static void main(String[] args) {
        int arr[] = {1, 2, 3, 4, 5};
        int num = 2;

        int result = linearSearch(arr, num);
        if (result != -1) {
            System.out.println("Element found at index: " + result);
        } else {
            System.out.println("Element not found.");
        }
    }
}
