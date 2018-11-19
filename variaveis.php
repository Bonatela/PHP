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
Numero 2: <input type="text" name="n2"><br>
<input type="submit" value="Calcular">
</form>

<?php
$num1 = $_POST['n1'];
$num2 = $_POST['n2'];

$soma = $num1 + $num2;
echo "A soma é: " .$soma. "<br>";
$subtracao = $num1 - $num2;
echo "A subtração é: " .$subtracao. "<br>";
$multiplicacao = $num1 * $num2;
echo "A multiplicação é: " .$multiplicacao. "<br>";
$divisao = $num1 / $num2;
echo "A divisão é: " .$divisao. "<br>";

if($num1 > $num2){
	echo "O primeiro número é maior<br>";
} else if($num2 > $num1) {
	echo "O segundo número é maior<br>";
} else {
	echo "Os números são iguais<br>";
}

?>




</body>
</html>