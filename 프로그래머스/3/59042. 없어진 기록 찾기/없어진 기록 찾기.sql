-- 코드를 입력하세요
SELECT
    animal_id
    , name
FROM
    animal_outs
MINUS
SELECT
    animal_id
    , name
FROM
    animal_ins
