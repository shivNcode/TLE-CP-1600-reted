import java.util.*;

public class CPartitioningTheArray {
        public static int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int t = sc.nextInt();
        while (t-- > 0) {
            int n = sc.nextInt();
            int[] arr = new int[n];
            for (int i = 0; i < n; i++) {
                arr[i] = sc.nextInt();
            }
            ArrayList<Integer> fac = new ArrayList<>();
            for (int i = 1; i * i <= n; i++) {
                if (n % i == 0) {
                    if (i != (n / i)) {
                        fac.add(i);
                        fac.add(n / i);
                    } else {
                        fac.add(i);
                    }
                }

            }
            int ans = 1;
            for (int k : fac) {
                if (k == n)
                    continue;
                boolean check = true;
                int prev = 0;
                for (int i = 0; i < k; i++) {
                    for (int j = i + k; j < n; j += k) {
                        int curr = Math.abs(arr[j] - arr[j-k]);
                        prev = gcd(prev , curr);
                    }
                    if (prev==1) {
                        check = false;
                        break;
                    }
                }
                if(check==true) ans++;
            }
            System.out.println(ans);
        }

        sc.close();
    }
}