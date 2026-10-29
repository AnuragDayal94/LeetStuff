# Write your MySQL query statement below
select e.name as name
from Employee m
join Employee e
on m.managerId=e.id
-- where count(m.managerId)>=5
group by m.managerId
having count(m.managerId)>=5

