<?php
    
     $texto = "mauro, o melhor prof do alcides";

  echo $texto;
  echo "<br>";
 
   $texto = strtoupper($texto);
   echo $texto;
   echo "<br>";

   $texto = strtolower($texto);
   echo $texto;
   echo "<br>";


   $texto = ucwords($texto);
   echo $texto;
   echo "<br>";



   $texto = strrev($texto);
   echo $texto;
   echo "<br>";

  $palindromo = "reviver";
   echo $palindromo;
   $palindromo = strrev($palindromo);
   echo "<br>";
   echo $palindromo;
   echo "<br>";

   $tamanho = strlen($texto);
   echo $tamanho;
   echo "<br>";

   $nome = "<b>Meu nome</b>";
   echo $nome;
   echo "<br>";
   $nome = strip_tags($nome);
   echo $nome;
   echo "<br>";

   $npalavras = str_word_count($texto);
   echo $npalavras;





?>