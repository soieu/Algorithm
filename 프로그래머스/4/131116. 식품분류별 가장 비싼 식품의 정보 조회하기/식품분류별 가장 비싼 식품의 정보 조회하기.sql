SELECT
    fp.CATEGORY,
    fp.PRICE AS MAX_PRICE,
    fp.PRODUCT_NAME
FROM
    FOOD_PRODUCT fp
INNER JOIN (
    SELECT
        CATEGORY,
        MAX(PRICE) AS MAX_PRICE
    FROM
        FOOD_PRODUCT
    WHERE
        CATEGORY IN ('과자', '국', '김치', '식용유')
    GROUP BY
        CATEGORY
) AS subquery
ON
    fp.CATEGORY = subquery.CATEGORY
    AND fp.PRICE = subquery.MAX_PRICE
ORDER BY
    MAX_PRICE DESC;
