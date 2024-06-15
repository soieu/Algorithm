SELECT
    ii.ITEM_ID,
    ii.ITEM_NAME,
    ii.RARITY
FROM
    ITEM_INFO ii
WHERE
    ii.ITEM_ID IN (
        SELECT
            it.ITEM_ID
        FROM 
            ITEM_TREE it
        WHERE
            it.PARENT_ITEM_ID IN (
                SELECT
                    iii.ITEM_ID
                FROM
                    ITEM_INFO iii
                WHERE
                    iii.RARITY = 'RARE'
            )
        )
ORDER BY
    ii.ITEM_ID DESC