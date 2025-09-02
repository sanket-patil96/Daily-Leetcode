# Write your MySQL query statement below

SELECT r.contest_id, ROUND(COUNT(r.contest_id) * 100 / (SELECT COUNT(*) FROM users),2) as percentage
FROM register r
GROUP BY r.contest_id
ORDER BY percentage DESC, r.contest_id