# Write your MySQL query statement below
select b.id
from Weather a
join Weather b
on datediff(b.recordDate, a.recordDate)=1
where b.temperature>a.temperature