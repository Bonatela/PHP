<?php

$x = 2;
$y = 10;

$s = $x + $y;
echo $s;

$m = $x * $y;
echo $m;

$d = $x / $y;
echo $d;

$r = $x - $y;
echo $r;

echo "<br>";
$dado = rand(1,6);
echo $dado;

//caça
//variaveis
$aleatorio1 = rand(1,6);
$aleatorio2 = rand(1,6);
$aleatorio3 = rand(1,6);
$aleatorio4 = rand(1,6);
$aleatorio5 = rand(1,6);
$aleatorio6 = rand(1,6);
$aleatorio7 = rand(1,6);
$aleatorio8 = rand(1,6);
$aleatorio9 = rand(1,6);


?> 
<table>
<tr>
<td><?php echo $aleatorio1; ?></td>
<td><?php echo $aleatorio2; ?></td>
<td><?php echo $aleatorio3; ?></td>
</tr>
<tr>
<td><?php echo $aleatorio4; ?></td>
<td><?php echo $aleatorio5; ?></td>
<td><?php echo $aleatorio6; ?></td>
</tr>
<tr>
<td><?php echo $aleatorio7; ?></td>
<td><?php echo $aleatorio8; ?></td>
<td><?php echo $aleatorio9; ?></td>

</table>


<?php

// 123 / 17

$r = 123 / 17;
echo $r;

echo "<br>";

$r = round($r);
echo $r;

echo "<br>";

$r = round($r , 2);
echo $r;
echo "<br>";

$p = pi ();
echo $p;
echo "<br>";

$ex = pow(5,2);
echo $ex;


$raio = 6;
$perimetro = 2 * $p *$raio;
$area = $p * pow($raio ,2);

?>
<br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br>

