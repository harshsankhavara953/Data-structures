public class slargest2 {

    public static void main(String[] args) {
        
        int arr[]={1,2,3,4,6,5,5};
        int largest=arr[0];
        int slargest=-1;

        for(int i=0;i<arr.length;i++){
            if(arr[i]>largest){
                slargest=largest;
                largest=arr[i];
            }else if(arr[i]<largest && arr[i]>slargest){
                slargest=arr[i];
            }
        }
        System.out.println("second largest element is:"+slargest);

    }
}
