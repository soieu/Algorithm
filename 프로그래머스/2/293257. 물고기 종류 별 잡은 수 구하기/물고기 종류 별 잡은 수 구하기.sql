SELECT
    count(*) fish_count
    , fish_name
FROM
    fish_name_info fni
INNER JOIN
    fish_info fi
ON
    fni.fish_type = fi.fish_type
GROUP BY
    fni.fish_name
ORDER BY
    fish_count DESC