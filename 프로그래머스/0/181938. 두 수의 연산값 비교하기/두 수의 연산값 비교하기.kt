class Solution {
    fun solution(a: Int, b: Int): Int {
        val ab = "$a$b".toInt()
        val doubleProduct = 2 * a * b

        return maxOf(ab, doubleProduct)
    }
}
