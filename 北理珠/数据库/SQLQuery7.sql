create database studb
go
use studb
--创建三个表，分别是学生表，课程表和学生选课表；
create table  student  (
  sno char ( 10 ) primary key,
  sname char ( 10 ) not null,
  ssex char (2) check (ssex = '男' or ssex = '女'), 
  sage tinyint check (sage >= 15 and sage <=45),
  sdept char (20)
)

create table  course  (
  cno    char(4)  not null primary key,
  cname  char(20)  not null,
  cpno  int  check (cpno > 0),
  ccredit  tinyint  check (ccredit > 0),  
) 

create table  sc  (
  sno    char(10)  not null foreign key references  student (sno),
  cno   char(4)  not null foreign key references  course (cno),
  grade  tinyint check (grade >= 0 and grade <= 100)
  primary key ( sno, cno ),       
)

--分别向这三个表中插入数据；
insert into student values('2006010101','张扬','男',19,'计算机系')
insert into student values('2006010102','李勇','男',21,'计算机系')
insert into student values('2006010103','王小','男',20,'数学系')
insert into student values('2006010104','赵娣','女',18,'外语系')
insert into student values('2006010105','刘柳','女',19,'外语系')
select * from student

insert into course values('J001','tc',2,32)
insert into course values('J002','vb',2,32)
insert into course values('J003','vc',2,32)
insert into course values('J004','计算机文化基础',2,32)
select * from course

insert into sc values('2006010101','J001',85)
insert into sc values('2006010101','J002',80)
insert into sc values('2006010101','J003',78)
insert into sc values('2006010101','J004',90)
insert into sc values('2006010102','J001',75)
insert into sc values('2006010102','J002',60)
insert into sc values('2006010102','J003',77)
insert into sc values('2006010102','J004',92)
insert into sc values('2006010103','J001',85)
insert into sc values('2006010103','J003',90)
insert into sc values('2006010104','J004',89)
insert into sc values('2006010105','J004',76)
select * from sc

--编写一个存储过程，可以查询指定系的学生的选课信息，列出学号、姓名、所在系、课程名和成绩等内容。调用该存储过程，测试执行结果。
go
create procedure sp_dispsc_sdept
       @sdept varchar(20)
as
select s.sno 学号, s.sname 姓名, s.sdept 所在系, c.cname 课程名, sc.grade 成绩 
from student s
left join sc on s.sno=sc.sno
left join course c on sc.cno=c.cno 
where sdept=@sdept

go
execute  sp_dispsc_sdept  '计算机系'
execute  sp_dispsc_sdept  '外语系'
execute  sp_dispsc_sdept  @sdept='数学系'

--编写一个存储过程，返回指定课程的平均分。调用该存储过程，测试执行结果。
--select avg(grade) from sc,course  where sc.cno=course.cno and course.cname='tc'
go
create procedure sp_avggrade
 @cname varchar(20),
 @avg int output
as
 select @avg=avg(grade) from sc,course where sc.cno=course.cno and course.cname=@cname
 if @avg=0
   print '没有学生选此门课'
 else
   return @avg

go
declare @avggrade int
execute  sp_avggrade 'tc',@avg=@avggrade output
print @avggrade

go
declare @avggrade int
execute  sp_avggrade 'vb',@avg=@avggrade output
print @avggrade

go
declare @avggrade int
execute  sp_avggrade 'vc',@avg=@avggrade output
print @avggrade

go
declare @avggrade int
execute  sp_avggrade '计算机文化基础',@avg=@avggrade output
print @avggrade

--编写一个存储过程，可以查询指定系指定成绩等级的学生的选课信息，列出学号、姓名、所在系、课程名和成绩等内容。调用该存储过程，测试执行结果。
go
create  procedure sp_dispsc_dept_level
        @sdept varchar(20),
		@gradelevel varchar(6)
as
declare @sqltext varchar(200),
		@gradestr varchar(30)
--声明sql文本
set @sqltext='select s.sno, s.sname, s.sdept, c.cname, sc.grade from student s left join sc on s.sno=sc.sno left join course c on sc.cno=c.cno'
--根据等级得到对应的sql追加文本
set @gradestr=case 
	when @gradelevel='优' then 'between 90 and 100'
	when @gradelevel='良' then 'between 80 and 89'
	when @gradelevel='中' then 'between 70 and 79'
	when @gradelevel='及格' then 'between 60 and 69'
	when @gradelevel='不及格' then 'between 0 and 59'
	when @gradelevel is null then 'is null'		--允许为空
	else  'levelerror' 
end
if  @gradestr='levelerror' 
      print '错误：输入的成绩等级不符合要求！'
else
--执行sql语句追加学院与成绩限定的sql文本
       execute(@sqltext+' where sdept='''+@sdept +''' and grade '+@gradestr)


go
execute  sp_dispsc_dept_level  '计算机系','优'
execute  sp_dispsc_dept_level  '外语系',null
execute  sp_dispsc_dept_level  '外语系','中'
execute  sp_dispsc_dept_level  '数学系','良'
