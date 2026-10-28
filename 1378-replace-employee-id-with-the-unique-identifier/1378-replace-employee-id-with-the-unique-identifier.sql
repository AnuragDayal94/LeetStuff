# Write your MySQL query statement below
select coalesce(b.unique_id,null) as unique_id, 
a.name
from Employees a
left join EmployeeUNI b
on a.id=b.id