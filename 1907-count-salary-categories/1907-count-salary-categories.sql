# Write your MySQL query statement below
select r.category, coalesce(t.no,0) as accounts_count
from (
    select 'Low Salary' as category
    union all 
    select 'Average Salary'
    union all 
    select 'High Salary'
) r
left join (
    select *, count(*) as no
    from(
        select *, (case when income<20000 then 'Low Salary'  when income<=50000 and income>=20000 then 'Average Salary' else 'High Salary' end) as category
        from Accounts
    )a
    group by a.category
    
) t
on r.category=t.category


