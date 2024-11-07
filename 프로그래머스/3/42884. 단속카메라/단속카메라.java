import java.util.*;

class Solution {
    public int solution(int[][] routes) {
        int answer = 1;

        // 첫 번째 원소 기준으로 오름차순 정렬
        Arrays.sort(routes, (a, b) -> Integer.compare(a[0], b[0]));
        
        // 첫 번째 경로의 끝점을 초기값으로 설정
        int curEnd = routes[0][1];
        
        for (int i = 1; i < routes.length; i++) {
            // 현재 경로의 시작점이 이전 끝점보다 큰 경우, 새로운 카메라 설치
            if (routes[i][0] > curEnd) {
                answer++;
                curEnd = routes[i][1]; // 끝점 갱신
            } else {
                // 겹치는 구간이 있으면 curEnd를 더 작은 값으로 업데이트
                curEnd = Math.min(curEnd, routes[i][1]);
            }
        }
        
        return answer;
    }
}
