import java.awt.*;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    static int[] dirx = {1, -1, 0, 0};
    static int[] diry = {0, 0, 1, -1};

    static class Location {
        int x, y, dist, wall;

        public Location(int x, int y, int dist, int wall) {
            this.x = x;
            this.y = y;
            this.dist = dist;
            this.wall = wall;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        int[][] map = new int[n][m];
        for (int i = 0; i < n; i++) {
            String line = br.readLine();
            for (int j = 0; j < m; j++) {
                map[i][j] = line.charAt(j) - '0';
            }
        }

        boolean[][][] visited = new boolean[n][m][2];
        Queue<Location> q = new LinkedList<>();
        q.add(new Location(0, 0, 1, 0));
        visited[0][0][0] = true;

        while (!q.isEmpty()) {
            Location loc = q.poll();

            if (loc.x == n - 1 && loc.y == m - 1) {
                System.out.println(loc.dist);
                return;
            }

            for (int i = 0; i < 4; i++) {
                int nx = loc.x + dirx[i];
                int ny = loc.y + diry[i];

                if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;

                if (map[nx][ny] == 0) {
                    if (!visited[nx][ny][loc.wall]) {
                        visited[nx][ny][loc.wall] = true;
                        q.add(new Location(nx, ny, loc.dist + 1, loc.wall));
                    }
                } else if (map[nx][ny] == 1 && loc.wall == 0) {
                    if (!visited[nx][ny][1]) {
                        visited[nx][ny][1] = true;
                        q.add(new Location(nx, ny, loc.dist + 1, 1));
                    }
                }
            }
        }

        System.out.println(-1);
    }
}
