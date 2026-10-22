# Write your MySQL query statement below
SELECT p.firstname, p.lastName, a.city, a.state
FROM Person AS p LEFT JOIN Address AS a on p.personId = a.personId; 