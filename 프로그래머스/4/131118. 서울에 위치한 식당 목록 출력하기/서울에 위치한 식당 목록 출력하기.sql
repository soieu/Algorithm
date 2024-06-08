-- 코드를 입력하세요
-- SELECT
--     ROUND(AVG(review_score),3) score
-- FROM
--     rest_review r
-- JOIN rest_info i
-- ON 
--     r.rest_id = i.rest_id
-- WHERE i.address LIKE '서울%'
-- GROUP BY i.REST_ID
-- ORDER BY score DESC, i.favorites DESC

SELECT A.rest_id, A.rest_name, A.food_type, A.favorites, A.address, round(Avg(B.review_score),2) AS average 
FROM rest_info A
    INNER JOIN rest_review B ON A.rest_id = B.rest_id 
WHERE a.address LIKE '서울%'
GROUP BY A.rest_id, A.rest_name, A.food_type, A.favorites, A.address
ORDER BY average DESC, A.favorites DESC