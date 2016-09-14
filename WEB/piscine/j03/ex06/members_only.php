<?php
$valid_passw = array ("zaz" => "jaimelespetitsponeys");
$valid_user = array_keys($valid_passw);

$user = $_SERVER['PHP_AUTH_USER'];
$passw = $_SERVER['PHP_AUTH_PW'];

$test = (in_array($user, $valid_user)) && ($passw == $valid_passw[$user]);

if ($test) 
{
	 header('Content-type : text/html');
	 echo "<html><body>\nBonjour Zaz<br />\n<img src='data:image/png;base64,";
	 echo base64_encode(file_get_contents("../img/42.png"));
	 echo "'>\n</body></html>\n";
}
else
{
	header("HTTP 1.0, assume close after body");
	header("HTTP/1.0 401 Unauthorized");
	header("WWW-Authenticate: Basic realm=''Espace membres''");
	echo "<html><body>Cette zone est accessible uniquement aux membres du site</body></html>";
}
?>
