<!doctype html>
<html>
<head>
<meta charset="utf=8">
<title>Aula 2 PHP</title>
</head>
<body>

<h1>Aula 2 PHP</h1>
<form method="post" action="variaveis.php">
Numero 1: <input type="text" name="n1"><br>
Opreação: <input type="text" name="op"><br>
Numero 2: <input type="text" name="n2"><br>

<input type="submit" value="Calcular">
</form>

<?php
$num1 = $_POST['n1'];
$num2 = $_POST['n2'];
$op = $_POST['op'];

$soma = $num1 + $num2;
$subtracao = $num1 - $num2;
$multiplicacao = $num1 * $num2;
$divisao = $num1 / $num2;

if($op == "+")
{echo "A soma é: " .$soma."<br>";}

else 
if($op == "-")
{echo "A subtração é: " .$subtracao."<br>";}

else
if($op == "*")
{echo "A multiplicação é: " .$multiplicacao."<br>";}

else
if($op == "/")
{echo "A divisao é: " .$divisao."<br>";}

?>




</body>
</html>