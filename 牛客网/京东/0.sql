select cid,count(*) as max_peak_uv 
from play_record_tb 
group by cid 
order by 