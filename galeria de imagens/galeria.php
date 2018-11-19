<! doctype html>
<html>
<head>
<meta charset="UTF-8">
<link rel="stylesheet" type="text/css" href="estilo.css">
</head>
<body>
<?php
$url_galeria = "http://localhost/galeria/galeria.php"; 

$pasta_fotos = "fotos_galeria";

$fotos = array();

foreach(glob($pasta_fotos . '/{*_p.jpg,*_p.png,*_p.gif}', GLOB_BRACE) as $image ){
 $fotos[] = $image;

}
if ($_GET['image'] == "") {
      for($i = 0; $i < count($fotos); $i++) {
      echo "<div class='thumb'>";
      echo "<a href=' " .$url_galeria. "?image=". $i." '>";
      echo "<img src=' ".$fotos[$i].  " '>";
      echo "</a>"; 
      echo "</div>";
      }
}
 else {
$foto_g = explode("_p", $fotos[$_GET['image']]);

if ( $_GET['image'] ==0){
$anterior = "";

} else {
$anterior = $_GET['image'] -1;
}
if ( $_GET['image'] == count($fotos) -1){
 $_proxima = "";
} else {
$proxima = $_GET['image'] +1;
}

echo "<div>";
echo "<a href=' ".$url_galeria."?image=".$proxima." '>";
echo "<img src=' " .$foto_g[0]. "_g".$foto_g[1]." '>";
echo"</a>";
echo "<p><a href=' " . $url_galeria. "?image=".$anterior." '>foto anterioro</a>";
echo "  | <a href=' " .$url_galeria. "?image='>voltar para a galeria</a>";
echo "  | <a href=' " .$url_galeria. "?image=".$proxima. " ' >foto seguinte</a> </p>";
echo "</div>";

}



?>
</body>
</html>
