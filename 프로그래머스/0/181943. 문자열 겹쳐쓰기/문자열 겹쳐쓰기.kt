class Solution {
    fun solution(my_string: String, overwrite_string: String, s: Int): String {
        val sb = StringBuilder()
        val n = my_string.length
        val m = overwrite_string.length

        for (i in 0 until n) {
            sb.append(
                if (i in s until s + m) {
                    overwrite_string[i - s]
                } else {
                    my_string[i]
                }
            )
        }
        return sb.toString()
    }
}
