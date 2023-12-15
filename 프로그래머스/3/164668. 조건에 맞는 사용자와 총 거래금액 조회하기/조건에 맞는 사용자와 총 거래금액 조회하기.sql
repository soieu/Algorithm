SELECT u.user_id USER_ID, u.nickname NICKNAME, sum(price) TOTAL_SALES
FROM USED_GOODS_BOARD b
INNER JOIN USED_GOODS_USER u
ON b.writer_id = u.user_id AND STATUS = 'DONE'
GROUP BY user_id
HAVING sum(price) >= 700000
ORDER BY sum(price) asc