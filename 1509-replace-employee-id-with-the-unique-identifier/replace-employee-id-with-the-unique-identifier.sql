# Write your MySQL query statement below
SELECT a.unique_id, b.name
FROM EmployeeUNI a
RIGHT JOIN Employees b
ON a.id = b.id;
