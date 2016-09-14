#!/usr/bin/php
<?php 
if ($argc == 2)
{
	$flag = 0;
	$av = $argv[1];
	$tab = explode(" ", $av);
	if (count($tab) != 5)
		$flag = 1;
	if (preg_match('/[0-9]{1,2}/', $tab[1]) == false)
		$flag = 1;
	if (preg_match('/[0-9]{4}/', $tab[3]) == false)
		$flag = 1;
	if (preg_match("/[0-9][0-9]:[0-9][0-9]:[0-9][0-9]/", $av) == false)
		$flag = 1;
	$old = $av;
	$av = preg_replace('/ [Jj]anvier /', ' January ', $av);
	$av = preg_replace('/ [Ff][eé]vrier /', ' February ', $av);
	$av = preg_replace('/ [Mm]ars /', ' March ', $av);
	$av = preg_replace('/ [Aa]vril /', ' April ', $av);
	$av = preg_replace('/ [Mm]ai /', ' May ', $av);
	$av = preg_replace('/ [Jj]uin /', ' June ', $av);
	$av = preg_replace('/ [Jj]uillet /', ' July ', $av);
	$av = preg_replace('/ [Aa]o[ûu]t /', ' August ', $av);
	$av = preg_replace('/ [Ss]eptembre /', ' September ', $av);
	$av = preg_replace('/ [Oo]ctobre /', ' October ', $av);
	$av = preg_replace('/ [Nn]ovembre /', ' November ', $av);
	$av = preg_replace('/ [Dd][eé]cembre /', ' December ', $av);
	if ($old == $av)
		$flag = 1;
	$old = $av;
	$av = preg_replace('/^[Dd]imanche /', 'Sunday ', $av);
	$av = preg_replace('/^[Ll]undi /', 'Monday ', $av);
	$av = preg_replace('/^[Mm]ardi /', 'Tuesday ', $av);
	$av = preg_replace('/^[Mm]ercredi /', 'Wendnesday ', $av);
	$av = preg_replace('/^[Jj]eudi /', 'Thursday ', $av);
	$av = preg_replace('/^[Vv]endredi /', 'Friday ', $av);
	$av = preg_replace('/^[Ss]amedi /', 'Saturday ', $av);
	if ($old == $av)
		$flag = 1;
	$day = explode(" ", $av);
	if (($day[1] > 30) && ($day[2] == 'April' || $day[2] == 'June' ||$day[2] == 'September'||$day[2] == 'November'))
	$flag = 1;
	if (($day[1] > 28) && ($day[2] == 'February') && (($day[3] % 4) != 0))
		$flag = 1;
	if (($day[1] > 29) && ($day[2] == 'February') &&(($day[3] % 4) == 0))
		$flag = 1;
	$date_to_check = strptime($my_date, "%w %d %m %Y %H:%M:%S");
	if ($date_to_check === 1)
			$flag = 1;
	if ($flag == 1)
		echo"Wrong Format\n";
	else
	{
		date_default_timezone_set('Europe/Paris');
		$seconds = strtotime($av);
		if (strlen($seconds) > 0)
			echo $seconds."\n";
		else
			echo"Wrong Format\n";

	}
}
?>