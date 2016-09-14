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
			$a = explode(' ', $av);
			$b = array_filter($a, "mb_strlen");
			if(count($b > 1))
				while($b[$j])
					$vet[$ind++] = $b[$j++];
			else
				$vet[$ind++] = $av;
		}
	}
	sort($vet);
	foreach ($vet as $key) {
		echo $key."\n";
	}
}
?>
