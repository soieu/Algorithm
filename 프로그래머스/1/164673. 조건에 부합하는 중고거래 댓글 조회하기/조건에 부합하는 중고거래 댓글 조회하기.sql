# -- 코드를 입력하세요

SELECT 
    ugb.title TITLE, 
    ugb.board_id BOARD_ID, 
    ugr.reply_id REPLY_ID, 
    ugr.writer_id WRITER_ID, 
    ugr.contents CONTENTS,
    DATE_FORMAT(ugr.created_date, '%Y-%m-%d') created_date
FROM 
    used_goods_board ugb
JOIN
    used_goods_reply ugr
ON
    ugb.board_id = ugr.board_id
WHERE
    DATE_FORMAT(ugb.created_date, '%Y-%m') = '2022-10'
ORDER BY
    ugr.created_date ASC, ugb.title ASC