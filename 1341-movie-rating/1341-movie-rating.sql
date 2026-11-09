# Write your MySQL query statement below
(select name as results
from (
    select u.name, count(*) as no
    from MovieRating m
    left join Users u
    on m.user_id=u.user_id
    group by m.user_id
) t
order by t.no desc, name asc
limit 1)

union all
(select title
from (
    select u.title, avg(m.rating) as no
    from MovieRating m
    left join Movies u
    on m.movie_id=u.movie_id
    WHERE m.created_at >= '2020-02-01'
    AND m.created_at < '2020-03-01'
    group by m.movie_id
) t2
order by t2.no desc, title asc
limit 1)