class Solution {
    boolean solution(String s) {
        int pSize = 0;
        int ySize = 0;
        
        // Count occurrences of 'p' and 'y'
        for(int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if(c == 'p' || c == 'P') {
                pSize++;
            } else if(c == 'y' || c == 'Y') {
                ySize++;
            }
        }
        
        // Check if counts are equal and return result
        return pSize == ySize;
    }
}
