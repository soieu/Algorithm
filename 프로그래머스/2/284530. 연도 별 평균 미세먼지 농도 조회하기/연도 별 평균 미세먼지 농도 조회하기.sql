-- 코드를 작성해주세요
SELECT
    YEAR(ym) 'year',
    ROUND(AVG(pm_val1), 2) 'pm10',
    ROUND(AVG(pm_val2), 2) 'pm2.5'
FROM
    air_pollution
WHERE
    location2 LIKE '%수원%'
GROUP BY
    YEAR(ym)
ORDER BY
    year
