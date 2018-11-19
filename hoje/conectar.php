<?php    // conectar.php
$lennor = mysql_connect("localhost","root","") 
           or die ("do not  let me down!!!!");

echo " conexao estabelecida <br>";

mysql_select_db("maya")
       or die("help!");

echo " banco selecionado ";
 	        
?>






