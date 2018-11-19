<?php //excluir.php
$numero = $GET_['numero'];
$lennor = mysql_connect("localhost","root","") 
          or die ("do not  let me down!!!!");
          mysql_select_db("maya")
          or die("help!");
		  $excluir="delete from jogos where numero='$numero'";
		  $resultado = mysql_query($excluir) or die("erro ao excluir");
		  echo " jogo exluido com sucesso!!!";
		  
		  
?>