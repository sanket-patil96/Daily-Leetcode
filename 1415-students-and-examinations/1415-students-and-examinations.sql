# Write your MySQL query statement below
SELECT stud.student_id, stud.student_name, sub.subject_name, COUNT(e.student_id) as attended_exams 
FROM Students stud
CROSS JOIN Subjects sub
LEFT JOIN Examinations e
    ON stud.student_id = e.student_id
    AND sub.subject_name = e.subject_name
GROUP BY stud.student_id, stud.student_name, sub.subject_name
ORDER BY stud.student_id, stud.student_name, sub.subject_name;