# Write your MySQL query statement below
select b.product_name, a.unit 
from (
    select product_id, order_date,
    sum(unit) as unit
    from Orders
    where order_date>='2020-02-01' and order_date<'2020-03-01'
    group by (product_id)
) a
left join Products b
on a.product_id=b.product_id
where a.unit>=100

