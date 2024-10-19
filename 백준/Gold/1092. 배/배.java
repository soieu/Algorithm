import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;

public class Main {
    static Integer[] crane;
    static int craneMax;
    static Integer[] cargo;
    static int cargoMax;
    static boolean[] cargoIsEmpty;
    static int N;
    static int M;

    // 화물 다 옮겼는지 체크
    static Boolean cargoCheck() {
        for (int i = 0; i < M; i++) {
            if (!cargoIsEmpty[i]) {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine());
        crane = new Integer[N];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            crane[i] = Integer.parseInt(st.nextToken());
        }
        Arrays.sort(crane, Collections.reverseOrder());

        M = Integer.parseInt(br.readLine());
        cargo = new Integer[M];
        cargoIsEmpty = new boolean[M];  // boolean 배열로 수정
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < M; i++) {
            cargo[i] = Integer.parseInt(st.nextToken());
        }
        Arrays.sort(cargo, Collections.reverseOrder());

        // 배로 옮길 수 없는 박스가 있는 경우
        if (crane[0] < cargo[0]) {
            System.out.println("-1");
            return;
        }

        int count = 0;
        while (!cargoCheck()) {
            int j = 0;
            for (int i = 0; i < N; i++) {
                while (j < M) {
                    if (!cargoIsEmpty[j] && cargo[j] <= crane[i]) {
                        cargoIsEmpty[j] = true;
                        j++;
                        break;  // 크레인이 화물을 옮겼으면 다음 크레인으로
                    }
                    j++;
                }
            }
            count++;
        }
        System.out.println(count);
    }
}
