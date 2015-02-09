<?php
session_start();
if(!isset($_SESSION['username'])){header("location:login.php");die;} //not logged 
include("includes/db.php");

include("includes/header.php");
include("includes/sidebar.php");
?>



                <div class="span9" id="content">
<div class="row-fluid">
                        <!-- block -->
                        
                                                <?php
                        
                        
                        
                        
                        if(isset($_POST['del']) && isset($_POST['checkbox'])){
$cheks = implode("','", $_POST['checkbox']);
preg_replace("/[^0-9]/", "",$cheks);
$sql = "delete from fpd where id in ('$cheks')";
$result = mysqli_query($mysqli,$sql);

 if($result){
    
    echo '<div class="alert alert-success">
<button class="close" data-dismiss="alert">&#215;</button>
<strong>Sucesso! </strong>
 Registos eliminados com sucesso.
</div>';}else{

echo '<div class="alert alert-error">
<button class="close" data-dismiss="alert">&#215;</button>
<strong>Erro!</strong>
 Registos n&#227;o eliminados.
</div>';

}
}

?>


                        <div class="block">
                            <div class="navbar navbar-inner block-header">
                                <div class="muted pull-left">Diret&#xF3;rios Completos</div>
                            </div>
                            <div class="block-content collapse in">
                                <div class="span12">
                                
<form action="fpd.php" method="POST">
  									<table class="table table-condensed">
						              <thead>
						                <tr>
						                  <th>URL</th>
						                  <th>Payload</th>
                                          <th>Vulner&#225;vel</th>
                                         
						                </tr>
						              </thead>
						              <tbody>
                                      
                                                                      	<?php
			
			
	$result = mysqli_query($mysqli,"SELECT * FROM fpd ORDER BY id DESC");
	
	
	
	
while($row = mysqli_fetch_array($result)) {

?>
						                <tr>
						                  <td><a href="<?php echo $row['url'];?>"><?php echo (strlen($row['url']) > 50 ? substr($row['url'], 0, 50)."..." : $row['url']);?></a></td>
						                  <td><?php echo $row['payload'];?></td>
                                          <td><?php if($row['vuln'] == '1'){echo '<font color="#A10000">Sim</font>';}else{echo '<font color="#3C8F3C">N&#227;o</font>';}?></td>
                                          <td><input name="checkbox[]" type="checkbox" value="<?php echo $row['id']; ?>"></td>
						                </tr>
                                        
						                <?php }; ?>
                                        
						              </tbody>
						            </table>
                                    
                                </div>
                            </div>
                        </div>
                         <p align="right"><input type="checkbox" onClick="toggle(this)" /> All</p>
                        <button style="float:right" class="btn btn-danger" name="del"><i class="icon-remove icon-white"></i>Delete</button></p>
                        <!-- /block -->
                        </form>
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
        <script>
        $(function() {
            // Easy pie charts
            $('.chart').easyPieChart({animate: 1000});
        });
        </script>
    </body>

</html>