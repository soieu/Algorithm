import java.util.*;

class Solution {
    public int solution(String begin, String target, String[] words) {
        int answer = 0;
        
        // words에 target이 없는 경우 변환 불가
        if (Arrays.stream(words).noneMatch(target::equals)) {
            return answer;
        }

        // 방문한 단어들을 저장할 리스트
        List<String> already = new ArrayList<>();

        // BFS를 위한 Queue (현재 단어, 변환 횟수)
        Queue<Pair> queue = new LinkedList<>();
        queue.add(new Pair(begin, 0));

        while (!queue.isEmpty()) {
            Pair current = queue.poll();
            String currentWord = current.word;
            int steps = current.steps;

            // target 단어에 도달하면 변환 횟수 반환
            if (currentWord.equals(target)) {
                return steps;
            }

            // 변환 가능한 단어 탐색
            for (String word : words) {
                if (!already.contains(word) && isDifferentOneSpell(currentWord, word)) {
                    queue.add(new Pair(word, steps + 1));
                    already.add(word); // 방문 처리
                }
            }
        }

        return 0; // 변환할 수 없는 경우
    }

    // 한 글자만 다른지 체크하는 함수
    private boolean isDifferentOneSpell(String a, String b) {
        int count = 0;
        for (int i = 0; i < a.length(); i++) {
            if (a.charAt(i) != b.charAt(i)) {
                count++;
            }
            if (count > 1) return false; // 두 글자 이상 다르면 false
        }
        return count == 1; // 정확히 한 글자만 다를 경우 true
    }

    // 단어와 변환 횟수를 저장할 Pair 클래스
    private static class Pair {
        String word;
        int steps;
        
        Pair(String word, int steps) {
            this.word = word;
            this.steps = steps;
        }
    }
}
