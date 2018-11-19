<?php
$login = $_POST['login'];
$senha = $_POST['senha'];
if($login == "aluno" && $senha == "12345"){
session_start();
session_name('secreta');
$_SESSION['validacao']=1;
$_SESSION['login']=$login;
header("Location: secreta.php");
}
else{
echo ("usuário ou senha inválidos");
}
?>