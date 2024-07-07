import java.util.Arrays;

class Solution {
    public String solution(String number, int k) {
        int len = number.length() - k;
        char[] result = new char[len]; 
        int index = 0; 
        
        // 문자열 number를 문자 배열로 변환
        char[] digits = number.toCharArray();
        
        for (int i = 0; i < digits.length; i++) {
            while (index > 0 && result[index - 1] < digits[i] && k > 0) {
                index--;
                k--;
            }
            
            if (index < len) {
                result[index++] = digits[i];
            }
        }
        
        return new String(result);
    }
}
