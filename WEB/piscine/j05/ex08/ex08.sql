SELECT nom, prenom, DATE_FORMAT(date_naissance, '%Y-%m-%d') FROM fiche_personne
WHERE YEAR(date_naissance) = 1989
ORDER BY nom;