# Write your MySQL query statement below
select name as Employee from Employee e where e.managerId in (select id from Employee where id=e.managerId and e.salary > salary);