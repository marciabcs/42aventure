<?php
function auth($login, $passwd)
{
	if (!$data = file_get_contents("../private/passwd"))
		return FALSE;
	$tab = unserialize($data);
	$hashedpw = hash('whirlpool',$passwd);
	foreach ($tab as $key ) 
	{
	 	if($login === $key['login'] && $hashedpw === $key['passwd'])
	 		return TRUE;
	 }
	 return FALSE;
}
?>