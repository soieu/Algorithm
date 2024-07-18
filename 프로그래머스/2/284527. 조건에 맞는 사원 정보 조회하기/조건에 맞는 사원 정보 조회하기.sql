-- 2022년도 평가 점수가 가장 높은 사원들의 점수, 사번, 성명, 직책, 이메일 / 박소영

SELECT
    SUM(SCORE) score
    , e.emp_no
    , e.emp_name
    , e.position
    , e.email
FROM
    hr_employees e
JOIN
    hr_grade g
ON 
    e.emp_no = g.emp_no
GROUP BY
    e.emp_no
ORDER BY
    score DESC
LIMIT 1


    
