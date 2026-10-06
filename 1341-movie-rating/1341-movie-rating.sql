# Write your MySQL query statement below
(
    select u.name as results
    from Users u
    left join MovieRating m
    on u.user_id=m.user_id
    group by u.user_id
    order by count(*) DESC, u.name
    limit 1
)
union all
(
    select m.title as results
    from Movies m
    left join MovieRating r
    on m.movie_id=r.movie_id
    where r.created_at>= '2020-02-01' and 
    r.created_at<='2020-02-29'
    group by m.movie_id
    order by avg(r.rating) DESC, m.title
    limit 1
)