-- Write your PostgreSQL query statement below
select score,dense_rank() over (order by score desc) as rank
from  Scores
-- group by score
order by score desc
;