# Write your MySQL query statement below
select a.user_id,
ROUND(coalesce((select count(*) from Confirmations b where b.user_id=a.user_id and b.action='confirmed' group by b.user_id)
/ count(c.action),0),2)as confirmation_rate from Signups a left join Confirmations c on a.user_id=c.user_id group by a.user_id 