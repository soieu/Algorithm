
import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        Map<Character, Integer> m = new TreeMap<>();
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String name = br.readLine().trim();

        for(char c : name.toCharArray()) {
            m.put(c, m.getOrDefault(c,0)+1);
        }

        // 홀수 개인 문자가 2개 이상이면 팰린드롬 불가
        int oddCount = 0;
        char oddChar = 0;
        for (Map.Entry<Character, Integer> entry : m.entrySet()) {
            if (entry.getValue() % 2 == 1) {
                oddCount++;
                oddChar = entry.getKey();
                if (oddCount > 1) {
                    bw.write("I'm Sorry Hansoo");
                    bw.flush();
                    bw.close();
                    return;
                }
            }
        }
        // 팰린드롬 만들기
        // 앞쪽 절반: 각 문자를 (개수/2)만큼 배치
        StringBuilder front = new StringBuilder();
        for (Map.Entry<Character, Integer> entry : m.entrySet()) {
            int half = entry.getValue() / 2;
            for (int i = 0; i < half; i++) {
                front.append(entry.getKey());
            }
        }

        // 앞쪽 + 홀수문자(있으면) + 앞쪽 뒤집은 것
        StringBuilder result = new StringBuilder();
        result.append(front);
        if (oddCount == 1) {
            result.append(oddChar);
        }
        result.append(front.reverse());

        bw.write(result.toString());
        bw.flush();
        bw.close();

    }
}
