-- 코드를 입력하세요
SELECT pt_name, pt_no, gend_cd, age, NVL(tlno, 'NONE') tlno
FROM patient
WHERE AGE <= 12 and gend_cd = 'W'
ORDER BY AGE DESC, pt_name ASC