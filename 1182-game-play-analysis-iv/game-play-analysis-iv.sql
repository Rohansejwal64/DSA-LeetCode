
SELECT 
  ROUND(
    (
      SELECT COUNT(DISTINCT a1.player_id)
      FROM Activity a1
      WHERE a1.event_date = (
        SELECT DATE_ADD(MIN(a2.event_date), INTERVAL 1 DAY)
        FROM Activity a2
        WHERE a2.player_id = a1.player_id
      )
    ) * 1.0 / 
    (SELECT COUNT(DISTINCT player_id) FROM Activity)
  , 2) AS fraction;
