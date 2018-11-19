    <!DOCTYPE html>
    <html>
    <head>
            <meta charset="UTF-8">
            <title>Banco</title>
    </head>
    <body>
     
            <h1>Banco</h1>
     
            <form method="post" action="form.php">
            Depositar dinheiro: <input type="text" name="n1"><br>
            Sacar dinheiro: <input type="text" name="n2"><br>
            <input type="submit" value="Enviar">
            </form>
     
            <?php
		session_start();
		$depo=$_POST['n1'];
		$saca=$_POST['n2'];
		$_SESSION['saldo'];

		function depo($depo){
			$_SESSION['saldo'] = $_SESSION['saldo'] + $depo;

			echo "<br>";
		}
	
		depo($depo);

		function saca($saca){
			$_SESSION['saldo'] = $_SESSION['saldo'] - $saca;
		}
		
		saca($saca);

			echo "Seu saldo é: ".$_SESSION['saldo'];           
            ?>
    </body>
    </html>

