
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

/*
CREATE TABLE SC
(
	Sno char(7) primary key foreign key(Sno) references Student(Sno),
	Cno char(10) primary key foreign key(Cno) references Course(Cno),
	Grade int check(Grade >= 0 and Grade <= 100),
	XKLB char(4) NULL 
)
*/

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
