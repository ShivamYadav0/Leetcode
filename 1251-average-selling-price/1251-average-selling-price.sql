# Write your MySQL query statement below

select p.product_id , coalesce(round(sum(u.units*p.price)/sum(u.units),2),0) as average_price from Prices p Left Join UnitsSold u on p.product_id=u.product_id and  datediff(p.start_date,u.purchase_date)<=0 and datediff(p.end_date,u.purchase_date)>=0 group by p.product_id;