# Write your MySQL query statement below
# select (select salary 
# from employee
# order by salary desc limit 1,1) as SecondHighestSalary ;

SELECT
(SELECT DISTINCT Salary
FROM Employee
ORDER BY Salary DESC
LIMIT 1 OFFSET 1) AS SecondHighestSalary