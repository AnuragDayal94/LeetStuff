# Write your MySQL query statement below
with ranked as (
    select *, row_number() over (
        partition by player_id 
        order by event_date
    ) as rn
    from Activity
)

select round(sum(case when datediff(b.event_date,a.event_date)=1 then 1  else 0 end)/(SELECT COUNT(DISTINCT player_id) FROM Activity),2) as fraction
from ranked a
left join ranked b
on a.player_id=b.player_id and b.rn=2

where a.rn=1
-- group by a.player_id