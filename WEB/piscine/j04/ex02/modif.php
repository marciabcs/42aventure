<?php
	function put_error()
	{
		echo "ERROR\n";
		exit;
	}
	if ($_POST["submit"] !== "OK")
		put_error();
	if (!$_POST["login"] || !$_POST["oldpw"]|| !$_POST["newpw"])
		put_error();
	$data = file_get_contents("../private/passwd");
	if (!$data)
		put_error();
	$tab = unserialize($data);
	foreach ($tab as $key => $elem)
	{
		if ($elem['login'] === $_POST["login"])
		{
			$opw = $elem['passwd'];
			$index = $key;
		}
	}
	if ($opw === false)
		put_error();
	else
	{
		if ($opw !== hash("whirlpool", $_POST["oldpw"]))
			put_error();
		$tab[$index]["passwd"] = hash("whirlpool", $_POST["newpw"]);
	}
	file_put_contents("../private/passwd", serialize($tab));
	echo "OK\n";
?>