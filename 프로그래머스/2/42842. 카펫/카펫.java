class Solution {
   public int[] solution(int brown, int yellow) {
        int total = brown + yellow;
         // 높이의 최솟값은 3부터 시작 최대값은 brown과 yellow의 합의 제곱근보다는 작거나 같음
        for (int h = 3; h <= Math.sqrt(total); h++) {
            // total이 h로 나누어떨어질때만 값이 계산이됨
            if (total % h == 0) {
                // w * h = total이 되도록 w 값 대입
                int w = total / h;
                // 기억하는 brown의 개수랑 맞는지 비교
                if (2 * w + 2 * h - 4 == brown) {
                    return new int[] {w, h};
                }
            }
        }
        return null; // This line should never be reached
    }
}
