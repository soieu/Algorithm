import java.util.*;

class Solution {
    public int solution(int k, int[] tangerine) {
        HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
        
        for(int i = 0; i < tangerine.length; i++) {
            map.put(tangerine[i], map.containsKey(tangerine[i]) ? map.get(tangerine[i])+1:1);
        }
        
        List<Integer> keySet = new ArrayList<Integer>(map.keySet());
        keySet.sort((o1, o2) -> map.get(o2).compareTo(map.get(o1)));
        
        int count = 0;
        for (Integer key : keySet) {
            System.out.println(map.get(key));
            k = k - map.get(key);
            count = count+1;
            if(k <= 0) {
                return count;
            }
        }
        return 0;

    }
}