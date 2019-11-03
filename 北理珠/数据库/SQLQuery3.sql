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
	Ssex char(2) check(Ssex='��' or Ssex='Ů'),
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


/*ѧ����Ϣ��Student�����ݣ�*/
INSERT INTO Student VALUES ('9512101', '����', '��', 19, '�����ϵ')
INSERT INTO Student VALUES ('9512102', '����', '��', 20, '�����ϵ')
INSERT INTO Student VALUES ('9512103', '����', 'Ů', 20, '�����ϵ')
INSERT INTO Student VALUES ('9521101', '����', '��', 22, '��Ϣϵ')
INSERT INTO Student VALUES ('9521102', '���', 'Ů', 21, '��Ϣϵ')
INSERT INTO Student VALUES ('9521103', '�ź�', '��', 20, '��Ϣϵ')
INSERT INTO Student VALUES ('9531101', 'ǮСƽ', 'Ů', 18, '��ѧϵ')
INSERT INTO Student VALUES ('9531102', '������', '��', 19, '��ѧϵ')


/*�γ���Ϣ��Course����*/
INSERT INTO Course VALUES ('C01', '������Ļ�����', 3, 1)
INSERT INTO Course VALUES ('C02', 'VB', 2, 3)
INSERT INTO Course VALUES ('C03', '���������', 4, 7)
INSERT INTO Course VALUES ('C04', '���ݿ����', 6, 6)
INSERT INTO Course VALUES ('C05', '�ߵ���ѧ', 8, 2)
INSERT INTO Course VALUES ('C06', '���ݽṹ', 5, 4)


/*ѧ��ѡ����Ϣ��SC����*/
INSERT INTO SC VALUES ('9512101', 'C01', 90, '����')
INSERT INTO SC VALUES ('9512101', 'C02', 86, 'ѡ��')
INSERT INTO SC VALUES ('9512101', 'C06', 62, '����')
INSERT INTO SC VALUES ('9512102', 'C02', 78, 'ѡ��')
INSERT INTO SC VALUES ('9512102', 'C04', 66, '����')
INSERT INTO SC VALUES ('9512102', 'C01', 82, 'ѡ��')
INSERT INTO SC VALUES ('9512102', 'C05', 92, '����')
INSERT INTO SC VALUES ('9512102', 'C06', 50, '����')
INSERT INTO SC VALUES ('9512103', 'C02', 68, 'ѡ��')
INSERT INTO SC VALUES ('9512103', 'C06', 62, '����')
INSERT INTO SC VALUES ('9531101', 'C01', 80, 'ѡ��')
INSERT INTO SC VALUES ('9531101', 'C05', 95, '����')
INSERT INTO SC VALUES ('9531102', 'C05', 85, '����')

/* ������ͬѧ������ϵ��Ϊ��Ϣϵ */
UPDATE Student SET Sdept='��Ϣϵ' WHERE Sname='����';
/* �����ݿ��������Ϊ���ݿ�ԭ����Ӧ�ã�*/
UPDATE Course SET Cname='���ݿ�ԭ����Ӧ��' WHERE Cname='���ݿ����';
/* ɾ���ɼ�С��40�ֵ�ѡ����Ϣ��*/
DELETE FROM SC WHERE Grade<40;

/* ����ʵ��2�����������ݿ�BookDB�е����ݱ�������²�ѯ��*/
/* 1-5 Ϊ���Ӳ�ѯ */
use BookDB;
--select * from Borrow where bookNo='B200101002';
--1.��ѯ������ͼ����Ϊ'B200101002'ͼ��Ķ����������������ڡ��������ڣ�
select readerName ��������,borrowDate ��������,returnDate �������� 
from Borrow,Reader 
where Borrow.readerNO=Reader.readerNO and bookNo='B200101002';
--2.��ѯ��������÷���ĵ�ͼ���š�ͼ�����ơ��������ں͹黹���ڣ�
select Book.bookNO ͼ����,bookName ͼ������,borrowDate ��������,returnDate �黹����
from Borrow,Reader,Book
where Borrow.readerNO=Reader.readerNO and Book.bookNO = Borrow.bookNO and readerName='����÷';
--3.��ѯ'�鶼�ɷ����޹�˾'û�й黹����ͼ��Ķ��߱�š�����������ͼ�����ơ��������ں�Ӧ�黹���ڣ�
select Reader.readerNO ���߱��,readerName ��������,bookName ͼ������,borrowDate ��������,shouldDate Ӧ�黹����
from Borrow,Reader,Book
where Borrow.readerNO=Reader.readerNO and Book.bookNO = Borrow.bookNO
and workUnit='�鶼�ɷ����޹�˾' and returnDate is null;
--4.��ѯ�������廪��ѧ����������ͼ��Ķ��߱�š�����������ͼ�����ơ��������ں͹黹���ڣ�
select reader.readerNO ���߱��,readerName ��������,bookName ͼ������,borrowDate ��������,returnDate �黹����
from Borrow,Reader,Book
where Borrow.readerNO=Reader.readerNO and Book.bookNO = Borrow.bookNO
and publishingName = '�廪��ѧ������';
--5.��ѯ����ʱ����2010-2011��֮��Ķ��߱�š�����������ͼ���š�ͼ�����ƣ�
select reader.readerNO ���߱��,readerName ��������,Book.bookNO ͼ����,bookName ͼ������
from Borrow,Reader,Book
where Borrow.readerNO=Reader.readerNO and Book.bookNO = Borrow.bookNO
and (year(borrowDate) between 2010 and 2011);

/*  ʹ�þۺϺ������Լ�����*/
--6.��ѯÿ������ͼ�����š���߼۸��ƽ���۸񣬲�����߼۸�Ľ��������
-- select * from Book;
select classNo ͼ������,max(price) ��߼۸�,avg(price) ƽ���۸� 
from Book group by classNO order by ��߼۸� desc;

--7.��ѯ�����С��009��ÿ��ͼ������������
-- select * from Book;
select classNo,sum(shopNum)
from Book where (classNO < '009') group by classNO;

/* 8��ʼ��ʹ�����ӣ��Ӳ�ѯ���оۺϺ�����*/
--8.��ѯ����ͼ����ܼ���100Ԫ���ϵĶ��߱�š���������������ͼ����ܼۣ�  
select R.readerNO ���߱��,R.readerName ��������,sum(price) ����ͼ���ܼ�
from Borrow,Reader R,Book
where Borrow.readerNO=R.readerNO and Book.bookNO = Borrow.bookNO group by R.readerNO,R.readerName
having sum(price)>100;

--9.��ѯû�н���Ķ��������͹�����λ(ʹ��IN�Ӳ�ѯ���)��
--select distinct readerNO from Borrow;
--select readerNO from Reader;
select readerName ��������,workUnit ������λ from Reader
where readerNo not in
(
	select readerNO from Borrow
);

--10.��ѯû�н���ͼ������'B2001'��ͷ��ͼ��Ķ��߱�š������Լ�����������ͼ���ͼ�����ơ��������ڣ�ʹ��IN�Ӳ�ѯ����
select BW.readerNO ���߱��,readerName ����,bookName ͼ������,borrowDate �������� 
from Borrow BW,Reader R,Book BK
where BW.readerNo not in
(
	select readerNO from Borrow where bookNo like 'B2001%'
) and BW.readerNO=R.readerNO and BK.bookNO = BW.bookNO;

/*--11��ʼʹ�ü������㣬*/
--11.��ѯ�Ƚ�����"����Ӣ��"ͼ���ֽ�����"��ѧӢ��"����ͼ��Ķ��߱�š������������������ں�ͼ�����ƣ�
select BW.readerNo ���߱��,readername ��������,borrowDate ��������,bookName ͼ������
from Borrow BW,Reader R,Book BK
where BW.readerNO=R.readerNO and BK.bookNO = BW.bookNO
and /*(bookName = '����Ӣ��' or bookName = '��ѧӢ��') and */BW.readerNO in (
	select BW.readerNo
	from Borrow BW,Reader R,Book BK
	where BW.readerNO=R.readerNO and BK.bookNO = BW.bookNO and bookName = '����Ӣ��'
	INTERSECT
	select BW.readerNo
	from Borrow BW,Reader R,Book BK
	where BW.readerNO=R.readerNO and BK.bookNO = BW.bookNO and bookName = '��ѧӢ��'
);

--12.��ѯû�н���"������"ͼ��Ķ��߱�š�����������ʹ��IN�Ӳ�ѯ����
select distinct Borrow.readerNO ���߱��,readerName ��������
from Borrow,Reader,Book
where Borrow.readerNO=Reader.readerNO and Book.bookNO = Borrow.bookNO
and classNO not in
(
	select Book.classNO
	from Borrow,Reader,Book,BookClass
	where Borrow.readerNO=Reader.readerNO and Book.bookNO = Borrow.bookNO and bookclass.classNO  = Book.classNO
	and className = '������'
);

--13.��ѯ���������"����÷"�����ͼ��һ���Ķ��߱�š����������͹�����λ��
select distinct Borrow.readerNO ���߱��,readerName ��������,workUnit ������λ
from Borrow,Reader,Book
where Borrow.readerNO=Reader.readerNO and Book.bookNO = Borrow.bookNO
and bookName in (
	select bookName
	from Borrow,Reader,Book
	where Borrow.readerNO=Reader.readerNO and Book.bookNO = Borrow.bookNO
	and readername = '����÷'
) and readername != '����÷';

--14.��ѯ������ͼ�����Ϊ002�ŵ�����ͼ��Ķ��߱�š����������Լ����������Ĺ�������ͼ���ͼ�����ƺͽ������ڣ�
select Reader.readerNO ���߱��,readerName ��������,bookName ͼ������,borrowDate ��������
from Borrow,Reader,Book,BookClass
where Borrow.readerNO=Reader.readerNO and Book.bookNO = Borrow.bookNO and Book.classNO=BookClass.classNO
and Reader.readerNO in (
	select distinct Reader.readerNo
	from Borrow,Reader,Book,BookClass
	where Borrow.readerNO=Reader.readerNO and Book.bookNO = Borrow.bookNO and Book.classNO=BookClass.classNO
	and BookClass.classNo = '002'
);

/*--15��ʼ���Ƿ��������ˣ��Լ����������*/  
--15.��ѯ���ٽ�����3��ͼ��Ķ��߱�š�����������ͼ���š�ͼ�����ƣ������߱�����������
select Reader.readerNO ���߱��,readerName ��������,book.bookNO ͼ����,bookname ͼ������
from Borrow,Reader,Book
where Borrow.readerNO=Reader.readerNO and Book.bookNO = Borrow.bookNO
and Reader.readerNO in(
	select Reader.readerNO
	from Borrow,Reader,Book
	where Borrow.readerNO=Reader.readerNO and Book.bookNO = Borrow.bookNO
	group by Reader.readerNO
	having count(Reader.readerNO)>=3
)
order by ���߱��;

--16.��ѯ�����ĵ�ͼ���ܼ���ߵĶ��߱�š����������ͳ������ڣ�
select Reader.readerNO ���߱��,readerName ��������,substring(identitycard,7,8) ��������
from Borrow,Reader,Book,BookClass
where Borrow.readerNO=Reader.readerNO and Book.bookNO = Borrow.bookNO and Book.classNO=BookClass.classNO
and price in
(
	select max(price) from Borrow,Book where Book.bookNO = Borrow.bookNO
);

--17.��"������"ͼ��ĵ������10%��
/*
select * from book where classNO in (
	select classNO from BookClass where className='������'
)
*/
update book set price = price*1.1 where classNO in (
	select classNO from BookClass where className='������'
)
/*
select * from book where classNO in (
	select classNO from BookClass where className='������'
)
*/

--18.����������25-35��֮��Ķ��������ĵ�Ӧ�黹��δ�黹��ͼ��,����黹�����޸�Ϊϵͳ��������;
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