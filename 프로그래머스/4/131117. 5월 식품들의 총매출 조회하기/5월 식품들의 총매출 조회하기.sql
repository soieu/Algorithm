SELECT
    pro.product_id,
    pro.product_name,
    SUM(price * amount) AS total_sales

FROM
    food_product pro
JOIN
    food_order ord
ON
    pro.product_id = ord.product_id
WHERE
    produce_date BETWEEN '2022-05-01' AND '2022-05-31'
GROUP BY
    pro.product_id,
    pro.product_name
ORDER BY
    total_sales desc
    , product_id 
