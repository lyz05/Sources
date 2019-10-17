CREATE DATABASE [BookDB]
 CONTAINMENT = NONE
 ON  PRIMARY 
( NAME = N'BookDB', FILENAME = N'D:\SQ\BookDB.mdf' , SIZE = 8192KB , MAXSIZE = 30720KB , FILEGROWTH = 1024KB )
 LOG ON 
( NAME = N'BookLog', FILENAME = N'D:\SQ\BookLog.ldf' , SIZE = 5120KB , MAXSIZE = 20480KB , FILEGROWTH = 1024KB )

use BookDB;

CREATE TABLE BookClass
(
	classNO char(3) NOT NULL primary key,
	className char(20) NOT NULL 
)

CREATE TABLE Book
(
	bookNO char(10) primary key,
	classNO char(3) foreign key(classNO) references BookClass(classNo),
	bookName char(40),
	authorName char(8),
	publishingName char(20),
	publishingNO char(17),
	price decimal(7,2),
	publishingDate datetime,
	shopDate datetime,
	shopNum int
)

CREATE TABLE Reader
(
	readerNO char(8) primary key,
	readerName char(8),
	sex char(2),
	identitycard char(18),
	workUnit char(50),
	borrowCount tinyint
)

CREATE TABLE Borrow
(
	readerNO char(8) foreign key(readerNO) references Reader(readerNO),
	bookNO char(10) foreign key(bookNO) references Book(bookNO),
	borrowDate datetime,
	shouldDate datetime,
	returnDate datetime
)


/*图书分类表（BookClass）数据：*/
INSERT INTO BookClass VALUES('001','经济类');
INSERT INTO BookClass VALUES('002','外语类');
INSERT INTO BookClass VALUES('003','计算机类');

/*图书表(Book)数据：*/
INSERT INTO Book VALUES('B200101001','001','政治经济学','宋涛','中国人民大学出版社','P1991010100010001',31.80,'19910101','19950111',100);
INSERT INTO Book VALUES('B200201001','002','大学英语','郑树棠','外语教学与研究出版社','P1992010100010001',35.20,'19920101','19960111',130);
INSERT INTO Book VALUES('B200301001','003','数据库系统原理','吴京慧','清华大学出版社','P1993010100010001',58.20,'19930101','19950111',160);
INSERT INTO Book VALUES('B200101002','001','微观经济学','张蕊','高等教育出版社','P1991010100010002',41.80,'19910102','19950112',110);
INSERT INTO Book VALUES('B200101003','001','宏观经济学','袁明圣','中国财经经济出版社','P1991010100010003',51.80,'19910103','19950113',120);
INSERT INTO Book VALUES('B200201002','002','商务英语','马升烨','上海外语学院出版社','P1992010100010002',45.20,'19920102','19960112',140);
INSERT INTO Book VALUES('B200201003','002','商务英语2','江宇佳','西安交通大学出版社','P1992010100010003',55.20,'19920103','19960113',150);
INSERT INTO Book VALUES('B200301002','003','组网技术','万征','浙江大学出版社','P1993010100010002',38.20,'19930102','19950112',170);
INSERT INTO Book VALUES('B200301003','003','人工智能','费翔林','电子工业出版社','P1993010100010003',43.20,'19930103','19950113',180);
INSERT INTO Book VALUES('B200301004','003','算法设计与分析','陈慧南','科学出版社','P1993010100010004',58.20,'19930104','19950114',190);


/*读者表（Reader）数据：*/
insert Reader values('R2005001','张小娟','F','412723199001014321','统一股份有限公司',0)
insert Reader values('R2006001','刘凤','F','412723199003014321','联合股份有限公司',0)
insert Reader values('R2007001','高代鹏','M','412723199005014321','洪都股份有限公司',0)
insert Reader values('R2008001','陈辉','M','412723199111014321','南昌市电脑研制公司',0)
insert Reader values('R2009001','李虹冰','F','412723199208014321','富士康科技集团',0)
insert Reader values('R2005002','张露','F','412723199002014321','兴隆股份有限公司',0)
insert Reader values('R2006002','喻自强','M','412723199004014321','万事达股份有限公司',0)
insert Reader values('R2007002','张晓梅','F','412723199112014321','世界技术开发公司',0)
insert Reader values('R2008002','张良','M','412723199110014321','上海生物研究室',0)
insert Reader values('R2009002','韩福平','M','412723199209014321','合生元有限公司',0)

/*借阅表（Borrow）数据：*/
insert Borrow values('R2005001','B200101001','20110901','20111001',null)
insert Borrow values('R2006001','B200101001','20110907','20111007','20111005')
insert Borrow values('R2007001','B200201001','20110913','20111013','20111010')
insert Borrow values('R2008001','B200301001','20110915','20111015','20111013')
insert Borrow values('R2009001','B200301001','20110918','20111018',null)
insert Borrow values('R2005001','B200101002','20110902','20111002','20111001')
insert Borrow values('R2005001','B200101003','20110903','20111003',null)
insert Borrow values('R2005002','B200101001','20110904','20111004','20111003')
insert Borrow values('R2005002','B200101002','20110905','20111005',null)
insert Borrow values('R2005002','B200101003','20110906','20111006','20111008')
insert Borrow values('R2006001','B200101002','20110908','20111008','20111006')
insert Borrow values('R2006001','B200101003','20110909','20111009','20111012')
insert Borrow values('R2009002','B200201001','20110910','20111010','20111008')
insert Borrow values('R2006002','B200201002','20110911','20111011','20111008')
insert Borrow values('R2006002','B200201003','20110912','20111012','20111008')
insert Borrow values('R2007001','B200201002','20110914','20111014',null)
insert Borrow values('R2007001','B200201003','20110915','20111015','20111010')
insert Borrow values('R2009002','B200201001','20110916','20111016','20111014')
insert Borrow values('R2007002','B200201002','20110917','20111017','20111014')
insert Borrow values('R2007002','B200201003','20110917','20111017','20111014')

/*查询操作*/
select * from Reader;
select readerName,workUnit,identitycard from Reader where identitycard like '______1991________';
select readerNO,readerName,sex from Reader where workUnit = '富士康科技集团';
select * from Book;
select * from Book where bookName like '%数据库%';
select * from Book where authorName = '袁明圣';