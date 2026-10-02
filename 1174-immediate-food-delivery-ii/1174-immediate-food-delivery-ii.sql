# Write your MySQL query statement below
with ranked as (
    select *, row_number() over (
        partition by customer_id
        order by order_date
    ) as rn

    from Delivery 
)

select round(sum(case when order_date=customer_pref_delivery_date then 1 else 0 end)*100/count(*),2) as immediate_percentage
from ranked
where rn=1
-- group by customer_id