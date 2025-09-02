SELECT 
  r.contest_id,
  ROUND(COUNT(DISTINCT r.user_id) * 100.0 / COUNT(DISTINCT u.user_id), 2) AS percentage
FROM Register r
CROSS JOIN Users u
GROUP BY r.contest_id
ORDER BY percentage DESC, r.contest_id ASC;
