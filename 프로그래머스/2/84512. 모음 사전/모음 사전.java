import java.util.ArrayList;
import java.util.List;
class Solution {
   static List<String> list;
    static String[] words = {"A", "E", "I", "O", "U"};

    public int solution(String word) {
        list = new ArrayList<>();
        dfs("", 0);
        return list.indexOf(word);
    }

    static void dfs(String str, int len) {
        if (len > 5) return; // 단어의 길이가 5를 초과하면 종료
        list.add(str);
        for (int i = 0; i < 5; i++) {
            dfs(str + words[i], len + 1);
        }
    }
}
