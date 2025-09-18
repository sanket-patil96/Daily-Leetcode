# Write your MySQL query statement below

SELECT firstName, lastName, city, state
FROM Person
LEFT JOIN Address
ON Person.personId = Address.personId;

-- When you use a condition in the WHERE clause like a.personid IS NULL after a 
-- LEFT JOIN, it essentially filters out all rows where the condition is not true, 
-- including rows where there is no match in the right table. This is because the NULL 
-- condition will be false for rows where there is no match, and those rows will be excluded from the result set.