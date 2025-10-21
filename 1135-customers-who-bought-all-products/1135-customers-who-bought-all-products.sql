# just group the customer by id, and find if their distinct product_key count matches the
# total count of products
SELECT customer_id 
FROM Customer
GROUP BY customer_id
HAVING COUNT(DISTINCT product_key) = (select COUNT(*) From Product);