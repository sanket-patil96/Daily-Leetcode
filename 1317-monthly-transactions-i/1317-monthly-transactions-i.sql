# Write your MySQL query statement below
SELECT DATE_FORMAT(trans_date, '%Y-%m') as month
       ,country
       ,COUNT(*) as trans_count
       ,COUNT(CASE WHEN state = 'approved' THEN 1 END) as approved_count
       ,SUM(amount) as trans_total_amount
       ,COALESCE(SUM(CASE WHEN state = 'approved' THEN amount END), 0) as approved_total_amount
FROM Transactions
GROUP BY month, country