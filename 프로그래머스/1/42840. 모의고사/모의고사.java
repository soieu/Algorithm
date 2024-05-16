import java.util.ArrayList;
import java.util.List;

class Solution {
    public static int cal(int[] arr, int[] answers) {
        int answerLen = answers.length;
        int arrLen = arr.length;
        int count = 0;
    
        for(int i = 0; i < answerLen; i++) {
            int arrIdx = i % arrLen;
            if(arr[arrIdx] == answers[i]) {
                count++;
            }
        }
        
        return count;
    }
    
    public int[] solution(int[] answers) {
        int[] one = new int[] {1,2,3,4,5};
        int[] two = new int[] {2,1,2,3,2,4,2,5};
        int[] three = new int[] {3,3,1,1,2,2,4,4,5,5};
        
        int oneCount = cal(one, answers);
        int twoCount = cal(two, answers);
        int threeCount = cal(three, answers);
        
        int[] resultCount = {oneCount, twoCount, threeCount};
        
        List<Integer> newList = new ArrayList<>();
        int maxNum = 0;
        for(int i = 0; i < resultCount.length; i++) {
            if(resultCount[i] > maxNum) {
                newList.clear();
                newList.add(i+1);
                maxNum = resultCount[i];
            } else if (resultCount[i] == maxNum) {
                newList.add(i+1);
            }
        } 
        
        return newList.stream().mapToInt(i->i).toArray();
    }
}
