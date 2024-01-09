# Write your MySQL query statement below

select e.name from employee e Join employee b on e.id=b.managerId group by e.id having count(*)>=5;