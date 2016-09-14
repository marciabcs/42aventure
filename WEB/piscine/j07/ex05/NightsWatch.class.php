<?php
class NightsWatch implements IFighter
{
	private $_fight = array();

	public function recruit($soldier)
	{
		if ($soldier instanceof IFighter)
		{
			array_push($this->_fight, $soldier);
		}
	}
	 public function fight()
	 {
	 	foreach ($this->_fight as $soldier) 
	 	{
	 		$soldier->fight();
	 	}
	}
}
?>