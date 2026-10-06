WITH friends AS (
    SELECT requester_id AS user_id
    FROM RequestAccepted

    UNION ALL

    SELECT accepter_id AS user_id
    FROM RequestAccepted
)
SELECT user_id AS id,
       COUNT(*) AS num
FROM friends
GROUP BY user_id
ORDER BY num DESC
LIMIT 1;