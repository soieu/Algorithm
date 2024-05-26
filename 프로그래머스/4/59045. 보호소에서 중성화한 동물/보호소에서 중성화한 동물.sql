SELECT
    ain.animal_id,
    ain.animal_type,
    ain.name
FROM
    animal_ins ain
JOIN
    animal_outs aout
ON
    ain.animal_id = aout.animal_id
WHERE
    ain.sex_upon_intake LIKE "%Intact%"
    AND (
        aout.sex_upon_outcome LIKE "%Spayed%"
        OR aout.sex_upon_outcome LIKE "%Neutered%"
    )
ORDER BY
    ain.animal_id,
    ain.animal_type,
    ain.name;
