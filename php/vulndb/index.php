<?php
session_start();

if(!isset($_SESSION['username'])){header("location:login.php");die;} //not logged 

include("includes/db.php");
include("includes/header.php");
include("includes/sidebar.php");



?>

        <script>
        
       //chart
       
        var chart = AmCharts.makeChart("chartdiv", {
    "type": "pie",
    "theme": "light",
    "dataProvider": [{
        "country": "Servi\u00E7os Vulner\u00E1veis",
        "value": <?php $result = mysqli_query($mysqli,"SELECT * FROM scans WHERE vuln=1");echo $count=mysqli_num_rows($result);?>

    }, {
        "country": "Inje\u00e7\u00e3o SQL",
        "value": <?php $result = mysqli_query($mysqli,"SELECT * FROM sqli WHERE vuln=1");echo $count=mysqli_num_rows($result);?>
    }, {
        "country": "Cross Site Scripting",
        "value": <?php $result = mysqli_query($mysqli,"SELECT * FROM xss WHERE vuln=1");echo $count=mysqli_num_rows($result);?>
    }, {
        "country": "Inclus\u00e3o de Ficheiros",
        "value": <?php $result = mysqli_query($mysqli,"SELECT * FROM inc_fich WHERE vuln=1");echo $count=mysqli_num_rows($result);?>
    }, {
        "country": "Revela\u00e7\u00e3o de Diret\u00f3rio",
        "value": <?php $result = mysqli_query($mysqli,"SELECT * FROM fpd WHERE vuln=1");echo $count=mysqli_num_rows($result);?>
    }, {
        "country": "For\u00e7a Bruta",
        "value": <?php $result = mysqli_query($mysqli,"SELECT * FROM bruteforce");echo $count=mysqli_num_rows($result);?>
    }],
    "valueField": "value",
    "titleField": "country",
    "outlineAlpha": 0.4,
    "depth3D": 15,
    "balloonText": "[[title]]<br><span style='font-size:14px'><b>[[value]]</b> ([[percents]]%)</span>",
    "angle": 30,
    "innerRadius": 60,
    "exportConfig":{	
      menuItems: [{
      icon: '/lib/3/images/export.png',
      format: 'png'	  
      }]  
	}
});
jQuery('.chart-input').off().on('input change',function() {
	var property	= jQuery(this).data('property');
	var target		= chart;
	var value		= Number(this.value);
	chart.startDuration = 0;
  

	target[property] = value;
	chart.validateNow();
});

        </script>
        
<style>
#chartdiv {
	width		: 100%;
	height		: 280px;
	font-size	: 11px;
}								
</style>

                <div class="span9" id="content">

                    <div class="row-fluid">
                        <!-- block -->
    

                        <div class="block">
                            <div class="navbar navbar-inner block-header">
                                <div class="muted pull-left">Total de Registos</div>
                                <!--<div class="pull-right"><span class="badge badge-warning">View More</span></div>-->
                            </div>
                            <div class="block-content collapse in">
                                <div class="span2">

                                
                                <div class="panel panel-primary">
<div class="panel-heading">
<h4 class="panel-title">
<center>
<a href="svc.php">Servi&#231;os</a>
</center>
</h4>
</div>
<div class="panel-body">
<center>
<h1><?php 	


$result = mysqli_query($mysqli,"SELECT * FROM scans ORDER BY id DESC");
$count=mysqli_num_rows($result);
echo $count;
?></h1>
</center>
</div>
</div>
                                
                                
                                </div>
                                <div class="span3">
                                <div class="panel panel-primary">
<div class="panel-heading">
<h4 class="panel-title">
<center>
<a href="ce.php">Inje&#231;&#227;o de C&#243;digo</a>
</center>
</h4>
</div>
<div class="panel-body">
<center>
<h1><?php 	


$result = mysqli_query($mysqli,"SELECT * FROM sqli ORDER BY id DESC");
$result2 = mysqli_query($mysqli,"SELECT * FROM xss ORDER BY id DESC");
$count=mysqli_num_rows($result) + mysqli_num_rows($result2);
echo $count;
?></h1>
</center>
</div>
</div>
                                </div>
                                <div class="span3">
<div class="panel panel-primary">
<div class="panel-heading">
<h4 class="panel-title">
<center>
<a href="fi.php">Inclus&#227;o de Ficheiros</a>
</center>
</h4>
</div>
<div class="panel-body">
<center>
<h1><?php 	


$result = mysqli_query($mysqli,"SELECT * FROM inc_fich ORDER BY id DESC");
$count=mysqli_num_rows($result);
echo $count;
?></h1>
</center>
</div>
</div>
                                </div>
                                <div class="span2">
<div class="panel panel-primary">
<div class="panel-heading">
<h4 class="panel-title">
<center>
<a href="fpd.php">Diret&#243;rios</a>
</center>
</h4>
</div>
<div class="panel-body">
<center>
<h1><?php 	


$result = mysqli_query($mysqli,"SELECT * FROM fpd ORDER BY id DESC");
$count=mysqli_num_rows($result);
echo $count;
?></h1>
</center>
</div>
</div>
                                </div>
                                
                                
                                                                <div class="span2">
<div class="panel panel-primary">
<div class="panel-heading">
<h4 class="panel-title">
<center>
<a href="bf.php">Credenciais</a>
</center>
</h4>
</div>
<div class="panel-body">
<center>
<h1><?php 	


$result = mysqli_query($mysqli,"SELECT * FROM bruteforce ORDER BY id DESC");
$count=mysqli_num_rows($result);
echo $count;
?></h1>
</center>
</div>
</div>
                                </div>
                                
                                
                            </div>
                        </div>
                        
                        
                        <!-- /block -->
                        
<div class="block">

                            <div class="navbar navbar-inner block-header">
                                <div class="muted pull-left">Percentagem de Vulnerabilidades</div>
                                
                            </div>
                            <div class="block-content collapse in">
                            <div id="chartdiv"></div>
                            </div>
                    


</div>			                   
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