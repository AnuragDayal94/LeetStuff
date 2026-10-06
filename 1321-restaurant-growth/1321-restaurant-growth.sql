# Write your MySQL query statement below
with daily as (
    select visited_on, sum(amount) as amount
    from Customer
    group by visited_on
),
running as (
    select visited_on, 
    sum(amount) over (
        order by visited_on
        rows between 6 preceding and current row
    ) as amount,
    avg(amount) over (
        order by visited_on
        rows between 6 preceding and current row

    ) as average_amount,
    row_number() over (
        order by visited_on
    ) as rn

    from daily
)

select visited_on, amount, ROUND(average_amount, 2) AS average_amount
from running 
where rn>=7
group by visited_on

