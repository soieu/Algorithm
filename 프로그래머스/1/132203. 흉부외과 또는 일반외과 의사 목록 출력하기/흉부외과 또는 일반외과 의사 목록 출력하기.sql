-- 코드를 입력하세요
SELECT dr_name, dr_id, mcdp_cd, to_char(hire_ymd, 'yyyy-mm-dd') hire_ymd
FROM DOCTOR
WHERE lcns_no in (select lcns_no from doctor where mcdp_cd = 'CS' OR mcdp_cd = 'GS')
ORDER BY hire_ymd desc, dr_name asc