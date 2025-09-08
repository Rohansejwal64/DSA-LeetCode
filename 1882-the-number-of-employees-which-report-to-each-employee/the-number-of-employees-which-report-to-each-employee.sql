SELECT e2.employee_id,e2.name,count(e1.employee_id) as reports_count, round(avg(e1.age)) as average_age
FROM employees as e1
inner join employees as e2
on e2.employee_id =e1.reports_to
group by e2.employee_id
order by e2.employee_id;
