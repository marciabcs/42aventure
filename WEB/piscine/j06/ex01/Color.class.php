<?php
class Color {

	Public $red = 0;
	public $green = 0;
	public $blue = 0;
	public static $verbose = TRUE;

	public static function doc(){
		return file_get_contents('Color.doc.txt');
	} 
	public function __toString(){
		return ("Color( red: ".sprintf("%3d", $this->red).", green :".sprintf("%3d",$this->green).", blue: ".sprintf("%3d",$this->blue)." ) ");
	}
	public function __construct(array $kwargs){
		if (array_key_exists('red', $kwargs) && array_key_exists('green', $kwargs) && array_key_exists('blue', $kwargs))
		{
			if ($kargs['red'] >= 0 && $kargs['red'] <= 255)
				$this->red = $kwargs['red'];
			if ($kargs['green'] >= 0 && $kargs['green'] <= 255)
				$this->green = $kwargs['green'];
			if ($kargs['blue'] >= 0 && $kargs['blue'] <= 255)
				$this->blue = $kwargs['blue'];
		}
		else if (array_key_exists('rgb', $kwargs))
		{
			$this->red = ($kwargs['rgb'] >> 16) & 0xff;
			$this->green = ($kwargs['rgb'] >> 8) & 0xff;
			$this->blue = ($kwargs['rgb']) & 0xff;
		}
		else
		{
			print("Invalid arguments" . PHP_EOL);
			exit(1);
		}
		if(self::$verbose == TRUE)
		{
			print($this->__toString() . "constructed." . PHP_EOL);
		}
		return;
	}
	public function __destruct(){
		if(self::$verbose == TRUE)
		{
			print($this->__toString() . "destructed." . PHP_EOL);
		}
		return;
	}
	public function add($col){
		
		return	new Color (array( 'red' => ($this->red + $col->red)  & 0xff  , 'green' => ($this->green + $col->green) & 0xff , 'blue' => ($this->blue + $col->blue)  & 0xff ));
		
	}
	public function sub($col){
		return	new Color (array( 'red' => ($this->red - $col->red)  & 0xff , 'green' => ($this->green - $col->green)  & 0xff , 'blue' => ($this->blue - $col->blue)  & 0xff ));
	}
	public function mult($f){
		return	new Color (array( 'red' => $f * ($this->red) & 0xff, 'green' => $f * ($this->green) & 0xff , 'blue' => $f * ($this->blue) & 0xff ));
	}
}
?>
