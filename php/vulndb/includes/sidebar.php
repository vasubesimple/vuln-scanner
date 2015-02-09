<?php


if(!isset($_SESSION['username'])){header("location:../login.php");die;} //not logged 
?>

        <div class="container-fluid">
            <div class="row-fluid">
                <div class="span3" id="sidebar">
                    <ul class="nav nav-list bs-docs-sidenav nav-collapse collapse">
                        <li <?php if(basename($_SERVER["SCRIPT_FILENAME"]) == 'index.php'){echo ' class="active" ';}?>>
                            <a href="index.php"><i class="icon-chevron-right"></i> P&#225;gina Inicial</a>
                        </li>
                        
                        <li <?php if(basename($_SERVER["SCRIPT_FILENAME"]) == 'svc.php'){echo ' class="active" ';}?>>
                            <a href="svc.php"><i class="icon-chevron-right"></i> Servi&#231;os Vulner&#225;veis</a>
                        </li>
                        
                        <li <?php if(basename($_SERVER["SCRIPT_FILENAME"]) == 'ce.php'){echo ' class="active" ';}?>>
                            <a href="ce.php"><i class="icon-chevron-right"></i> Inje&#231;&#227;o de C&#243;digo JS/SQL</a>
                        </li>
                        
                        <li <?php if(basename($_SERVER["SCRIPT_FILENAME"]) == 'fi.php'){echo ' class="active" ';}?>>
                            <a href="fi.php"><i class="icon-chevron-right"></i> Inclus&#227;o de Ficheiros</a>
                        </li>
                        
                        <li <?php if(basename($_SERVER["SCRIPT_FILENAME"]) == 'fpd.php'){echo ' class="active" ';}?>>
                            <a href="fpd.php"><i class="icon-chevron-right"></i> Diret&#243;rios Completos</a>
                        </li>
                        
                       <!-- <li <?php //if(basename($_SERVER["SCRIPT_FILENAME"]) == 'dns.php'){echo ' class="active" ';}?>>
                            <a href="dns.php"><i class="icon-chevron-right"></i> Transf. de Zonas DNS</a>
                        </li>-->
                        
                        <li <?php if(basename($_SERVER["SCRIPT_FILENAME"]) == 'bf.php'){echo ' class="active" ';}?>>
                            <a href="bf.php"><i class="icon-chevron-right"></i> Credenciais</a>
                        </li>

                    </ul>
                </div>
                
                <!--/span-->