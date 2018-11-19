<?php
session_start();
session_name('secreta');
unset($_SESSION['validacao']); //dessetando as variaveis
unset($_SESSION['login']);
session_destroy(); // destruindo a sessão
header("location: index.php");
?>