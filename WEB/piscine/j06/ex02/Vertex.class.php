<?php

Class Vertex {
	private $_x = 0;
	private $_y = 0;
	private $_z = 0;
	private $_w = 1.0;
	private $_color;
	public static $verbose = FALSE;
	public static function doc() 
	{
		return file_get_contents("Vertex.doc.txt");
	}
	public function getX() { return $this->_x; }
	public function getY() { return $this->_y; }
	public function getZ() { return $this->_z; }
	public function getW() { return $this->_w; }
	public function getColor() { return $this->_color; }
	function __construct( array $kwargs ) 
	{
		if ( isset( $kwargs['x'] ) && isset( $kwargs['y'] ) && isset( $kwargs['z'] ) ) {
			$this->_x = $kwargs['x'];
			$this->_y = $kwargs['y'];
			$this->_z = $kwargs['z'];
		}
		if ( isset( $kwargs['w'] ) ) 
		{
			$this->_w = $kwargs['w'];
		}
		else {
			$this->_w = 1.0;
		}
		if ( isset( $kwargs['color'] ) ) 
		{
			$this->_color = $kwargs['color'];
		}
		if ( self::$verbose === TRUE ) 
		{
			print( $this->__toString() . " constructed" . PHP_EOL);
		}
	}
	function __destruct() 
	{
		if ( self::$verbose === TRUE ) {
			print( $this->__toString()  . " destructed" . PHP_EOL);
		}
	}
	function __toString() 
	{
		$spr = ("Vertex( x: ".sprintf("%.2f",$this->getX()).", y: ".sprintf("%.2f",$this->getY()).", z:".sprintf("%.2f",$this->getZ()).", w:".sprintf("%.2f",$this->getW()));
		if ( self::$verbose == TRUE ) 
		{
				$spr = $spr . ", Color( red: 255, green: 255, blue: 255 )" ;
		}
		return $spr . " )";
	}
}
?>
