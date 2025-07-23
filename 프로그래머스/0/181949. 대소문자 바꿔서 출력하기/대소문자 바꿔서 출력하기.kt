fun main(args: Array<String>) {
    val s1 = readLine()!!
    for (ch in s1) {
        when {
            ch.isUpperCase() -> print(ch.lowercaseChar())
            ch.isLowerCase() -> print(ch.uppercaseChar())
            else              -> print(ch)
        }
    }
    
}