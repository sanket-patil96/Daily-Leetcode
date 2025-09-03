-- FIRST get the sum of all the rating/position group by query_name and divide them by total of that query_name
-- then again count the total query_names that have rating < 3 and divide it by total names * 100 as percentage
SELECT 
    query_name 
    ,ROUND(
        SUM(rating / position) / COUNT(*), 2
    ) as quality
    ,
    IFNULL(
        ROUND(
            SUM(rating < 3) 
            / 
            COUNT(*) * 100, 
        2) 
    ,0) as poor_query_percentage
FROM Queries
GROUP BY query_name