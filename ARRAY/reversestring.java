public class reversestring{

    public static void main(String[] args) {
        
String str="dik";
char[] nm=str.toCharArray();

for(int i=nm.length-1;i>=0;i--){
    System.out.print(nm[i]+" ");
}
    }
}
