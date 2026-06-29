# Write your MySQL query statement below
select e1.name,e2.unique_id
from Employees e1
LEFT JOIN EmployeeUNI e2
ON e1.id=e2.id