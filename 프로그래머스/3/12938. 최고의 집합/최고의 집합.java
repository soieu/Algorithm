import java.util.*;

class Solution {
    public int[] solution(int n, int s) {
        if (n > s) {
            return new int[]{-1}; 
        }
        
        int[] answer = new int[n];
        
        int copyN = n;
        for(int i = 0; i < n; i++) {
            answer[i] = s / copyN--;
            s -= answer[i];
        }
        Arrays.sort(answer);
        return answer;
    }
}