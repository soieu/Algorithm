class Solution {
    public int[] solution(int n, int s) {
        int[] answer = {};
        if(n > s) {
            answer = new int[1];
            answer[0] = -1;
            return answer;
        } else {
            answer = new int[n];
        }
        for(int i = 0; i < n; i++) {
            if(i == n-1) {
                answer[i] = s;
            } else {
                answer[i] = s/(n-i);
                s -= answer[i];
            }
        }
        return answer;
    }
}