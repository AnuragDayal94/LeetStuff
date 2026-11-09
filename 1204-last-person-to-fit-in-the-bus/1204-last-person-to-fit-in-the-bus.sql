# Write your MySQL query statement below
select person_name
from (
    select *, sum(weight) over (order by turn ASC) as su
    from Queue
    order by turn 
) a
where a.su<=1000
order by a.su desc
limit 1
