class Solution {
    fun solution(arr: Array<String>): String {
        var answer = StringBuilder();
        
        for(c in arr) {
            answer.append(c);
        }
        return answer.toString()
    }
}