# Write your MySQL query statement below
with tab as (
    select *, count(student) as no
    from Courses
    group by class
)

select class
from tab 
where no>=5