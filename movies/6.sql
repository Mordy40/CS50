SELECT AVG(rating) AS avg_rating_2012 FROM ratings JOIN movies ON ratings.movie_id = movies.id WHERE movies.year = 2012;
