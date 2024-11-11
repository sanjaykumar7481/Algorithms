# Write your MySQL query statement below
select coalesce(empun.unique_id,null) as unique_id,emp.name from Employees emp left join EmployeeUNI empun on emp.id=empun.id;