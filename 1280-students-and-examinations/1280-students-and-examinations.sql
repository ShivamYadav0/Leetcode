# Write your MySQL query statement below

select s.student_id , s.student_name , sb.subject_name , coalesce(count(e.student_id),0) as attended_exams from students s Join subjects sb Left Join Examinations e on s.student_id=e.student_id and e.subject_name=sb.subject_name group by s.student_id , s.student_name , sb.subject_name order by s.student_id , sb.subject_name;