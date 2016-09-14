<?php
require_once 'Vertex.class.php';

Class Vector {
	private $_x	= 0.0;
	private $_y = 0.0;
	private $_z = 0.0;
	private $_w = 0.0;
	public static $verbose = FALSE;

	public function getX() { return $this->_x; }
	public function getY() { return $this->_y; }
	public function getZ() { return $this->_z; }
	public function getW() { return $this->_w; }

	public static function doc()
	{
		return file_get_contents("Vector.doc.txt");
	}

	public function __construct( array $kwargs ) 
	{
		if ( isset( $kwargs['dest'] ) ) 
		{
			$dest = $kwargs['dest'];
		}
		if ( isset( $kwargs['orig'] ) ) 
		{
			$orig = $kwargs['orig'];
		}
		else 
		{
			$orig = new Vertex(array("x" => 0, "y" => 0, "z" => 0, "w" => 1 ));
		}
		$this->_x = $dest->getX() - $orig->getX();
		$this->_y = $dest->getY() - $orig->getY();
		$this->_z = $dest->getZ() - $orig->getZ();
		$this->_w = $dest->getW() - $orig->getW();
		if (self::$verbose === TRUE)
		{
			print("Vector( x:".sprintf("%.2f",$this->getX()).", y:".sprintf("%.2f",$this->getY()).", z:".sprintf("%.2f",$this->getZ()).", w:".sprintf("%.2f",$this->getW())." ) constructed\n");
		}
	}

	public function __destruct() 
	{
		if (self::$verbose === TRUE)
		{
			print("Vector( x:".sprintf("%.2f",$this->getX()).", y:".sprintf("%.2f",$this->getY()).", z:".sprintf("%.2f",$this->getZ()).", w:".sprintf("%.2f",$this->getW())." ) destructed\n");
		}
	}

	public function __toString()
	{
		return ("Vector( x:".sprintf("%.2f",$this->getX()).", y:".sprintf("%.2f",$this->getY()).", z:".sprintf("%.2f",$this->getZ()).", w:".sprintf("%.2f",$this->getW())." )");
	}
 
	public function magnitude()
	{
		return (sqrt(pow($this->getX(), 2) + pow($this->getY(), 2) + pow($this->getZ(), 2)));
	}

	public function normalize()
	{
		$new_dest = new Vertex(array( 'x' => ($this->getX() / $this->magnitude()),
								  'y' => ($this->getY() / $this->magnitude()),
								  'z' => ($this->getZ() / $this->magnitude())));
		return (new Vector(array("dest" => $new_dest)));
	}

	public function add(Vector $rhs)
	{
		$new_dest = new Vertex(array("x" => $this->getX() + $rhs->getX(), 
									"y" => $this->getY() + $rhs->getY(), 
									"z" => $this->getZ() + $rhs->getZ()));
		return (new Vector(array("dest" => $new_dest)));
	}

	public function sub(Vector $rhs)
	{
		$new_dest = new Vertex(array("x" => $this->getX() - $rhs->getX(), 
									"y" => $this->getY() - $rhs->getY(), 
									"z" => $this->getZ() - $rhs->getZ()));
		return (new Vector(array("dest" => $new_dest)));
	}

	public function opposite()
	{
		$new_dest = new Vertex(array("x" => -$this->getX(), "y" => -$this->getY(), "z" => -$this->getZ()));
		return (new Vector(array("dest" => $new_dest)));
	}

	public function scalarProduct($k)
	{
		$new_dest = new Vertex(array("x" => $this->getX() * $k, 
									"y" => $this->getY() * $k, 
									"z" => $this->getZ() * $k));
		return (new Vector(array("dest" => $new_dest)));
	}

	public function dotProduct(Vector $rhs)
	{
		return ($this->getX() * $rhs->getX() + $this->getY() * $rhs->getY() + $this->getZ() * $rhs->getZ());
	}

	public function cos(Vector $rhs)
	{
		return ($this->dotProduct($rhs) / ($this->magnitude() * $rhs->magnitude()));
	}

	public function crossProduct(Vector $rhs)
	{
		$new_dest = new Vertex(array("x" => $this->getY() * $rhs->getZ() - $this->getZ() * $rhs->getY(),
									"y" => -($this->getX() * $rhs->getZ() - $this->getZ() * $rhs->getX()),
									"z" => $this->getX() * $rhs->getY() - $this->getY() * $rhs->getX()));
		return (new Vector(array("dest" => $new_dest)));
	}
}
?>
