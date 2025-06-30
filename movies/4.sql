SELECT COUNT(movies.title) AS movies_10 FROM movies JOIN ratings ON movies.id = ratings.movie_id WHERE ratings.rating = 10;
