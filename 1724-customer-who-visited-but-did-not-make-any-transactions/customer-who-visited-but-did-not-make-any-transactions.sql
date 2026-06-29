# Write your MySQL query statement below
select customer_id,COUNT(customer_id) as count_no_trans
from Visits v
LEFT JOIN Transactions t
ON v.visit_id = t.visit_id
WHERE t.transaction_id IS NULL
GROUP BY customer_id