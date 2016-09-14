#!/usr/bin/php
<?
$flag = 0;
if ($argc != 2)
	$flag = 2;
else
{
	$av = trim($argv[1]);
	$tab = preg_split('/[ ]*[+\/*%][ ]*/', $av);
	if 
	if (count($tab) != 2)
		$flag = 1;
	foreach ($tab as $key)
		if (!is_numeric($key))
			$flag = 1;
}
if ($flag == 0)
{
	if (preg_match('/[+]/', $av))
		$res = $tab[0] + $tab[1];
	if (preg_match('/[-]/', $av))
		$res = $tab[0] - $tab[1];
	if (preg_match('/[*]/', $av))
		$res = $tab[0] * $tab[1];
	if (preg_match('/[\/]/', $av))
		$res = $tab[0] / $tab[1];
	if (preg_match('/[%]/', $av))
		$res = $tab[0] % $tab[1];
	echo $res."\n";
}
else if ($flag == 2)
	echo "Incorrect Parameters\n";
else
	echo "Syntax Error\n";
?>