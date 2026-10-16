# Write your MySQL query statement below
select st.student_id, st.student_name, s.subject_name, count(e.subject_name) as attended_exams
from subjects s
cross join Students st
left join Examinations e

on s.subject_name=e.subject_name and
e.student_id=st.student_id
group by st.student_id, st.student_name, s.subject_name
order by st.student_id, s.subject_name