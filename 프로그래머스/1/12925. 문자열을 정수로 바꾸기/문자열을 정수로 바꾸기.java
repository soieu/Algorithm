class Solution {
    public int solution(String s) {
        if (s == null || s.isEmpty()) {
            throw new IllegalArgumentException("Input string is null or empty.");
        }

        int answer = 0;
        int sign = 1;
        int start = 0;

        // Check for negative sign at the start
        if (s.charAt(0) == '-') {
            sign = -1;
            start++;
        } else if (s.charAt(0) == '+') {
            start++;
        }

        // Convert the rest of the string to an integer
        for (int i = start; i < s.length(); i++) {
            char c = s.charAt(i);
            if (c < '0' || c > '9') {
                throw new NumberFormatException("Invalid character found: " + c);
            }
            int digit = c - '0'; // Faster than Character.getNumericValue
            answer = answer * 10 + digit;
        }

        return answer * sign; // Apply the sign to the final result
    }
}
