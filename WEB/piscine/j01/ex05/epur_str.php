#!/usr/bin/php
<?php
if ($argc == 2)
{
	$av = explode(' ', $argv[1]);
	$av1 = array_filter($av, "mb_strlen");
	$str = implode(" ", $av1);
	echo $str."\n";
}
?>
