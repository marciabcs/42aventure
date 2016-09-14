<?php
session_start();
if ($_GET['submit'] == 'OK')
{
	$_SESSION['login'] = $_GET['login'];
	$_SESSION['passwd']= $_GET['passwd'];
}
?>
<html><body>
<form action="index.php" method="get">
	Identifiant : <input id="login" name="login" value= <?php echo '"'.$_SESSION['login'].'"' ; ?> type="text"> 
	<br /> 
	Mot de passe : <input id="passwd" name="passwd" value= <?php echo '"'.$_SESSION['passwd'].'"' ;?> type="text">
	<input  type="submit" value="OK" name="submit">
</form>
</body></html>