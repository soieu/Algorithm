SELECT
    HISTORY_ID,
    CAR_ID,
    TO_CHAR(START_DATE, 'yyyy-mm-dd') start_date,
    TO_CHAR(END_DATE, 'yyyy-mm-dd') end_date,
    CASE WHEN TO_DATE(end_date) - TO_DATE(start_date) >= 29 THEN '장기 대여'
         ELSE '단기 대여' 
         END AS RENT_TYPE
FROM
    Car_Rental_Company_Rental_History
WHERE
    to_char(start_date,'yyyy-mm') LIKE '%2022-09%'
ORDER BY 
    HISTORY_ID DESC