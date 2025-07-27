public class slargest {
    public static void main(String[] args) {
        int arr[]={2,34,54,3,54,55};
        int largest=arr[0];
        for(int i=0;i<arr.length;i++)
        {
            if(arr[i]>largest){
                largest=arr[i];
            }
        }
        int slarg=-1;
        for(int i=0;i<arr.length;i++){
            if(arr[i]>slarg && arr[i]!=largest){
                slarg=arr[i];
            }
        }
System.out.println("second largest element is :"+slarg);
    }
}
