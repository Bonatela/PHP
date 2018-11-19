<!doctype html>
<html>
<head>
<meta charset="utf=8">
<title>peso </title>
</head>
<body>

<h1>imc </h1>
<form method="post" action="imc.php">
altura: <input type="text" name="alt"><br>
peso: <input type="text" name="peso"><br>
<input type="submit" value="Calcular">

</form>

<?php
$altura = $_POST['alt'];
$peso = $_POST['peso'];

$imc = $peso / ($altura * $altura);


if($imc <25)
{echo "bem magrinha: " .$imc."<br>";}

else 
if($imc <30)
{echo "viamao : " .$imc."<br>";}

else
if($imc <35)
{echo " a pessoa e nao e o super man : " .$imc."<br>";}

else

{echo "esta ali ali: " .$imc."<br>";}

?>




</body>
</html>