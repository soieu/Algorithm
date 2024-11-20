import java.util.*;

class Solution {
    public static int stoi(String operation) {
        int result = 0;
        int start = 2;
        int flag = 1;
        if (operation.charAt(2) == '-') {
            start++;
            flag = -1;
        }
        for (int i = start; i < operation.length(); i++) {
            result = result * 10 + operation.charAt(i) - '0';
        }
        return flag * result;
    }

    public int[] solution(String[] operations) {
        // 낮은 숫자가 우선순위인 우선순위 큐
        PriorityQueue<Integer> pql = new PriorityQueue<>();
        // 높은 숫자가 우선순위인 우선순위 큐
        PriorityQueue<Integer> pqh = new PriorityQueue<>(Collections.reverseOrder());

        for (String operation : operations) {
            if (operation.charAt(0) == 'I') {
                // 숫자 삽입
                int insertNum = stoi(operation);
                pql.add(insertNum);
                pqh.add(insertNum);
            } else if (operation.equals("D 1")) {
                // 최댓값 삭제
                if (!pqh.isEmpty()) {
                    int maxVal = pqh.poll();
                    pql.remove(maxVal);
                }
            } else if (operation.equals("D -1")) {
                // 최솟값 삭제
                if (!pql.isEmpty()) {
                    int minVal = pql.poll();
                    pqh.remove(minVal);
                }
            }
        }

        // 결과 값 계산
        int[] answer = new int[2];
        if (!pqh.isEmpty() && !pql.isEmpty()) {
            answer[0] = pqh.peek(); // 최댓값
            answer[1] = pql.peek(); // 최솟값
        } else {
            answer[0] = 0; // 큐가 비어 있을 경우
            answer[1] = 0;
        }

        return answer;
    }
}
