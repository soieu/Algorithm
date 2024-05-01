

import java.util.*;

// Press Shift twice to open the Search Everywhere dialog and type `show whitespaces`,
// then press Enter. You can now see whitespace characters in your code.
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int count = 0;
        int s = sc.nextInt();
        int p = sc.nextInt();
        String str = sc.next();

        int[] alphaCnt = new int[4];
        int[] cnt = new int[4];
        for (int i = 0; i < 4; i++) {
            alphaCnt[i] = sc.nextInt();
        }

        for (int i = 0; i < p; i++){
            if (str.charAt(i) == 'A') {
                cnt[0]++;
            } else if (str.charAt(i) == 'C') {
                cnt[1]++;
            } else if (str.charAt(i) == 'G') {
                cnt[2]++;
            } else if (str.charAt(i) == 'T') {
                cnt[3]++;
            }
        }

        for (int i = 0; i < s - p + 1; i++) {
            if (i != 0) {
                if (str.charAt(i-1) == 'A') {
                    cnt[0]--;
                } else if (str.charAt(i-1) == 'C') {
                    cnt[1]--;
                } else if (str.charAt(i-1) == 'G') {
                    cnt[2]--;
                } else if (str.charAt(i-1) == 'T') {
                    cnt[3]--;
                }
                if (str.charAt(i+p-1) == 'A') {
                    cnt[0]++;
                } else if (str.charAt(i+p-1) == 'C') {
                    cnt[1]++;
                } else if (str.charAt(i+p-1) == 'G') {
                    cnt[2]++;
                } else if (str.charAt(i+p-1) == 'T') {
                    cnt[3]++;
                }
            }
            if (alphaCnt[1] <= cnt[1]
                    && alphaCnt[2] <= cnt[2]
                    && alphaCnt[3] <= cnt[3]
                    && alphaCnt[0] <= cnt[0]) {
                count++;
            }


        }

        System.out.println(count);


    }
}