-- Write your PostgreSQL query statement below
-- select e.name as Employee, max(e.salary) as Salary
select d2.name as department, e2.name as employee,salary as salary
-- select *
from employee e2
inner join Department d2
on e2.departmentID=d2.id
where (d2.id,salary) in
(select d.id,max(salary)
from employee e
inner join Department d
on e.departmentID=d.id
group by d.id)
-- having e.salary=max(e.salary) 