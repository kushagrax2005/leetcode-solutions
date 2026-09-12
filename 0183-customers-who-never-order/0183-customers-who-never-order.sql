-- Write your PostgreSQL query statement below
select c1.name as Customers
from customers c1
where id not in(
select c2.id
from customers c2
inner join orders o
on c2.id=o.customerID
)