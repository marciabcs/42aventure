#!/usr/bin/php
<?php

	function ft_search_op($string,$ope)
	{
		$flag = 1;
		$strexp = explode("$ope", trim($string));
		if (count($strexp) == 2)
		{
			$str1 = trim($strexp[0]);
			$str2 = trim($strexp[1]);
			if($str1[0] = "-")
				$str1a = substr($str1, 1);
			else
				$str1a = $str1;
			if($str2[0] = "-")
				$str2a = substr($str2, 1);
			else
				$str2a = $str2;
			if (is_numeric($str1a) && is_numeric($str2a))
			{
				if ($ope == "+")
					$res = ($str1 + $str2);
				if ($ope == "-")
					$res = ($str1 - $str2);
				if ($ope == "*")
					$res = ($str1 * $str2);
				if ($ope == "/")
					$res = ($str1 / $str2);
				if ($ope == "%")
					$res = ($str1 % $str2);
				echo $res."\n";;
				$flag = 0;
			}
		}
		return $flag;
	}

	if ($argc != 2)
	{
    	echo "Incorrect Parameters\n";
    	exit (1);
	}
	$tabop = array("+", "-", "*", "/", "%");
	$id = 0;
	while ($id < 5)
	{
			$result = ft_search_op($argv[1], $tabop[$id++]);
			if ($result == 0)
				break;
	}
	if ($result == 1)
	{
    	echo "Syntax Error\n";
		exit (1);
	}
	exit (0);
?>