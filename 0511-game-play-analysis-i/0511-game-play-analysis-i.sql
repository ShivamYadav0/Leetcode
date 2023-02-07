# Write your MySQL query statement below
select a.player_id , a.event_date as first_login from Activity a
where a.event_date=(select min(b.event_date) from Activity b where a.player_id=b.player_id);