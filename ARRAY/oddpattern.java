
import java.util.*;

public class oddpattern {

    public static void main(String[] args) {
        int n, i, j, k = 1;
        Scanner sc = new Scanner(System.in);
        System.out.println("enter lines");
        n = sc.nextInt();
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= i; j++) {
                System.out.print(k + " ");
                k += 2;
            }
            System.out.println();
        }
    }

}
