#!/usr/bin/php
<?PHP
while(true)
{
	$num = fopen('php://stdin', 'r');
	echo "Entrez un nombre: ";
	$a = fgets($num);
	if ($a == false)
		exit;
	else
	{
		$a = trim($a);
		if (is_numeric($a))
		{
			if (($a % 2) == 0)
				echo "Le chiffre $a est Pair\n";
			else
				echo "Le chiffre $a est Impair\n";
		}
		else
			echo "'$a' n'est pas un chiffre\n";
	}
}
?>