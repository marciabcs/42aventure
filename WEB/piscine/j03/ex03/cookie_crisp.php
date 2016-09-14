<?php

$tab = $_GET;
if ($tab[action] == "set")
  	setcookie($tab[name], $tab[value], time()+3600); 
if ($tab[action] == "get")
	if ($_COOKIE[$tab[name]] === true)
  		echo $_COOKIE[$tab[name]]; 
if ($tab[action] == "del")
  	setcookie($tab[name], $tab[value], 1); 

?>
