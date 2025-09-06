# 
-- SELECT 
--     ROUND(
--         -- COUNT(CASE WHEN order_date = customer_pref_delivery_date THEN 1 ELSE 0 END)
--         -- / 
--         COUNT(DISTINCT customer_id)
--         -- *100
--     , 2) as immediate_percentage
-- FROM delivery
-- ORDER BY order_date, customer_id

# From solutions
Select round(avg(order_date = customer_pref_delivery_date)*100, 2) as immediate_percentage
from Delivery
where (customer_id, order_date) in (
  Select customer_id, min(order_date) 
  from Delivery
  group by customer_id
);