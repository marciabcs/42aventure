<?php
function ft_is_sort($av)
{
	$str = $av;
	sort($av);
	return ($str === $av);
}
?>