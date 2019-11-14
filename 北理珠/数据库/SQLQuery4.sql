use DB3;
--（1）设计一个视图，用于简化用户的查询操作，例如把上面的三个表做自然连接，使用外连接，可以保留学生表和课程表的所有记录；把这个视图创建出来；
create view View1 
as 
select Course.Cno,Cname,Ccredit,Semster,Student.Sno,Sname,Ssex,Sage,Sdept from SC 
full join Course on Course.Cno = SC.Cno 
full join Student on Student.Sno = SC.Sno;
select * from View1;

--（2）设计一个视图，使表中的数据以另一种方式显示给用户，例如：将学生的年龄转换成出生年份呈现给用户，创建该视图；
create view View2 
as 
select Sno,Sname,Ssex,year(GetDate())-Sage as 出生年份,Sdept from Student;
select * from View2;

--（3）设计一个视图，改变表中的列名，例如：将英文列名转换成中文列名；
create view View3 
as
select Cno 课程编号,Cname 课程名,Ccredit 学分,Semster 学期,Sno 学号,Sname 姓名,Ssex 性别,Sage 年龄,Sdept 学院 from View1;
select * from View3;

--（4）设计一个视图，对于表中的机密数据提供安全保护，实现数据的安全性控制，例如创建一个所有计算机系学生的视图 ，并且在视图中只显示学号、姓名、性别、所在系这四列，然后把对于视图的查询权限授予某些用户，就可以控制这些用户对学生信息表的数据访问控制了；创建出该视图；
create view View4 
as
select Sno 学号,Sname 姓名,Ssex 性别,Sdept 所在系 from Student where Sdept='计算机系';
select * from View4;

--（5）设计一个视图，用于更清新的表达用户的查询，例如：查询学生选修课程成绩大于该课程平均分的选课信息，列出学号、课程号和成绩；
-- 可以先创建一个包含课程号和该课程平均分的视图，然后再查询出学生成绩大于该课程平均分的选课记录；
-- select * from SC where XKLB='选修';
create view View5_1
as 
select Cno,avg(Grade) as avg from SC group by Cno;
create view View5
as
select Sno 学号,SC.Cno 课程号,Grade 成绩 from SC,View5_1 where XKLB='选修' and SC.Cno=View5_1.Cno and Grade>avg;

select * from View5_1;
select * from View5;