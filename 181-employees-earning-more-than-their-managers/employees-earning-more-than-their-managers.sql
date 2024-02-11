# Write your MySQL query statement below
select e.name as Employee from Employee e join Employee on e.managerId=Employee.id where e.salary>Employee.salary