# Write your MySQL query statement below
select m.reports_to as employee_id, e.name,
count(*) as reports_count, round(avg(m.age)) as average_age
from Employees m
left join Employees e
on m.reports_to=e.employee_id 
where m.reports_to is not NULL
group by m.reports_to
order by employee_id