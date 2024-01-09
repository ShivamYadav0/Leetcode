# Write your MySQL query statement below

select name from employee e where (select count(ee.id) from employee ee where e.id=ee.managerId) >=5;