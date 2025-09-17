# Write your MySQL query statement below
SELECT e.name, b.bonus 
FROM EMPLOYEE e 
LEFT JOIN BONUS b
on e.empId = b.empId
where (b.bonus < 1000 or b.bonus is NULL)