--1.创建一个数据库，数据库名称为exp6；
create database exp6

--2.在数据库服务器上创建新的登录，登录名分别为：王明、李勇、刘星、张新、周平、杨兰等；这些登录只能是public角色的成员；
CREATE  LOGIN  [李勇]  WITH  PASSWORD=N'123';
CREATE  LOGIN  [王明]  WITH  PASSWORD=N'123';
CREATE  LOGIN  [刘星]  WITH  PASSWORD=N'123';
CREATE  LOGIN  [张新]  WITH  PASSWORD=N'123';
CREATE  LOGIN  [周平]  WITH  PASSWORD=N'123';
CREATE  LOGIN  [杨兰]  WITH  PASSWORD=N'123';
--select USER_NAME()
--3.把上面创建的王明、李勇、刘星、张新、周平、杨兰等登录映射为exp6数据库的用户，用户名和登录名相同，并且他们不属于任何数据库角色的成员。
use exp6
go
CREATE  USER   [李勇]  FOR  LOGIN  [李勇];
CREATE  USER   [王明]  FOR  LOGIN  [王明];
CREATE  USER   [刘星]  FOR  LOGIN  [刘星];
CREATE  USER   [张新]  FOR  LOGIN  [张新];
CREATE  USER   [周平]  FOR  LOGIN  [周平];
CREATE  USER   [杨兰]  FOR  LOGIN  [杨兰];
go
--4.在exp6数据库中，创建以下两个关系模式，并分别插入相应的数据。
--    职工（职工号，姓名，年龄，职务，工资，部门号）
--    部门（部门号，名称，经理名，地址，电话号码）
create table 部门
(
	部门号 char(20) primary key,
	名称 char(20),
	经理名 char(20),
	地址 char(20),
	电话号码 char(20),
)
create table 职工
(
	职工号 char(20) primary key,
	姓名 char(20),
	年龄 char(20),
	职务 char(20),
	工资 int,
	部门号 char(20) foreign key(部门号) references 部门(部门号),
);
insert into 部门 values ('007','信息院','杨兰','麓山南路','123456');
insert into 职工 values('2010081042','王明','20','生活委员',100000,'007');
insert into 职工 values('2010081041','刘星','19','团支书',100000,'007');


-- 5.请用SQL的Grant和Revoke语句（加上视图机制）完成以下授权定义或存取控制功能，并进行相应的安全性测试；
--（a）用户王明对两个表有select权限；
grant select on 职工 to 王明
grant select on 部门 to 王明
select * from 职工
delete from 职工
--（b）用户李勇对两个表有insert和delete权限；
grant insert, delete on  职工 to 李勇
grant insert, delete on  部门 to 李勇
insert into 职工 values('2010081044','李勇','21','学习委员',100000,'007')
select * from 职工

--（c）每个职工只对自己的记录有select权限；
go
create view v_individual
as
select  *  
from  职工
where 姓名= suser_sname()   --suser_sname()返回登录帐号
go
grant select on v_individual to public
select * from v_individual

--（d）用户刘星对职工表有select权限，对工资字段具有更新权限；
grant select, update(工资) on 职工 to 刘星
update 职工 SET 工资=150000 WHERE 姓名='李勇';
delete from 职工;

--（e）用户张新具有修改这两个表的结构的权限；
grant alter on 职工 to 张新;
grant alter on 部门 to 张新; 
delete from 职工;
alter table 部门 add 新列 int

--（f）用户周平具有对两个表所有权限（查询，插入，修改，删除数据），并具有给其他用户授权的权限；
grant all privileges on 职工 to 周平 with grant option;
grant all privileges on 部门 to 周平 with grant option; 
select * from 职工,部门
--（g）用户杨兰具有从每个部门职工中select最高工资，最低工资，平均工资的权限，他不能查看每个人的工资。
go
create view 部门工资 
as
	select 部门.名称, max(工资) 最高工资, min(工资) 最低工资, avg(工资) 平均工资
	from 职工,部门
	where 职工.部门号=部门.部门号
	group by 职工.部门号,部门.名称
go
grant select on 部门工资 to 杨兰;
select * from 部门工资

--6.把上面（a）～（g）的每一种情况，撤销各用户所授予的权限。
--（a）用户王明对两个表有select权限；
revoke select on 职工 from 王明
revoke select on 部门 from 王明
--（b）用户李勇对两个表有insert和delete权限；
revoke insert,delete on 职工 from 李勇
revoke insert,delete on 部门 from 李勇
--（c）每个职工只对自己的记录有select权限；
revoke insert,delete on  v_individual  from  public
drop view v_individual
--（d）用户刘星对职工表有select权限，对工资字段具有更新权限；
revoke select,update on 职工 from 刘星 cascade
--（e）用户张新具有修改这两个表的结构的权限；
revoke alter on 职工 from 张新
revoke alter on 部门 from 张新
--（f）用户周平具有对两个表所有权限（查询，插入，修改，删除数据），并具有给其他用户授权的权限；
revoke all privileges on 职工 from 周平 cascade
revoke all privileges on 部门 from 周平 cascade
--（g）用户杨兰具有从每个部门职工中select最高工资，最低工资，平均工资的权限，他不能查看每个人的工资。
revoke select on 部门工资 from 杨兰
drop view 部门工资
