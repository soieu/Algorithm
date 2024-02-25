-- 코드를 입력하세요
SELECT name, count(name) count
FROM animal_ins
group by name
having count(name) >= 2
order by name