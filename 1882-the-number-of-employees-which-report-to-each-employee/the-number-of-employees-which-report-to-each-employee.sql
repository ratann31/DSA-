# Write your MySQL query statement below
select e1.employee_id,e1.name,COUNT(e2.reports_to) as reports_count,ROUND(AVG(e2.age),0) as average_age
from Employees e1
INNER JOIN Employees e2
ON e1.employee_id = e2.reports_to
GROUP BY e1.employee_id,e1.name
ORDER BY e1.employee_id