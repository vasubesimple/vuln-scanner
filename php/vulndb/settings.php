<?php
session_start();
if(!isset($_SESSION['username'])){header("location:login.php");die;} //not logged 

include("includes/db.php");

include("includes/header.php");
include("includes/sidebar.php");

if(isset($_POST['newtoken'])){

$newtoken = preg_replace("/[^a-zA-Z0-9]/", "", md5(rand(0,1337)));

$result = mysqli_query($mysqli,"UPDATE settings SET token='$newtoken' WHERE id=1");

}


?>


                <div class="span9" id="content">
                
<div class="row-fluid">

<div class="span12">
<?php
if(!empty($_POST['newpass'])){

$newpass = md5($_POST['newpass']);

$current = $_SESSION['username'];

    $stmt = $mysqli->prepare("UPDATE login SET pass=? WHERE user='$current'");
    $stmt->bind_param("s", $newpass);
    $result = $stmt->execute();
    
    if($result){
    
    echo '<div class="alert alert-success">
<button class="close" data-dismiss="alert">&#215;</button>
<strong>Sucesso!</strong>
Senha alterada com sucesso.
</div>';}else{

echo '<div class="alert alert-error">
<button class="close" data-dismiss="alert">&#215;</button>
<strong>Erro!</strong>
Erro ao alterar a senha.
</div>';}}
?>


                        <div class="block">

                            <div class="navbar navbar-inner block-header">
                            
                                <div class="muted pull-left">Gerir chaves de seguran&#231;a</div>
                                <!--<div class="pull-right"><span class="badge badge-warning">View More</span></div>-->
                            </div>
<div class="block-content collapse in">

<form action="settings.php" method="post" class="form-horizontal">
<fieldset>
<div class="control-group">
<label class="control-label">Token</label>
<div class="controls">
<span class="input-xlarge uneditable-input"><?php $result = mysqli_query($mysqli,"SELECT token FROM settings");while($row = mysqli_fetch_array($result)) { echo $row['token'];} ?></span> 
<button name="newtoken" class="btn btn-inverse">
<i class="icon-refresh icon-white"></i>
Gerar
</button>
</div>
</div>

</form>
<form method="post" action="settings.php">

<div class="control-group">
<label class="control-label">Senha de utilizador</label>
<div class="controls">
<input name="newpass" id="focusedInput" class="input-xlarge focused" type="password" >
<button class="btn btn-primary">
<i class="icon-pencil icon-white"></i>
Alterar
</button>
</div>
</div>

</form>


</div></div></div>



</div>




 
                </div>
                
                
                
             
                
            </div>
            <hr>
            <footer>
                <p>&copy; VulnDB | <a href="https://github.com/joaovarelas">Jo&#227;o Varelas</a></p>
            </footer>
        </div>
        <!--/.fluid-container-->
        <script src="vendors/jquery-1.9.1.min.js"></script>
        <script src="bootstrap/js/bootstrap.min.js"></script>
        <script src="vendors/easypiechart/jquery.easy-pie-chart.js"></script>
        <script src="assets/scripts.js"></script>

    </body>

</html>