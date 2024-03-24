-- 코드를 작성해주세요
SELECT i.item_id, i.item_name
FROM ITEM_INFO i 
JOIN ITEM_TREE t ON t.item_id = i.item_id
WHERE t.parent_item_id is null