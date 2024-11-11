# Write your MySQL query statement below
select vis.customer_id,count(*) as count_no_trans from Visits vis where vis.visit_id not in (select visit_id from Transactions) group by vis.customer_id