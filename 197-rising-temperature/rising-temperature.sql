# Write your MySQL query statement below
select distinct(w1.id) as id from Weather w1 cross join Weather w2 where w1.temperature>w2.temperature and dateDiff(w1.recordDate,w2.recordDate)=1;