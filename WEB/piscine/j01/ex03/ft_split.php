<?PHP
function ft_split($av)
{
	if ($av)
	{
		$tab = explode(' ', $av);
		$tab2 = array_filter($tab, "mb_strlen");
		$tab = array_slice($tab2,0);
		sort($tab);
		return $tab;
	}
}
?>
