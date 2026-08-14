# Write your MySQL query statement below
select person.firstName,person.lastName,address.city,address.state
from person
left join address ON person.personID=address.personID