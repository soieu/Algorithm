import java.io.*;
import java.util.*;

public class Main {
    static int N, M;
    static int[][] map;
    static int maxSafeArea = 0;
    static int[] dx = {-1, 1, 0, 0};  // 상하좌우 이동
    static int[] dy = {0, 0, -1, 1};

    static class Virus {
        int x, y;

        public Virus(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        map = new int[N][M];

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < M; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        installWall(0);
        System.out.println(maxSafeArea);
    }

    public static void installWall(int wallCount) {
        if (wallCount == 3) {
            // 벽이 3개 설치된 경우 바이러스 확산 후 안전 영역 계산
            bfs();
            return;
        }

        // 빈 칸(0)에 벽을 설치
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (map[i][j] == 0) {  // 빈 공간
                    map[i][j] = 1;  // 벽 설치
                    installWall(wallCount + 1);
                    map[i][j] = 0;  // 다시 빈 공간으로
                }
            }
        }
    }

    public static void bfs() {
        int[][] cloneMap = new int[N][M];  // 맵 복사
        for (int i = 0; i < N; i++) {
            cloneMap[i] = map[i].clone();
        }

        Queue<Virus> q = new LinkedList<>();
        // 바이러스 위치를 큐에 추가
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (cloneMap[i][j] == 2) {
                    q.add(new Virus(i, j));
                }
            }
        }

        // BFS로 바이러스 퍼뜨리기
        while (!q.isEmpty()) {
            Virus v = q.poll();
            for (int i = 0; i < 4; i++) {
                int nx = v.x + dx[i];
                int ny = v.y + dy[i];

                if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
                    if (cloneMap[nx][ny] == 0) {  // 빈 공간으로 퍼질 수 있으면
                        cloneMap[nx][ny] = 2;  // 바이러스 퍼짐
                        q.add(new Virus(nx, ny));
                    }
                }
            }
        }

        // 안전 영역 계산
        int safeArea = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (cloneMap[i][j] == 0) {
                    safeArea++;
                }
            }
        }

        // 안전 영역의 최대값 갱신
        maxSafeArea = Math.max(maxSafeArea, safeArea);
    }
}
