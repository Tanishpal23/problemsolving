# Write your MySQL query statement below
SELECT a.year, a.price, b.product_name
FROM Sales a
LEFT JOIN Product b
ON a.product_id = b.product_id;