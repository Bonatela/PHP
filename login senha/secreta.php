<?php //secreta.php
session_start();
session_name('secreta');
if($_SESSION["validacao"]==1){
?>

// colocar paginas clonadas 

<?php
}
else{
echo "acesso negado!!!";
}
?>