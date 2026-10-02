# Write your MySQL query statement below
select r.contest_id, 
round((count(*)/ (select count(*) from Users))*100,2) as percentage
from Register r

group by contest_id
order by percentage DESC, r.contest_id
