/* 删除BookDB1数据库及用户 */
use mysql;
drop database BookDB1;

/*创建数据库（BookDB1）*/
CREATE DATABASE BookDB1;

/*转到（BookDB1）数据库*/
use BookDB1;

/* 修改基本表约束 */
alter table api_borrow add constraint CKtime check(borrowdate<=shoulddate);

/* 创建视图 */
-- 借阅未还视图
create view ViewBorrownotReturn
as
select readerno_id as readerno,bookno_id as bookno,borrowdate,shoulddate,returndate from api_borrow where returndate is null;

-- 读者借阅视图
create view ViewBorrow
as
select api_reader.readerno,readername,api_book.bookno,bookname,author,press,borrowdate,shoulddate,returndate from api_borrow,api_book,api_reader where api_borrow.bookno_id=api_book.bookno and api_borrow.readerno_id=api_reader.readerno;

-- 读者图书视图
create view ViewBook
as
select api_book.bookno,bookname,author,press,publishdate,shopnum,shopnum-count(ViewBorrownotReturn.bookno) curnum from ViewBorrownotReturn
join api_book on ViewBorrownotReturn.bookno=api_book.bookno
join api_reader on ViewBorrownotReturn.readerno=api_reader.readerno
group by api_book.bookno,bookname,author,press,publishdate,shopNum;

-- 管理员读者视图
create view ViewReaderAdmin
as
select api_reader.readerno,readername,sex,identitycard,workunit,count(api_borrow.readerno_id) totalborrownum,count(api_borrow.readerno_id)-count(api_borrow.returndate) notreturnnum from api_borrow
join api_reader on api_borrow.readerno_id=api_reader.readerno
join api_book on api_borrow.bookno_id=api_book.bookno
group by api_reader.readerno,api_borrow.readerno_id,readername,sex,identitycard,workUnit;

-- 管理员图书视图
create view ViewBookAdmin
as
select api_book.bookno,bookname,author,press,price,publishdate,shopNum,shopNum-count(ViewBorrownotReturn.bookno) curnum from ViewBorrownotReturn
join api_book on ViewBorrownotReturn.bookno=api_book.bookno
join api_reader on ViewBorrownotReturn.readerno=api_reader.readerno
group by api_book.bookno,bookname,author,press,publishdate,shopNum,price;

INSERT INTO "auth_user"("id", "password", "last_login", "is_superuser", "username", "last_name", "email", "is_staff", "is_active", "date_joined", "first_name") VALUES (11, 'pbkdf2_sha256$216000$MXocpIRpwufs$0HZmwU4r8CZEiEJMUg73KLH9JstVJuVH7eMFPOIsR1w=', '2021-04-01 13:14:29.654141', 1, 'admin', '', '', 1, 1, '2021-04-01 12:48:02.176920', '');
INSERT INTO "auth_user"("id", "password", "last_login", "is_superuser", "username", "last_name", "email", "is_staff", "is_active", "date_joined", "first_name") VALUES (1, 'pbkdf2_sha256$216000$MXocpIRpwufs$0HZmwU4r8CZEiEJMUg73KLH9JstVJuVH7eMFPOIsR1w=', '2021-04-01 13:13:26.154812', 0, 'R2005001', '', '', 0, 1, '2021-04-01 12:59:10.638216', '');
INSERT INTO "auth_user"("id", "password", "last_login", "is_superuser", "username", "last_name", "email", "is_staff", "is_active", "date_joined", "first_name") VALUES (2, 'pbkdf2_sha256$216000$MXocpIRpwufs$0HZmwU4r8CZEiEJMUg73KLH9JstVJuVH7eMFPOIsR1w=', '2021-04-01 13:11:14.846303', 0, 'R2006001', '', '', 0, 1, '2021-04-01 13:01:19.961919', '');
INSERT INTO "auth_user"("id", "password", "last_login", "is_superuser", "username", "last_name", "email", "is_staff", "is_active", "date_joined", "first_name") VALUES (3, 'pbkdf2_sha256$216000$MXocpIRpwufs$0HZmwU4r8CZEiEJMUg73KLH9JstVJuVH7eMFPOIsR1w=', '2021-04-01 13:11:14.846303', 0, 'R2007001', '', '', 0, 1, '2021-04-01 13:01:19.961919', '');
INSERT INTO "auth_user"("id", "password", "last_login", "is_superuser", "username", "last_name", "email", "is_staff", "is_active", "date_joined", "first_name") VALUES (4, 'pbkdf2_sha256$216000$MXocpIRpwufs$0HZmwU4r8CZEiEJMUg73KLH9JstVJuVH7eMFPOIsR1w=', '2021-04-01 13:11:14.846303', 0, 'R2008001', '', '', 0, 1, '2021-04-01 13:01:19.961919', '');
INSERT INTO "auth_user"("id", "password", "last_login", "is_superuser", "username", "last_name", "email", "is_staff", "is_active", "date_joined", "first_name") VALUES (5, 'pbkdf2_sha256$216000$MXocpIRpwufs$0HZmwU4r8CZEiEJMUg73KLH9JstVJuVH7eMFPOIsR1w=', '2021-04-01 13:11:14.846303', 0, 'R2009001', '', '', 0, 1, '2021-04-01 13:01:19.961919', '');
INSERT INTO "auth_user"("id", "password", "last_login", "is_superuser", "username", "last_name", "email", "is_staff", "is_active", "date_joined", "first_name") VALUES (6, 'pbkdf2_sha256$216000$MXocpIRpwufs$0HZmwU4r8CZEiEJMUg73KLH9JstVJuVH7eMFPOIsR1w=', '2021-04-01 13:11:14.846303', 0, 'R2005002', '', '', 0, 1, '2021-04-01 13:01:19.961919', '');
INSERT INTO "auth_user"("id", "password", "last_login", "is_superuser", "username", "last_name", "email", "is_staff", "is_active", "date_joined", "first_name") VALUES (7, 'pbkdf2_sha256$216000$MXocpIRpwufs$0HZmwU4r8CZEiEJMUg73KLH9JstVJuVH7eMFPOIsR1w=', '2021-04-01 13:11:14.846303', 0, 'R2006002', '', '', 0, 1, '2021-04-01 13:01:19.961919', '');
INSERT INTO "auth_user"("id", "password", "last_login", "is_superuser", "username", "last_name", "email", "is_staff", "is_active", "date_joined", "first_name") VALUES (8, 'pbkdf2_sha256$216000$MXocpIRpwufs$0HZmwU4r8CZEiEJMUg73KLH9JstVJuVH7eMFPOIsR1w=', '2021-04-01 13:11:14.846303', 0, 'R2007002', '', '', 0, 1, '2021-04-01 13:01:19.961919', '');
INSERT INTO "auth_user"("id", "password", "last_login", "is_superuser", "username", "last_name", "email", "is_staff", "is_active", "date_joined", "first_name") VALUES (9, 'pbkdf2_sha256$216000$MXocpIRpwufs$0HZmwU4r8CZEiEJMUg73KLH9JstVJuVH7eMFPOIsR1w=', '2021-04-01 13:11:14.846303', 0, 'R2008002', '', '', 0, 1, '2021-04-01 13:01:19.961919', '');
INSERT INTO "auth_user"("id", "password", "last_login", "is_superuser", "username", "last_name", "email", "is_staff", "is_active", "date_joined", "first_name") VALUES (10, 'pbkdf2_sha256$216000$MXocpIRpwufs$0HZmwU4r8CZEiEJMUg73KLH9JstVJuVH7eMFPOIsR1w=', '2021-04-01 13:11:14.846303', 0, 'R2009002', '', '', 0, 1, '2021-04-01 13:01:19.961919', '');

/*读者表（api_reader）数据：*/
INSERT INTO api_reader VALUES('R2005001','张小娟','女','412723199001014321','统一股份有限公司');
INSERT INTO api_reader VALUES('R2006001','刘凤','女','412723199003014321','联合股份有限公司');
INSERT INTO api_reader VALUES('R2007001','高代鹏','男','412723199005014321','洪都股份有限公司');
INSERT INTO api_reader VALUES('R2008001','陈辉','男','412723199111014321','南昌市电脑研制公司');
INSERT INTO api_reader VALUES('R2009001','李虹冰','女','412723199208014321','富士康科技集团');
INSERT INTO api_reader VALUES('R2005002','张露','女','412723199002014321','兴隆股份有限公司');
INSERT INTO api_reader VALUES('R2006002','喻自强','男','412723199004014321','万事达股份有限公司');
INSERT INTO api_reader VALUES('R2007002','张晓梅','女','412723199112014321','世界技术开发公司');
INSERT INTO api_reader VALUES('R2008002','张良','男','412723199110014321','上海生物研究室');
INSERT INTO api_reader VALUES('R2009002','韩福平','男','412723199209014321','合生元有限公司');

/*图书表(api_book)数据：*/
INSERT INTO api_book VALUES('B200101001','政治经济学','宋涛','中国人民大学出版社',31.80,'1991-01-01',5);
INSERT INTO api_book VALUES('B200201001','大学英语','郑树棠','外语教学与研究出版社',35.20,'1992-01-01',3);
INSERT INTO api_book VALUES('B200301001','数据库系统原理','吴京慧','清华大学出版社',58.20,'1993-01-01',3);
INSERT INTO api_book VALUES('B200101002','微观经济学','张蕊','高等教育出版社',41.80,'1991-01-02',2);
INSERT INTO api_book VALUES('B200101003','宏观经济学','袁明圣','中国财经经济出版社',51.80,'1991-01-03',2);
INSERT INTO api_book VALUES('B200201002','商务英语','马升烨','上海外语学院出版社',45.20,'1992-01-02',5);
INSERT INTO api_book VALUES('B200201003','商务英语2','江宇佳','西安交通大学出版社',55.20,'1992-01-03',3);
INSERT INTO api_book VALUES('B200301002','组网技术','万征','浙江大学出版社',38.20,'1993-01-02',1);
INSERT INTO api_book VALUES('B200301003','人工智能','费翔林','电子工业出版社',43.20,'1993-01-03',5);
INSERT INTO api_book VALUES('B200301004','算法设计与分析','陈慧南','科学出版社',58.20,'1993-01-04',10);

/*借阅表（api_borrow）数据：*/
INSERT INTO api_borrow("readerno_id", "bookno_id","borrowdate", "shoulddate", "returndate") VALUES('R2005001','B200101001','2011-09-01','2011-10-01',null);
INSERT INTO api_borrow("readerno_id", "bookno_id","borrowdate", "shoulddate", "returndate") VALUES('R2006001','B200101001','2011-09-07','2011-10-07','2011-10-05');
INSERT INTO api_borrow("readerno_id", "bookno_id","borrowdate", "shoulddate", "returndate") VALUES('R2007001','B200201001','2011-09-13','2011-10-13','2011-10-10');
INSERT INTO api_borrow("readerno_id", "bookno_id","borrowdate", "shoulddate", "returndate") VALUES('R2008001','B200301001','2011-09-15','2011-10-15','2011-10-13');
INSERT INTO api_borrow("readerno_id", "bookno_id","borrowdate", "shoulddate", "returndate") VALUES('R2009001','B200301001','2011-09-18','2011-10-18',null);
INSERT INTO api_borrow("readerno_id", "bookno_id","borrowdate", "shoulddate", "returndate") VALUES('R2005001','B200101002','2011-09-02','2011-10-02',null);
INSERT INTO api_borrow("readerno_id", "bookno_id","borrowdate", "shoulddate", "returndate") VALUES('R2005001','B200101003','2011-09-03','2011-10-03',null);
INSERT INTO api_borrow("readerno_id", "bookno_id","borrowdate", "shoulddate", "returndate") VALUES('R2005002','B200101001','2011-09-04','2011-10-04','2011-10-03');
INSERT INTO api_borrow("readerno_id", "bookno_id","borrowdate", "shoulddate", "returndate") VALUES('R2005002','B200101002','2011-09-05','2011-10-05',null);
INSERT INTO api_borrow("readerno_id", "bookno_id","borrowdate", "shoulddate", "returndate") VALUES('R2005002','B200101003','2011-09-06','2011-10-06','2011-10-08');
INSERT INTO api_borrow("readerno_id", "bookno_id","borrowdate", "shoulddate", "returndate") VALUES('R2006001','B200101002','2011-09-08','2011-10-08','2011-10-06');
INSERT INTO api_borrow("readerno_id", "bookno_id","borrowdate", "shoulddate", "returndate") VALUES('R2006001','B200101003','2011-09-09','2011-10-09',null);
INSERT INTO api_borrow("readerno_id", "bookno_id","borrowdate", "shoulddate", "returndate") VALUES('R2009002','B200201001','2011-09-10','2011-10-10','2011-10-08');
INSERT INTO api_borrow("readerno_id", "bookno_id","borrowdate", "shoulddate", "returndate") VALUES('R2006002','B200201002','2011-09-11','2011-10-11','2011-10-08');
INSERT INTO api_borrow("readerno_id", "bookno_id","borrowdate", "shoulddate", "returndate") VALUES('R2006002','B200201003','2011-09-12','2011-10-12','2011-10-08');
INSERT INTO api_borrow("readerno_id", "bookno_id","borrowdate", "shoulddate", "returndate") VALUES('R2007001','B200201002','2011-09-14','2011-10-14',null);
INSERT INTO api_borrow("readerno_id", "bookno_id","borrowdate", "shoulddate", "returndate") VALUES('R2007001','B200201003','2011-09-15','2011-10-15','2011-10-10');
INSERT INTO api_borrow("readerno_id", "bookno_id","borrowdate", "shoulddate", "returndate") VALUES('R2009002','B200201001','2011-09-16','2011-10-16','2011-10-14');
INSERT INTO api_borrow("readerno_id", "bookno_id","borrowdate", "shoulddate", "returndate") VALUES('R2007002','B200201002','2011-09-17','2011-10-17','2011-10-14');
INSERT INTO api_borrow("readerno_id", "bookno_id","borrowdate", "shoulddate", "returndate") VALUES('R2007002','B200201003','2011-09-17','2011-10-17','2011-10-14');



-- drop table ViewBorrow;
-- drop table ViewBook;
--
-- drop view ViewBorrownotReturn;
-- drop view ViewBorrow;
-- drop view ViewBook;