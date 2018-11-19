<?php
$nome = $_post ['nome'];
$quantidade = $_post ['quantidade'];
$preco = $_post ['preco'];
$imagem = $_FILES['arquivo'] ['name'];
$pasta = "c:/htdocs/".$imagem;
if(move_uploaded_file($_FILES['arquivo']['tmp_name'],$pasta)){
$lennor = mysql_connect("localhost","root","") 
          or die ("do not  let me down!!!!");
          mysql_select_db("maya")
          or die("help!");
$incluir= "insert into jogos
         (nome,quantidade,preco,imagem)
		 values
	('$nome','$quantidade','$preco'$imagem)";
	$r = mysql_query($incluir) or die("woman!");
echo " jogo inserido com sucesso ";
}else{
echo " erro no encluisao ";
}
?>