# Write your MySQL query statement below
select class
from (
    select class, count(distinct student) as no
    from Courses
    group by class
) a
where a.no>=5