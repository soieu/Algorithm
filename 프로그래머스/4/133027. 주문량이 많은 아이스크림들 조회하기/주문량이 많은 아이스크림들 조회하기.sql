SELECT
    flavor
FROM (
    SELECT
        fh.flavor,
        fh.total_order + SUM(NVL(j.total_order, 0)) AS total_order
    FROM
        first_half fh
    LEFT JOIN
        july j
    ON
        fh.flavor = j.flavor
    GROUP BY
        fh.flavor, fh.total_order
    ORDER BY
        total_order DESC
)
WHERE ROWNUM <= 3;
