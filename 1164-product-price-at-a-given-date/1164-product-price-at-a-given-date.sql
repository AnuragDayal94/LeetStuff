# Write your MySQL query statement below
with ranked as (
    select *, row_number() over (
        partition by product_id
        order by change_date DESC
    ) as rn
    from (
        select *
        from Products
        where change_date<='2019-08-16'
    ) a
)

select p.product_id, (case when r.rn=1 then r.new_price else 10 end) as price
from (
    select distinct product_id
    from Products
) p
left join ranked r
on p.product_id=r.product_id
where r.rn=1 or r.rn is NULL