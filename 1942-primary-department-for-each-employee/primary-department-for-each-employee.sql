SELECT t.employee_id, t.department_id
FROM (
    SELECT 
        e.employee_id,
        e.department_id,
        e.primary_flag,
        COUNT(*) OVER (PARTITION BY e.employee_id) AS cnt,
        CASE
            WHEN COUNT(*) OVER (PARTITION BY e.employee_id) = 1 THEN 1
            WHEN COUNT(*) OVER (PARTITION BY e.employee_id) > 1 AND e.primary_flag = 'Y' THEN 1
            ELSE 0
        END AS chk
    FROM employee e
) AS t
WHERE t.chk = 1;
