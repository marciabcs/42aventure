<?php
class Lannister
{
	public function sleepWith($prenom)
	{
		if(is_a($prenom, 'Lannister'))
			print("Not even if I'm drunk !".PHP_EOL);
		else
			print("Let's do this.".PHP_EOL);
	}
}
?>