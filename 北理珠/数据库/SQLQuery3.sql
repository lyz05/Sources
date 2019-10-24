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
select * from Book;
select classNo,sum(shopNum)
from Book where (classNO < '009') group by classNO;

/* 8��ʼ��ʹ�����ӣ��Ӳ�ѯ���оۺϺ�����*/


--10.��ѯû�н���ͼ������'B2001'��ͷ��ͼ��Ķ��߱�š������Լ�����������ͼ���ͼ�����ơ��������ڣ�ʹ��IN�Ӳ�ѯ����
/*
select *
from Borrow,Reader,Book
where Borrow.readerNO=Reader.readerNO and Book.bookNO = Borrow.bookNO order by Reader.readerNO;
*/
--8.��ѯ����ͼ����ܼ���100Ԫ���ϵĶ��߱�š���������������ͼ����ܼۣ�  
select Reader.readerNO ���߱��,Reader.readerName ��������,sum(price) ����ͼ���ܼ�
from Borrow,Reader,Book
where Borrow.readerNO=Reader.readerNO and Book.bookNO = Borrow.bookNO group by Reader.readerNO,Reader.readerName
having sum(price)>100;

--9.��ѯû�н���Ķ��������͹�����λ(ʹ��IN�Ӳ�ѯ���)��