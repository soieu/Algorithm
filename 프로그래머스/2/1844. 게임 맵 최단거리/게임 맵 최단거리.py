dx = [0, 0, 1, -1]
dy = [1, -1, 0, 0]

def solution(maps):
    n, m = len(maps), len(maps[0]) 
    visited = [[0 for _ in range(m)] for _ in range(n)]
    answer = -1
    q = [(0, 0, 1)]
    visited[0][0] = 1

    while q:
        y, x, step = q.pop(0)
        if y == n - 1 and x == m - 1: 
            answer = step
            break

        for i in range(4):
            next_x = x + dx[i]
            next_y = y + dy[i]

            if next_x < 0 or next_y < 0 or next_x >= m or next_y >= n:
                continue
            if visited[next_y][next_x] == 1:
                continue
            if maps[next_y][next_x] == 0: 
                continue
            q.append((next_y, next_x, step + 1))
            visited[next_y][next_x] = 1

    return answer
