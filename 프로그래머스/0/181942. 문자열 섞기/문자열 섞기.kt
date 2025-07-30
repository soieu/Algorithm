class Solution {
    fun solution(str1: String, str2: String): String {
        var sb = StringBuilder();
        
        for (i in str1.indices) {
            sb.append(str1[i]);
            sb.append(str2[i]);
        }
        return sb.toString()
    }
}