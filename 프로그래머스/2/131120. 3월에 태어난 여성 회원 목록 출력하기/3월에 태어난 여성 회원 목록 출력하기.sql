-- 코드를 입력하세요
SELECT member_id, member_name, gender,  TO_CHAR(date_of_birth,'yyyy-mm-dd') date_of_birth
FROM member_profile
WHERE TO_CHAR(date_of_birth,'mm') = '03'
AND gender = 'W'
AND tlno IS NOT NULL
ORDER BY member_id asc