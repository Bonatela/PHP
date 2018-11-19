<?php
	$nome = $_FILES['arquivo']['name'];
	echo $_FILES['arquivo']['name']."<br>";
	echo $_FILES['arquivo']['size']."<br>";
	echo $_FILES['arquivo']['type']."<br>";
	
	$pasta = "C:/htdocs/".$nome;
	
	if(move_uploaded_file($_FILES['arquivo']['tmp_name'],$pasta)){
		echo "Arquivo Enviado";
	}
	else {
		echo "Erro no Envio";
	}
?>