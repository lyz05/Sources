create database studb
go
use studb
--�����������ֱ���ѧ�����γ̱��ѧ��ѡ�α�
create table  student  (
  sno char ( 10 ) primary key,
  sname char ( 10 ) not null,
  ssex char (2) check (ssex = '��' or ssex = 'Ů'), 
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

--�ֱ������������в������ݣ�
insert into student values('2006010101','����','��',19,'�����ϵ')
insert into student values('2006010102','����','��',21,'�����ϵ')
insert into student values('2006010103','��С','��',20,'��ѧϵ')
insert into student values('2006010104','���','Ů',18,'����ϵ')
insert into student values('2006010105','����','Ů',19,'����ϵ')
select * from student

insert into course values('J001','tc',2,32)
insert into course values('J002','vb',2,32)
insert into course values('J003','vc',2,32)
insert into course values('J004','������Ļ�����',2,32)
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

--��дһ���洢���̣����Բ�ѯָ��ϵ��ѧ����ѡ����Ϣ���г�ѧ�š�����������ϵ���γ����ͳɼ������ݡ����øô洢���̣�����ִ�н����
go
create procedure sp_dispsc_sdept
       @sdept varchar(20)
as
select s.sno ѧ��, s.sname ����, s.sdept ����ϵ, c.cname �γ���, sc.grade �ɼ� 
from student s
left join sc on s.sno=sc.sno
left join course c on sc.cno=c.cno 
where sdept=@sdept

go
execute  sp_dispsc_sdept  '�����ϵ'
execute  sp_dispsc_sdept  '����ϵ'
execute  sp_dispsc_sdept  @sdept='��ѧϵ'

--��дһ���洢���̣�����ָ���γ̵�ƽ���֡����øô洢���̣�����ִ�н����
--select avg(grade) from sc,course  where sc.cno=course.cno and course.cname='tc'
go
create procedure sp_avggrade
 @cname varchar(20),
 @avg int output
as
 select @avg=avg(grade) from sc,course where sc.cno=course.cno and course.cname=@cname
 if @avg=0
   print 'û��ѧ��ѡ���ſ�'
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
execute  sp_avggrade '������Ļ�����',@avg=@avggrade output
print @avggrade

--��дһ���洢���̣����Բ�ѯָ��ϵָ���ɼ��ȼ���ѧ����ѡ����Ϣ���г�ѧ�š�����������ϵ���γ����ͳɼ������ݡ����øô洢���̣�����ִ�н����
go
create  procedure sp_dispsc_dept_level
        @sdept varchar(20),
		@gradelevel varchar(6)
as
declare @sqltext varchar(200),
		@gradestr varchar(30)
--����sql�ı�
set @sqltext='select s.sno, s.sname, s.sdept, c.cname, sc.grade from student s left join sc on s.sno=sc.sno left join course c on sc.cno=c.cno'
--���ݵȼ��õ���Ӧ��sql׷���ı�
set @gradestr=case 
	when @gradelevel='��' then 'between 90 and 100'
	when @gradelevel='��' then 'between 80 and 89'
	when @gradelevel='��' then 'between 70 and 79'
	when @gradelevel='����' then 'between 60 and 69'
	when @gradelevel='������' then 'between 0 and 59'
	when @gradelevel is null then 'is null'		--����Ϊ��
	else  'levelerror' 
end
if  @gradestr='levelerror' 
      print '��������ĳɼ��ȼ�������Ҫ��'
else
--ִ��sql���׷��ѧԺ��ɼ��޶���sql�ı�
       execute(@sqltext+' where sdept='''+@sdept +''' and grade '+@gradestr)


go
execute  sp_dispsc_dept_level  '�����ϵ','��'
execute  sp_dispsc_dept_level  '����ϵ',null
execute  sp_dispsc_dept_level  '����ϵ','��'
execute  sp_dispsc_dept_level  '��ѧϵ','��'
