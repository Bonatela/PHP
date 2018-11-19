<?php
$nome = $_post ['nome'];
$quantidade = $_post ['quantidade'];
$preco = $_post ['preco'];
$lennor = mysql_connect("localhost","root","") 
          or die ("do not  let me down!!!!");
          mysql_select_db("maya")
          or die("help!");
$incluir="insert into jogos
         (nome,quantidade,preco)
		 values
		 ('$nome','$quantidade','$preco')";
	$r = mysql_query($incluir) or die("woman!");
		 echo " jogo inserido com sucesso ";		  	  
?>