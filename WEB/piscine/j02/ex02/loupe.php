#!/usr/bin/php
<?php

function myupper($str)
{
	return $str[1].strtoupper($str[2]).$str[3];
}

function premier($str)
{
	$regex = array('/(>)(.*?)(<)/s', '/(title=")(.*?)(")/s');
	$str1 = preg_replace_callback($regex, 'myupper', $str[0]);
	return $str1;
}
if($argc == 2)
{
	$text = file($argv[1]);
	
	$str = implode('', $text);
	$str = preg_replace_callback('/<a href=(.*?)<\/a>/s', 'premier', $str);
	echo $str;
}
?>