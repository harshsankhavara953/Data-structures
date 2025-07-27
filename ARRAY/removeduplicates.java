public class removeduplicates {

    public static void main(String[] args) {
        int arr[] = { 1,1,22,3,3,4};
        int len=remove(arr);

        System.out.println("array after removing duplicates\n");
        for(int i=0;i<len;i++){
            System.out.println(arr[i]+" ");
        }
}

public static int remove(int []arr){

    if(arr.length==0||arr.length==1){
        return arr.length;}

        int i = 0;
        for (int j = 1; j < arr.length; j++) {
            if (arr[i] != arr[j]) {
                arr[i + 1] = arr[j];
                i++;
            }}
            return i+1;
    }
}
