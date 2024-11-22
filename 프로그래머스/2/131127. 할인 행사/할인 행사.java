import java.util.*;

class Solution {
    public static boolean check(HashMap<String, Integer> map, String[] want, int[] number) {
        // 원하는 물품의 개수(number)가 조건을 충족하는지 확인
        for (int i = 0; i < want.length; i++) {
            if (map.getOrDefault(want[i], 0) < number[i]) {
                return false;
            }
        }
        return true;
    }

    public int solution(String[] want, int[] number, String[] discount) {
        int answer = 0;
        HashMap<String, Integer> map = new HashMap<>();

        // 슬라이딩 윈도우 크기: 10일
        int windowSize = 10;

        for (int i = 0; i < discount.length; i++) {
            // 현재 아이템 추가
            map.put(discount[i], map.getOrDefault(discount[i], 0) + 1);

            // 윈도우 크기 초과 시 가장 오래된 아이템 제거
            if (i >= windowSize) {
                String expiredItem = discount[i - windowSize];
                map.put(expiredItem, map.get(expiredItem) - 1);
                if (map.get(expiredItem) == 0) {
                    map.remove(expiredItem); // 값이 0이 되면 삭제
                }
            }

            // 윈도우 크기가 10일에 도달했을 때 조건 확인
            if (i >= windowSize - 1 && check(map, want, number)) {
                answer++;
            }
        }

        return answer;
    }
}
