SELECT
    ab item_id
    , item_name
    , rarity
FROM
    (
        SELECT
            it.item_id ab
        FROM
                (
                    SELECT
                        *
                    FROM
                        item_info
                    WHERE
                        rarity = "rare"
                ) ii
        JOIN item_tree it ON ii.item_id = it.parent_item_id
    ) iii
    JOIN item_info iinfo ON iii.ab = iinfo.item_id
ORDER BY
    ab DESC


