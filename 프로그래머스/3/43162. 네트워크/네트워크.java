import java.util.*;

class Solution {
    public int solution(int n, int[][] computers) {
        int answer = 0;
        List<Integer>[] graph = new ArrayList[n];
        boolean[] visited = new boolean[n];

        // 그래프 초기화
        for (int i = 0; i < n; i++) {
            graph[i] = new ArrayList<>();
        }

        // 인접 리스트로 변환
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (computers[i][j] == 1 && i != j) {
                    graph[i].add(j);
                }
            }
        }

        // DFS를 사용하여 네트워크 개수 세기
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(graph, visited, i);
                answer++;
            }
        }

        return answer;
    }

    private void dfs(List<Integer>[] graph, boolean[] visited, int node) {
        visited[node] = true;
        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                dfs(graph, visited, neighbor);
            }
        }
    }
}
