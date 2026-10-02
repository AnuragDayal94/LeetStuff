# Write your MySQL query statement below
select s.user_id, 
COALESCE(round(sum(case when c1.action='confirmed' then 1 else 0 end)/count(c1.action),2), 0) as confirmation_rate
from Signups s
left join Confirmations c1
on s.user_id=c1.user_id
group by s.user_id