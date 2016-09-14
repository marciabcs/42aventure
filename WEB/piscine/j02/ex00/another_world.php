#!/usr/bin/php
<?php
$av = preg_replace('/[\s]+/', ' ', $argv[1]);
echo trim($av)."\n";
?>