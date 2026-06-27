# Write your MySQL query statement below
select product_name,year,price
from Product as p
INNER JOIN Sales as s
ON s.product_id=p.product_id
