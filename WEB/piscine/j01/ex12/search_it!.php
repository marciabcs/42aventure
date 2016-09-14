#!/usr/bin/php
<?php
if ($argc > 2)
{
	$flag = 0;
	$i = 2;
	while($argv[$i])
	{
		if(preg_match('/'.$argv[1].'/', $argv[$i]))
			$flag = $i;
		$i++;
	}
	if ($flag != 0)
	{
		$tab = explode(':', $argv[$flag]);
		if ($tab[0] == $argv[1])
			echo $tab[1]."\n";
	}
}

?>