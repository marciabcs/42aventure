<?php
if ($_POST['submit'] == 'OK')
{
	if (!$_POST['login'] || !$_POST['passwd'])
	{
		 echo  "ERROR\n";
		 exit;
	}
	if (file_exists("../private/passwd") === true)
	{
		$tab = unserialize(file_get_contents("../private/passwd"));
		$index = 0;
		foreach ($tab as $key => $key2) 
		{
		 	if($key2['login'] === $_POST['login'])
		 	{
		 		echo  "ERROR\n";
		 		exit;
		 	}
		 } 
	}
	$tab1['login'] = $_POST['login'];
	$tab1['passwd'] = hash('whirlpool',$_POST['passwd']);
	$tab[] = $tab1;
	@mkdir("../private/", 0777);
	$data = serialize($tab);
	if (file_put_contents("../private/passwd", $data) !== false);
		echo  "OK\n";
}
else
	echo  "ERROR\n";
?>
