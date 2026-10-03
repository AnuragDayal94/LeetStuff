# Write your MySQL query statement below
select employee_id, department_id
from (
    select *, count(*) over (partition by employee_id) as c
    from Employee
) t
where primary_flag='Y' or c=1;