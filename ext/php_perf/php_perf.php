<?php
$br = (php_sapi_name() == "cli")? "":"<br>";

if(!extension_loaded('php_perf')) {
	dl('php_perf.' . PHP_SHLIB_SUFFIX);
}
echo hello_world(10000000).PHP_EOL;
echo print_r(count(perf_array()),true).PHP_EOL;
echo "\n";
?>
