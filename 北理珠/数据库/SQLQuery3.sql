CREATE DATABASE DB3
 CONTAINMENT = NONE
 ON  PRIMARY 
( NAME = 'DB3', FILENAME = 'D:\DB3.mdf' , SIZE = 8192KB , FILEGROWTH = 65536KB )
 LOG ON 
( NAME = 'DB3_log', FILENAME = 'D:\DB3_log.ldf' , SIZE = 8192KB , FILEGROWTH = 65536KB )


use DB3;
CREATE TABLE Student
(
	Sno char(7) primary key,
	Sname char(10),
	Ssex char(2) check(Ssex='男' or Ssex='女'),
	Sage tinyint check(Sage>=15 or Sage<=45),
	Sdept char(20)
)

CREATE TABLE Course
(
	Cno char(10) primary key,
	Cname char(20) NOT NULL,
	Ccredit int check(Ccredit > 0),
	Semster int check(Semster > 0)
)

CREATE TABLE SC
(
	Sno char(7) foreign key(Sno) references Student(Sno),
	Cno char(10) foreign key(Cno) references Course(Cno),
	Grade int check(Grade >= 0 and Grade <= 100),
	XKLB char(4) NULL,
	CONSTRAINT [PK_SC] PRIMARY KEY CLUSTERED ( Sno,Cno )
)


/*学生信息表（Student）数据：*/
INSERT INTO Student VALUES ('9512101', '李勇', '男', 19, '计算机系')
INSERT INTO Student VALUES ('9512102', '刘晨', '男', 20, '计算机系')
INSERT INTO Student VALUES ('9512103', '王敏', '女', 20, '计算机系')
INSERT INTO Student VALUES ('9521101', '张立', '男', 22, '信息系')
INSERT INTO Student VALUES ('9521102', '吴宾', '女', 21, '信息系')
INSERT INTO Student VALUES ('9521103', '张海', '男', 20, '信息系')
INSERT INTO Student VALUES ('9531101', '钱小平', '女', 18, '数学系')
INSERT INTO Student VALUES ('9531102', '王大力', '男', 19, '数学系')


/*课程信息表（Course）：*/
INSERT INTO Course VALUES ('C01', '计算机文化基础', 3, 1)
INSERT INTO Course VALUES ('C02', 'VB', 2, 3)
INSERT INTO Course VALUES ('C03', '计算机网络', 4, 7)
INSERT INTO Course VALUES ('C04', '数据库基础', 6, 6)
INSERT INTO Course VALUES ('C05', '高等数学', 8, 2)
INSERT INTO Course VALUES ('C06', '数据结构', 5, 4)


/*学生选课信息表（SC）：*/
INSERT INTO SC VALUES ('9512101', 'C01', 90, '必修')
INSERT INTO SC VALUES ('9512101', 'C02', 86, '选修')
INSERT INTO SC VALUES ('9512101', 'C06', 62, '必修')
INSERT INTO SC VALUES ('9512102', 'C02', 78, '选修')
INSERT INTO SC VALUES ('9512102', 'C04', 66, '必修')
INSERT INTO SC VALUES ('9512102', 'C01', 82, '选修')
INSERT INTO SC VALUES ('9512102', 'C05', 92, '必修')
INSERT INTO SC VALUES ('9512102', 'C06', 50, '必修')
INSERT INTO SC VALUES ('9512103', 'C02', 68, '选修')
INSERT INTO SC VALUES ('9512103', 'C06', 62, '必修')
INSERT INTO SC VALUES ('9531101', 'C01', 80, '选修')
INSERT INTO SC VALUES ('9531101', 'C05', 95, '必修')
INSERT INTO SC VALUES ('9531102', 'C05', 85, '必修')

/* 把王敏同学的所在系改为信息系 */
UPDATE Student SET Sdept='信息系' WHERE Sname='王敏';
/* 把数据库基础改名为数据库原理与应用；*/
UPDATE Course SET Cname='数据库原理与应用' WHERE Cname='数据库基础';
/* 删除成绩小于40分的选课信息；*/
DELETE FROM SC WHERE Grade<40;

/* 根据实验2所创建的数据库BookDB中的数据表，完成如下查询：*/
/* 1-5 为连接查询 */
use BookDB;
--select * from Borrow where bookNo='B200101002';
--1.查询借阅了图书编号为'B200101002'图书的读者姓名、借书日期、还书日期；
select readerName 读者姓名,borrowDate 借书日期,returnDate 还书日期 
from Borrow,Reader 
where Borrow.readerNO=Reader.readerNO and bookNo='B200101002';
--2.查询读者张晓梅借阅的图书编号、图书名称、借书日期和归还日期；
select Book.bookNO 图书编号,bookName 图书名称,borrowDate 借书日期,returnDate 归还日期
from Borrow,Reader,Book
where Borrow.readerNO=Reader.readerNO and Book.bookNO = Borrow.bookNO and readerName='张晓梅';
--3.查询'洪都股份有限公司'没有归还所借图书的读者编号、读者姓名、图书名称、借书日期和应归还日期；
select Reader.readerNO 读者编号,readerName 读者姓名,bookName 图书名称,borrowDate 借书日期,shouldDate 应归还日期
from Borrow,Reader,Book
where Borrow.readerNO=Reader.readerNO and Book.bookNO = Borrow.bookNO
and workUnit='洪都股份有限公司' and returnDate is null;
--4.查询借阅了清华大学出版社出版的图书的读者编号、读者姓名、图书名称、借书日期和归还日期；
select reader.readerNO 读者编号,readerName 读者姓名,bookName 图书名称,borrowDate 借书日期,returnDate 归还日期
from Borrow,Reader,Book
where Borrow.readerNO=Reader.readerNO and Book.bookNO = Borrow.bookNO
and publishingName = '清华大学出版社';
--5.查询借书时间在2010-2011年之间的读者编号、读者姓名、图书编号、图书名称；
select reader.readerNO 读者编号,readerName 读者姓名,Book.bookNO 图书编号,bookName 图书名称
from Borrow,Reader,Book
where Borrow.readerNO=Reader.readerNO and Book.bookNO = Borrow.bookNO
and (year(borrowDate) between 2010 and 2011);

/*  使用聚合函数，以及排序；*/
--6.查询每种类别的图书分类号、最高价格和平均价格，并按最高价格的降序输出；
-- select * from Book;
select classNo 图书分类号,max(price) 最高价格,avg(price) 平均价格 
from Book group by classNO order by 最高价格 desc;

--7.查询分类号小于009号每类图书的入库数量；
-- select * from Book;
select classNo,sum(shopNum)
from Book where (classNO < '009') group by classNO;

/* 8开始，使用连接，子查询还有聚合函数；*/
--8.查询所借图书的总价在100元以上的读者编号、读者姓名和所借图书的总价；  
select R.readerNO 读者编号,R.readerName 读者姓名,sum(price) 所借图书总价
from Borrow,Reader R,Book
where Borrow.readerNO=R.readerNO and Book.bookNO = Borrow.bookNO group by R.readerNO,R.readerName
having sum(price)>100;

--9.查询没有借书的读者姓名和工作单位(使用IN子查询表达)；
--select distinct readerNO from Borrow;
--select readerNO from Reader;
select readerName 读者姓名,workUnit 工作单位 from Reader
where readerNo not in
(
	select readerNO from Borrow
);

--10.查询没有借阅图书编号以'B2001'开头的图书的读者编号、姓名以及他们所借阅图书的图书名称、借书日期（使用IN子查询表达）。
select BW.readerNO 读者编号,readerName 姓名,bookName 图书名称,borrowDate 借书日期 
from Borrow BW,Reader R,Book BK
where BW.readerNo not in
(
	select readerNO from Borrow where bookNo like 'B2001%'
) and BW.readerNO=R.readerNO and BK.bookNO = BW.bookNO;

/*--11开始使用集合运算，*/
--11.查询既借阅了"商务英语"图书又借阅了"大学英语"两本图书的读者编号、读者姓名、借书日期和图书名称；
select BW.readerNo 读者编号,readername 读者姓名,borrowDate 借书日期,bookName 图书名称
from Borrow BW,Reader R,Book BK
where BW.readerNO=R.readerNO and BK.bookNO = BW.bookNO
and /*(bookName = '商务英语' or bookName = '大学英语') and */BW.readerNO in (
	select BW.readerNo
	from Borrow BW,Reader R,Book BK
	where BW.readerNO=R.readerNO and BK.bookNO = BW.bookNO and bookName = '商务英语'
	INTERSECT
	select BW.readerNo
	from Borrow BW,Reader R,Book BK
	where BW.readerNO=R.readerNO and BK.bookNO = BW.bookNO and bookName = '大学英语'
);

--12.查询没有借阅"经济类"图书的读者编号、读者姓名（使用IN子查询表达）；
select distinct Borrow.readerNO 读者编号,readerName 读者姓名
from Borrow,Reader,Book
where Borrow.readerNO=Reader.readerNO and Book.bookNO = Borrow.bookNO
and classNO not in
(
	select Book.classNO
	from Borrow,Reader,Book,BookClass
	where Borrow.readerNO=Reader.readerNO and Book.bookNO = Borrow.bookNO and bookclass.classNO  = Book.classNO
	and className = '经济类'
);

--13.查询至少与读者"张晓梅"所借的图书一样的读者编号、读者姓名和工作单位；
select distinct Borrow.readerNO 读者编号,readerName 读者姓名,workUnit 工作单位
from Borrow,Reader,Book
where Borrow.readerNO=Reader.readerNO and Book.bookNO = Borrow.bookNO
and bookName in (
	select bookName
	from Borrow,Reader,Book
	where Borrow.readerNO=Reader.readerNO and Book.bookNO = Borrow.bookNO
	and readername = '张晓梅'
) and readername != '张晓梅';

--14.查询借阅了图书类别为002号的所有图书的读者编号、读者姓名以及他们所借阅过的所有图书的图书名称和借阅日期；
select Reader.readerNO 读者编号,readerName 读者姓名,bookName 图书名称,borrowDate 借阅日期
from Borrow,Reader,Book,BookClass
where Borrow.readerNO=Reader.readerNO and Book.bookNO = Borrow.bookNO and Book.classNO=BookClass.classNO
and Reader.readerNO in (
	select distinct Reader.readerNo
	from Borrow,Reader,Book,BookClass
	where Borrow.readerNO=Reader.readerNO and Book.bookNO = Borrow.bookNO and Book.classNO=BookClass.classNO
	and BookClass.classNo = '002'
);

/*--15开始，是分组和组过滤，以及排序输出；*/  
--15.查询至少借阅了3本图书的读者编号、读者姓名、图书编号、图书名称，按读者编号排序输出；
select Reader.readerNO 读者编号,readerName 读者姓名,book.bookNO 图书编号,bookname 图书名称
from Borrow,Reader,Book
where Borrow.readerNO=Reader.readerNO and Book.bookNO = Borrow.bookNO
and Reader.readerNO in(
	select Reader.readerNO
	from Borrow,Reader,Book
	where Borrow.readerNO=Reader.readerNO and Book.bookNO = Borrow.bookNO
	group by Reader.readerNO
	having count(Reader.readerNO)>=3
)
order by 读者编号;

--16.查询所借阅的图书总价最高的读者编号、读者姓名和出生日期；
select Reader.readerNO 读者编号,readerName 读者姓名,substring(identitycard,7,8) 出生日期
from Borrow,Reader,Book,BookClass
where Borrow.readerNO=Reader.readerNO and Book.bookNO = Borrow.bookNO and Book.classNO=BookClass.classNO
and price in
(
	select max(price) from Borrow,Book where Book.bookNO = Borrow.bookNO
);

--17.将"经济类"图书的单价提高10%；
/*
select * from book where classNO in (
	select classNO from BookClass where className='经济类'
)
*/
update book set price = price*1.1 where classNO in (
	select classNO from BookClass where className='经济类'
)
/*
select * from book where classNO in (
	select classNO from BookClass where className='经济类'
)
*/

--18.对于年龄在25-35岁之间的读者所借阅的应归还还未归还的图书,将其归还日期修改为系统当天日期;
/*
select borrow.readerNO,borrow.bookNO
from Borrow,Reader,Book,BookClass
where Borrow.readerNO=Reader.readerNO and Book.bookNO = Borrow.bookNO and Book.classNO=BookClass.classNO
and returnDate is null and ((year(GETDATE()) - cast(SUBSTRING(identitycard,7,4) as int)) between 25 and 35);

select * from Borrow tableA where exists(
	select borrow.readerNO,borrow.bookNO
	from Borrow,Reader,Book,BookClass
	where Borrow.readerNO=Reader.readerNO and Book.bookNO = Borrow.bookNO and Book.classNO=BookClass.classNO
	and /*returnDate is null and*/ ((year(GETDATE()) - cast(SUBSTRING(identitycard,7,4) as int)) between 25 and 35)
	and tableA.readerNO = borrow.readerNO and tableA.bookNO = borrow.bookNO
)
*/
update borrow set returnDate=getdate() from borrow tableA where exists(
	select borrow.readerNO,borrow.bookNO
	from Borrow,Reader,Book,BookClass
	where Borrow.readerNO=Reader.readerNO and Book.bookNO = Borrow.bookNO and Book.classNO=BookClass.classNO
	and returnDate is null and ((year(GETDATE()) - cast(SUBSTRING(identitycard,7,4) as int)) between 25 and 35)
	and tableA.readerNO = borrow.readerNO and tableA.bookNO = borrow.bookNO
)
/*
select *
from Borrow,Reader,Book,BookClass
where Borrow.readerNO=Reader.readerNO and Book.bookNO = Borrow.bookNO and Book.classNO=BookClass.classNO
*/