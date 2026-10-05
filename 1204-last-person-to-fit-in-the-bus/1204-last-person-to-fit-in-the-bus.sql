# Write your MySQL query statement below
select person_name
from (
    select *, sum(weight) over (order by turn ) as total
    from (
        select *
        from Queue
        order by turn 
    ) t
) t2
where t2.total<=1000
order by t2.total DESC
limit 1


