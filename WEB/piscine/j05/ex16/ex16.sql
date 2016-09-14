SELECT COUNT(id_film) FROM historique_membre
WHERE (DATE(date) >= 2006-30-10 AND DATE(date) <= 2007-27-07) 
		OR (MONTH(date) = 12 AND DAY(date) = 24);