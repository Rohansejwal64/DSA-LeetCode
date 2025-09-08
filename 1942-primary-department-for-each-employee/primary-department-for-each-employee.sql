SELECT t.employee_id, t.department_id
FROM (
    select employee_id ,department_id ,primary_flag  ,count(*) over (partition by employee_id )as cnt 
from employee
) AS t
WHERE t.cnt = 1
OR t.primary_flag='Y';
