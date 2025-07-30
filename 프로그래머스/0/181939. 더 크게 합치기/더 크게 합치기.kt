import kotlin.math.pow

class Solution {
    fun solution(a: Int, b: Int): Int {
        val aDigits = b.toString().length 
        val bDigits = a.toString().length  

        val ab = a * 10.0.pow(aDigits).toInt() + b
        val ba = b * 10.0.pow(bDigits).toInt() + a

        return maxOf(ab, ba)
    }
}
