SELECT titre ,resum FROM film
	WHERE LOWER(film.resum)  LIKE '%vincent%'
	ORDER BY id_film;