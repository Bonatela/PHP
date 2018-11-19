/*
SQLyog Community v9.63 
MySQL - 5.5.8 : Database - t3it1_dbloja
*********************************************************************
*/

/*!40101 SET NAMES utf8 */;

/*!40101 SET SQL_MODE=''*/;

/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;
CREATE DATABASE /*!32312 IF NOT EXISTS*/`t3it1_dbloja` /*!40100 DEFAULT CHARACTER SET latin1 */;

USE `t3it1_dbloja`;

/*Table structure for table `amigos` */

DROP TABLE IF EXISTS `amigos`;

CREATE TABLE `amigos` (
  `codigo` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `nome` varchar(50) DEFAULT NULL,
  `nascimento` datetime DEFAULT NULL,
  `endereco` varchar(50) DEFAULT NULL,
  `cidade` varchar(50) DEFAULT NULL,
  `estado` char(2) DEFAULT NULL,
  `cep` char(9) DEFAULT NULL,
  `informacoes` varchar(200) DEFAULT NULL,
  PRIMARY KEY (`codigo`)
) ENGINE=InnoDB AUTO_INCREMENT=4 DEFAULT CHARSET=latin1;

/*Data for the table `amigos` */

insert  into `amigos`(`codigo`,`nome`,`nascimento`,`endereco`,`cidade`,`estado`,`cep`,`informacoes`) values (1,'João maria','2000-10-10 00:00:00','rua x, 20','Porto Alegre','RS','90000-000','nenhuma informação'),(2,'Pedro paulo','2001-11-11 00:00:00','rua y, 30','Canoas ','RS','92000-000','nada a declarar'),(3,'Maria da Costa','2002-12-12 00:00:00','rua x, 30\'','Canoas','RS','92000-000','nada a declarar');

/*Table structure for table `clientes` */

DROP TABLE IF EXISTS `clientes`;

CREATE TABLE `clientes` (
  `codigo` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `nome` varchar(80) DEFAULT NULL,
  `nascimento` datetime DEFAULT NULL,
  `endereco` varchar(80) DEFAULT NULL,
  `cidade` varchar(80) DEFAULT NULL,
  `estado` char(2) DEFAULT NULL,
  `cep` char(9) DEFAULT NULL,
  PRIMARY KEY (`codigo`)
) ENGINE=InnoDB AUTO_INCREMENT=11 DEFAULT CHARSET=latin1;

/*Data for the table `clientes` */

insert  into `clientes`(`codigo`,`nome`,`nascimento`,`endereco`,`cidade`,`estado`,`cep`) values (1,'Elias Baiano','1910-12-27 00:00:00','Rua x, 10','Viamão','RS','89000-000'),(2,'Fausto Silva','1920-10-15 00:00:00','Rua y, 20','Porto Alegre','RS','90000-000'),(3,'Vava Rita Lee dos santos','1935-11-11 00:00:00','Rua x, 30','Porto Alegre','RS','90000-000'),(4,'Marcio Lulu Santos','1940-03-22 00:00:00','Rua w, 30','Canoas','RS','92000-000'),(5,'Eisenberg Reis','1950-12-12 00:00:00','Rua x, 30','São Leopoldo','RS','93000-000'),(6,'Vitor Goleiro Bruno','1960-05-19 00:00:00','Rua x, 30','Esteio','RS','97000-000'),(7,'Rubens Xuxa ','1970-06-20 00:00:00','Rua xc, 30','Porto Alegre','RS','90000-000'),(8,'Doctor Ray','1980-10-23 00:00:00','Rua x, 30','Canoas','RS','92000-000'),(9,'Arcides Mala','1901-12-28 00:00:00','Rua xc, 30','Porto Alegre','RS','90000-000'),(10,'Ze Coalhada Silva','1920-10-23 00:00:00','Rua x, 30','Canoas','RS','92000-000');

/*Table structure for table `fornecedores` */

DROP TABLE IF EXISTS `fornecedores`;

CREATE TABLE `fornecedores` (
  `codigo` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `nome_empresa` varchar(50) DEFAULT NULL,
  `endereco` varchar(50) DEFAULT NULL,
  `cidade` varchar(50) DEFAULT NULL,
  `estado` char(2) DEFAULT NULL,
  `cep` char(9) DEFAULT NULL,
  `cnpj` varchar(30) DEFAULT NULL,
  `fone` varchar(40) DEFAULT NULL,
  PRIMARY KEY (`codigo`)
) ENGINE=InnoDB AUTO_INCREMENT=4 DEFAULT CHARSET=latin1;

/*Data for the table `fornecedores` */

insert  into `fornecedores`(`codigo`,`nome_empresa`,`endereco`,`cidade`,`estado`,`cep`,`cnpj`,`fone`) values (1,'Hering','rua x, 30','São Paulo','SP','77000-000','23232323','3232323'),(2,'Papelaria Brasil','Rua Voluntarios da Patria','Porto Alegre','RS','90000-000','56454564564','78565'),(3,'Bic SA','Rua x, sn','Rio de janeiro','RJ','88000-000','676768','76767');

/*Table structure for table `produtos` */

DROP TABLE IF EXISTS `produtos`;

CREATE TABLE `produtos` (
  `codigo` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `nome` varchar(50) DEFAULT NULL,
  `descricao` varchar(50) DEFAULT NULL,
  `preco` decimal(10,0) DEFAULT NULL,
  `quantidade` int(11) DEFAULT NULL,
  `cod_fornecedor` int(11) DEFAULT NULL,
  PRIMARY KEY (`codigo`)
) ENGINE=InnoDB AUTO_INCREMENT=7 DEFAULT CHARSET=latin1;

/*Data for the table `produtos` */

insert  into `produtos`(`codigo`,`nome`,`descricao`,`preco`,`quantidade`,`cod_fornecedor`) values (1,'Caneta esferográfica','azul','1',10,3),(2,'Lapiseira','preta','2',100,3),(3,'Camiseta manga curta','branca','10',100,1),(4,'Chamequinho','branco','20',100,2),(5,'Camiseta manga longa','branca','30',100,1),(6,'Mochila','Pequena','50',100,2);

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;
