# Write your MySQL query statement below
select c.id
from Weather c
inner join Weather p
on datediff(c.recordDate,p.recordDate)=1
where c.temperature>p.temperature