<?php

if(isset($_REQUEST['add'])){

if(isset($_REQUEST['token'])){


include("db.php");

$token = preg_replace("/[^a-zA-Z0-9]/", "", $_REQUEST['token']);

$result = mysqli_query($mysqli,"SELECT token FROM settings WHERE token='$token'");
if($count=mysqli_num_rows($result) == 1){


$tabela = $_REQUEST['tabela'];
                        
                        if($tabela == 'scans'){
                        
                        $host = htmlentities($_REQUEST['host']);
                        $porta = htmlentities($_REQUEST['porta']);
                        $servico = htmlentities($_REQUEST['servico']);
                        $software = htmlentities($_REQUEST['software']);
                        $vuln= htmlentities($_REQUEST['vuln']);

    $stmt = $mysqli->prepare("INSERT INTO scans (host,porta,servico,software,vuln) VALUES (?,?,?,?,?)");
  
    $stmt->bind_param("sssss", $host,$porta,$servico,$software,$vuln);

    $stmt->execute();
    
                        
                        }elseif($tabela == 'xss'){
                        
                                          $url = htmlentities($_REQUEST['url']);
                        $payload = htmlentities($_REQUEST['payload']);
                        $vuln = htmlentities($_REQUEST['vuln']);


    $stmt = $mysqli->prepare("INSERT INTO xss (url,payload,vuln) VALUES (?,?,?)");
  
    $stmt->bind_param("sss", $url,$payload,$vuln);

    $stmt->execute();
          
                        
                        }elseif($tabela == 'sqli'){
                        
                         $url = htmlentities($_REQUEST['url']);
                        $metodo = htmlentities($_REQUEST['metodo']);
                        $postdata = htmlentities($_REQUEST['postdata']);
                        $vuln = htmlentities($_REQUEST['vuln']);


    $stmt = $mysqli->prepare("INSERT INTO sqli (url,metodo,postdata,vuln) VALUES (?,?,?,?)");
  
    $stmt->bind_param("ssss", $url,$metodo,$postdata,$vuln);

    $stmt->execute();
                        
                        }elseif($tabela == 'inc_fich'){
                        
                        
                         $url = htmlentities($_REQUEST['url']);
                        $tipo = htmlentities($_REQUEST['tipo']);
                        $payload = htmlentities($_REQUEST['payload']);
                        $vuln = htmlentities($_REQUEST['vuln']);


    $stmt = $mysqli->prepare("INSERT INTO inc_fich (url,tipo,payload,vuln) VALUES (?,?,?,?)");
  
    $stmt->bind_param("ssss", $url,$tipo,$payload,$vuln);

    $stmt->execute();
                        
                        
                        }elseif($tabela == 'fpd'){
                        
                                                 $url = htmlentities($_REQUEST['url']);
                        $payload = htmlentities($_REQUEST['payload']);
                        $vuln = htmlentities($_REQUEST['vuln']);


    $stmt = $mysqli->prepare("INSERT INTO fpd (url,payload,vuln) VALUES (?,?,?)");
  
    $stmt->bind_param("sss", $url,$payload,$vuln);

    $stmt->execute();
                        
                        
                        
                        }elseif($tabela == 'bruteforce'){
                        
                        
                                                 $target = htmlentities($_REQUEST['target']);
                        $porta = htmlentities($_REQUEST['porta']);
                        $protocolo = htmlentities($_REQUEST['protocolo']);
                        $user = htmlentities($_REQUEST['user']);
                         $pass = htmlentities($_REQUEST['pass']);


    $stmt = $mysqli->prepare("INSERT INTO bruteforce (target,porta,protocolo,user,pass) VALUES (?,?,?,?,?)");
  
    $stmt->bind_param("sssss", $target,$porta,$protocolo,$user,$pass);

    $stmt->execute();
    
                                        
                        }
                        

            $stmt->close();

    $mysqli->close();
    
}}}


?>