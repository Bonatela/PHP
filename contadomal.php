<body>

<h1>aula 2 php</h1>
<form method="post" action="contadomal.php">
numero 1:<input type="text" name="n1"><br>
numero 2:<input type="text" name="n2"><br>
<input type="submit" value="calcular">
</form>
<?php
$num1 = $_POST['n1'];
$num2 = $_POST['n2'];

$soma = $num1 + $num2;
echo "a soma é: " .$soma. "<br>";
$multiplicacao = $num1 * $num2;
echo "a multiplicacao é: " .$multiplicacao. "<br>";
$divisao= $num1 / $num2;
echo "a divisao é: " .$divisao. "<br>";
$subtracao= $num1 - $num2;
echo "a subtracao é: " .$subtracao. "<br>";







?>

</body>
</html>
