 SELECT name FROM people WHERE id IN --The IN funcition here allows for multiple return values. Using = will only allow one value (tom hanks)
   ...> (SELECT person_id FROM stars WHERE movie_id =
   ...> (SELECT id FROM movies WHERE title = 'Toy Story'));
