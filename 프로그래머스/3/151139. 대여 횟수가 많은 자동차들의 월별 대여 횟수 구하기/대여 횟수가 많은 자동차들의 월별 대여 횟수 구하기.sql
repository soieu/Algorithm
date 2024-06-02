WITH base AS (
    SELECT
        car_id
    FROM
        car_rental_company_rental_history
    WHERE
        start_date BETWEEN '2022-08-01' AND '2022-10-31'
    GROUP BY
        car_id
    HAVING
        count(*) >= 5
)
SELECT
    MONTH(a.start_date) AS month,
    a.car_id,
    count(*) AS records
FROM
    car_rental_company_rental_history a
JOIN
    base b
ON 
    a.car_id = b.car_id
WHERE
    a.start_date BETWEEN '2022-08-01' AND '2022-10-31'
GROUP BY 
    a.car_id,
    MONTH(a.start_date)
ORDER BY 
    month,
    a.car_id DESC;
