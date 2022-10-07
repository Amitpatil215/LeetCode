# Write your MySQL query statement below
select d.name as department, e.name as employee, e.salary as salary  
from department d, employee e
where e.departmentId = d.id and
e.salary = (select max(salary)
           from employee
            where e.departmentId = departmentId 
            group by departmentId 
           );


