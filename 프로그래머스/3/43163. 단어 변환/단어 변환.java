import java.util.*;

class Solution {
    public int solution(String begin, String target, String[] words) {
        if (!Arrays.asList(words).contains(target)) {  // target이 words에 있는지 확인
            return 0;
        }
        
        
        Queue<Integer> q = new LinkedList<>();
        int[] visited = new int[words.length];
        
        // begin에서 시작
        for (int i = 0; i < words.length; i++) {
            if (oneLetterDiff(begin, words[i])) {
                // 한글자만 다르면 큐에 추가하고 방문 처리
                q.add(i);
                visited[i] = 1; 
            }
        }

        int steps = 1;  // begin을 첫 변환 단계로 카운트
        while (!q.isEmpty()) {
            int size = q.size();
            for (int s = 0; s < size; s++) {
                int current = q.poll();
                if (words[current].equals(target)) {
                    return steps;  // 이미 begin을 첫 단계로 계산했으므로 여기서 바로 반환
                }

                for (int j = 0; j < words.length; j++) {
                    if (visited[j] == 0 && oneLetterDiff(words[current], words[j])) {
                        visited[j] = 1;  // 방문 처리
                        q.add(j);
                    }
                }
            }
            steps++;  // 다음 변환 단계로 이동
        }
        
        return 0; // target에 도달할 수 없으면 0 반환
    }

    private boolean oneLetterDiff(String s1, String s2) {
        int diffs = 0;
        for (int i = 0; i < s1.length(); i++) {
            if (s1.charAt(i) != s2.charAt(i)) {
                diffs++;
                if (diffs > 1) return false;
            }
        }
        return diffs == 1;
    }
}
