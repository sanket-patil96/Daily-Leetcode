SELECT a.name
FROM Employee a
LEFT JOIN Employee b
ON a.id = b.managerId and a.id != b.id
GROUP BY a.id
HAVING COUNT(b.id) >= 5
;
