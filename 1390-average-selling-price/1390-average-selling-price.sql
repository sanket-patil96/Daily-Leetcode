# Write your MySQL query statement below
-- we need to find if the purchace date is in between the start_date & end_date for each price
-- and multiply the that price for the units it has sold

SELECT p.product_id, 
    COALESCE(        #  TO CONVERT NULL TO 0 
        ROUND( 
            SUM(CASE 
                    WHEN u.purchase_date BETWEEN p.start_date AND p.end_date 
                    THEN (p.price*u.units) 
                    ELSE 0
                END) 
            /
            NULLIF(SUM(CASE         # NULLIF IS PART OF COALESCE
                    WHEN u.purchase_date BETWEEN p.start_date AND p.end_date 
                    THEN u.units 
                END), 0)
        ,2), 
    0) as average_price
FROM Prices p
LEFT JOIN UnitsSold u
ON p.product_id = u.product_id
GROUP BY p.product_id