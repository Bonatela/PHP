<?php //consulta.php
$lennor = myqls_connect("localhost","root","") 
          or die ("vai se fude!!!!");
          mysql_select_db("maya")
          or die("gay!");
$consulta="select  numero,nome,quantidade,preco from jogos ";
$resultado = mysql_query($consulta) or die("saporra nao funciona");
while($linha = mysql_fetch_assoc($resultado)){
$numero = $linha['numero'];
echo "NOME: ".$linha['nome']."<br>";
echo "QUANTIDADE: ".$linha['quantidade']."<br>";
echo "PREÇO: ".$linha['preco']."<br>";
echo "<a href='excluir.php?numero=$numero'>Excluir</a> <br><br>";
}
?>