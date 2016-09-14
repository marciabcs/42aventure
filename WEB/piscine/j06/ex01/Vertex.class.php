<?php

require_once 'Color.class.php';

class Vertex {
	private 		$_x = 0.0;
	private 		$_y = 0.0;
	private 		$_z = 0.0;
	private 		$_w = 1.0;
	private 		$_color;
	public static 	$verbose = FALSE;
	
	public static function doc() {
		return (file_get_contents('./Vertex.doc.txt'));
	}

	public function __construct( array $kwargs ) {
		if (array_key_exists('x', $kwargs))
			$this->_x = $kwargs['x'];
		if (array_key_exists('y', $kwargs))
			$this->_y = $kwargs['y'];
		if (array_key_exists('z', $kwargs))
			$this->_z = $kwargs['z'];
		if (array_key_exists('w', $kwargs))
			$this->_w = $kwargs['w'];
		if (array_key_exists('color', $kwargs))
			$this->_color = clone $kwargs['color'];
		else
			$this->_color = new Color (array('rgb' => 0xFFFFFF));
		
		if (self::$verbose === True)
			print ( $this->__toString() . " constructed" . PHP_EOL);
	}	
	
	public function	__destruct() {
		if (self::$verbose === True)
			print ( $this->__toString() . " destructed" . PHP_EOL);
		return;
	} 

	public function __toString() {
		$my_xyz = ("Vertex( x: ".sprintf("%0.2f", $this->_x).", y: ".sprintf("%0.2f", $this->_y).", z:".sprintf("%0.2f", $this->_z).", w:".sprintf("%0.2f",$this->_w));

		if (self::$verbose === True)
			$my_xyz .= ", " .$this->_color . ")";
		else
			$my_xyz .=  " )";
		return ($my_xyz);
	} 
}
?>
