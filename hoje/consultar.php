<form name="form1" method="post" action=""> 
  <label>
  <input type="text" name="jogo" id="textfield">
</label>
<label>
  <input type="submit" name="button" id="button" value="Submit">
<label>
</form>
</br>
<?php    // consultar.php
$jogo = $_POST['jogo'];
$lennor = mysql_connect("localhost","root","") 
           or die ("do not  let me down!!!!");
           mysql_select_db("maya")
           or die("help!");
$consulta="select nome,quantidade,preco from jogos
                     WHERE nome='$jogo' ";
 
$resultado = mysql_query($consulta) or die ("erro consulta");
while($linha = mysql_fetch_assoc($resultado) ) {

echo "nome:".$linha ['nome']."<br>";
echo "quantidade:".$linha ['quantidade']."<br>";
echo "preco:".$linha ['preco']."<br><br>";
}
?>

