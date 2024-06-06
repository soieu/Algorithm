-- 코드를 입력하세요
SELECT flavor
FROM first_half
WHERE total_order >= 3000
AND flavor in 
    (SELECT flavor 
     FROM icecream_info 
     WHERE ingredient_type = 'fruit_based')
ORDER BY total_order DESC