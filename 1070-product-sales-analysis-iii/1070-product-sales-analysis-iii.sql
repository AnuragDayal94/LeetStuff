# Write your MySQL query statement below
with ranked as (
    select *, rank() over (
        partition by product_id
        order by year
    ) as rn

    from Sales
)

select product_id, year as first_year, quantity, price
from ranked
where rn=1