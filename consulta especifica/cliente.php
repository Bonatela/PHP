<?php  //cliente.php
class Cliente{
     public $codigo;
     public $nome;
	 public $endereco;
	 public $cidade;
     public $banco; //@@@@@@@
function conectar($banco){
$this->banco = $banco; //@@@@@
$lennon = mysql_connect("localhost","root","")
          or die("do not let me down!!!!");
		  mysql_select_db("$banco") //@@@@2
		  or die("help");
		  echo " Estabelecida!!<br>";
         }
		 
function consulta_especifica($cidade){
$this->cidade = $cidade;
$consulta="select codigo,nome, endereco, cidade from clientes
where cidade = '$cidade' ";
$resultado = mysql_query($consulta) or die("erro na consulta");
while($linha = mysql_fetch_assoc($resultado)){
echo "codigo: ".$linha['codigo']."<br>";
echo "NOME: ".$linha['nome']."<br>";
echo "ENDERECO: ".$linha['endereco']."<br>";
echo "CIDADE: ".$linha['cidade']."<br>";
echo "<br><br>";
}
}

		 
}
?>