<?php //executor.php
include "cliente.php";
$ob = new cliente();
$ob->conectar("t3it1_dbloja");
$ob->consulta_especifica("Canoas");
?>