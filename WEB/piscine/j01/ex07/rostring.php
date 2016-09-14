#!/usr/bin/php
<?php
if ($argc > 1)
{
	$av = trim($argv[1]);
	$tab = explode(' ', $av);
	$tab = array_filter($tab, "mb_strlen");
	if (count($tab) == 1)
		echo $tab[0]."\n";
	else if (count($tab) > 1)
	{
		foreach ($tab as $key) 
		{
			if ($key == $tab[0])
				continue;
			else
				echo $key." ";	
		}
		echo $tab[0]."\n";
	}
}
?>
