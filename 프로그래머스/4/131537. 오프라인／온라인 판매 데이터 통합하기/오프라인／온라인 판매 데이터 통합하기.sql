-- 코드를 입력하세요
SELECT *
FROM
    (
        SELECT 
            DATE_FORMAT(sales_date, "%Y-%m-%d") AS sales_date
            , product_id
            , user_id
            , sales_amount
        FROM
            online_sale
        WHERE 
            sales_date LIKE '2022-03%'
        UNION
        SELECT 
            DATE_FORMAT(sales_date, "%Y-%m-%d") AS sales_date
            , product_id
            , NULL user_id
            , sales_amount
        FROM
            offline_sale
        WHERE 
            sales_date LIKE '2022-03%'
    ) base
ORDER BY
    sales_date
    , product_id
    , user_id