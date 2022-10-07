# Write your MySQL query statement below
select d.name as department, e.name as employee, e.salary
from  employee e, department d

where e.departmentId = d.id and 3 > (
    select count(distinct salary)
    from employee
    where departmentId = e.departmentId and salary > e.salary
);