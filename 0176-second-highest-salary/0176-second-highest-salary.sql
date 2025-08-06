# Write your MySQL query statement below
SELECT (
    SELECT DISTINCT salary 
    FROM Employee
    ORDER BY salary DESC
    LIMIT 1, 1
) as SecondHighestSalary;           -- THIS IS TO RETURN Null WHEN NO Nth highest salary