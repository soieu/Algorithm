-- 코드를 입력하세요
SELECT
    '/home/grep/src/'||b.board_id||'/'||file_id||f.file_name||f.file_ext AS file_path
FROM
    USED_GOODS_BOARD b
JOIN
    USED_GOODS_FILE f
ON
    b.board_id = f.board_id
WHERE
    b.views =
        (
            SELECT
                max(bb.views)
            FROM
                USED_GOODS_BOARD bb
                
        )
ORDER BY
    file_id DESC