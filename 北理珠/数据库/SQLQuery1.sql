
CREATE DATABASE [ScoreDB]
 CONTAINMENT = NONE
 ON  PRIMARY 
( NAME = 'BookDB', FILENAME = 'D:\SQLDatabase\ScoreDB.mdf' , SIZE = 10MB , MAXSIZE = 20MB , FILEGROWTH = 1MB )
 LOG ON 
( NAME = 'BookLog', FILENAME = 'D:\SQLDatabase\ScoreLog.ldf' , SIZE = 8MB , MAXSIZE = 15MB , FILEGROWTH = 1MB )

use ScoreDB;
/* https://blog.csdn.net/printf88/article/details/92839440 */
ALTER DATABASE [ScoreDB] COLLATE Chinese_PRC_CI_AS;
/* Cannot add multiple PRIMARY KEY constraints to table 'SC'. */
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

/*
CREATE TABLE SC
(
	Sno char(7) primary key foreign key(Sno) references Student(Sno),
	Cno char(10) primary key foreign key(Cno) references Course(Cno),
	Grade int check(Grade >= 0 and Grade <= 100),
	XKLB char(4) NULL 
)
*/

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
