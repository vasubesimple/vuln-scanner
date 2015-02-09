<?php

session_start();

if(isset($_REQUEST['logout'])){session_destroy();}

if(isset($_SESSION['username'])){header("location:index.php");die;} //not logged 

include('includes/db.php');

if(!empty($_POST['username']) && !empty($_POST['password'])){


$user=stripslashes($_POST['username']);
$pass=stripslashes(md5($_POST['password']));

$user = preg_replace("/[^a-zA-Z0-9]/", "", $user);
$pass = preg_replace("/[^a-zA-Z0-9]/", "", $pass);


$mysqli = new mysqli(DB_HOST, DB_USER, DB_PASS, DB_NAME);

 
    $sql = "SELECT * from login WHERE user='$user' AND pass='$pass'";
	
    $result = $mysqli->query($sql);
    
	
	while($row = mysqli_fetch_array($result)) {
	
    if ($result->num_rows == 1) {
			$_SESSION['username'] = $row['user'];
			header("location:index.php");
    }
	}

}
?>

<!DOCTYPE html>
<html>
  <head>
    <title>Login</title>
    <!-- Bootstrap -->
    <link href="bootstrap/css/bootstrap.min.css" rel="stylesheet" media="screen">
    <link href="bootstrap/css/bootstrap-responsive.min.css" rel="stylesheet" media="screen">
    <link href="assets/styles.css" rel="stylesheet" media="screen">
     <!-- HTML5 shim, for IE6-8 support of HTML5 elements -->
    <!--[if lt IE 9]>
      <script src="http://html5shim.googlecode.com/svn/trunk/html5.js"></script>
    <![endif]-->
    <script src="js/vendor/modernizr-2.6.2-respond-1.1.0.min.js"></script>
    <link rel="shortcut icon" type="image/png" href="./images/favicon.png"/>
  </head>
  <body id="login">
    <div class="container">

      <form class="form-signin" action="login.php" method="POST">
      <center><img src="./images/space.png" width="100" height="100">
        <h4 class="form-signin-heading">VulnDB</h4></center>
        <input name="username" type="text" class="input-block-level" placeholder="Nome de utilizador">
        <input name="password" type="password" class="input-block-level" placeholder="Senha">
        <!--<label class="checkbox">
          <input type="checkbox" value="remember-me"> Remember me
        </label>-->
        <button class="btn btn-primary" type="submit">Login</button>
      </form>

    </div> <!-- /container -->
    <script src="vendors/jquery-1.9.1.min.js"></script>
    <script src="bootstrap/js/bootstrap.min.js"></script>

  </body>
  
</html>