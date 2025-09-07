SELECT 
    ROUND(
        (
            SELECT COUNT(*)
            FROM (
                SELECT customer_id
                FROM Delivery
                WHERE (customer_id, order_date) IN (
                    SELECT customer_id, MIN(order_date)
                    FROM Delivery
                    GROUP BY customer_id
                )
                  AND order_date = customer_pref_delivery_date
            ) AS t
        ) * 100.0 /
        (
            SELECT COUNT(DISTINCT customer_id)
            FROM Delivery
        )
    , 2) AS immediate_percentage;

