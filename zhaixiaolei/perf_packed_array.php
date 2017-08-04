<?php

$MAX_COUNT=1000*10000;

$t1 = microtime(true);
$array1=[];
for ($i=0; $i < $MAX_COUNT; $i++) {
  # code...
  $array1[$i]=1;
}
$t2 = microtime(true);

unset($array1);

$t2 = microtime(true);

$array2=[];
for ($i=$MAX_COUNT; $i >0 ; $i--) {
  # code...
  $array2[$i]=1;
}
$t3 = microtime(true);

echo $t2-$t1,",",$t3-$t2,"\n";
 ?>
