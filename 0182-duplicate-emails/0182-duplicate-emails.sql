-- Write your PostgreSQL query statement below
select distinct p1.email as email
from Person p1
inner join person p2
on p1.email=p2.email
where p1.id!=p2.id