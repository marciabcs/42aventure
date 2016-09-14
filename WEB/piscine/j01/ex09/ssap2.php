#!/usr/bin/php
<?php
if ($argc > 1)
{
	$ind = 0;

	foreach($argv as $av)
	{
		if($av == $argv[0])
			continue;
		else
		{
			$j = 0;
			$b = explode(' ', trim($av));
			$b = array_filter($b, 'mb_strlen');
			if(count($b > 1))
				while($b[$j])
					$vet[$ind++] = $b[$j++];
			else
				$vet[$ind++] = $av;
		}
	}
	$arr1 = $arr2 = $arr3 = array();
	foreach ($vet as $val)
	{

		if (is_numeric($val)) 
			array_push($arr2, $val); 
		else if (ctype_alpha($val))
			array_push($arr1, $val);
		else
			array_push($arr3, $val);

	} 
	natcasesort($arr1);
	sort($arr2, SORT_STRING);
	sort($arr3, SORT_STRING);
	$vet = array_merge($arr1, $arr2, $arr3);
	foreach ($vet as $key)
		echo $key."\n";
}
?>