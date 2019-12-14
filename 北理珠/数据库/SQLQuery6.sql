--创建数据库
create database work
go
use work

--创建以下两个关系模式，并分别插入相应的数据。
--Worker 职工（职工号，姓名，年龄，职务，工资，部门号）
--（1）使用SQL语言定义这两个关系模式，并完成以下完整性约束条件的定义；
go
create table Worker(
	--（a）定义职工号为职工表的主码；
	职工号 varchar(10) primary key,
	--（d）职工的姓名不能为空；
	姓名 char(10) not null,
	--（c）定义职工的年龄不能小于18岁，并且不能超过60岁；
	年龄 int constraint w_age check (年龄>18 and 年龄<60),
	职务 char(15),
	--（e）职工的工资不能为空，且不能小于800；
	工资 money not null
	constraint w_sa check(工资>800),
	部门号 char(50),
	--（b）定义参照完整性
	foreign key(职工号) references Worker(职工号) 
)

--Section（部门号，名称，经理名，地址，电话号码）
create table Section (
	-- （a）定义部门号为部门表的主码
	部门号 char(10) primary key,
	--（f）部门名称不能为空且不能重复，定义约束名为UK_dName；
	名称 char(10) not null
	constraint UK_dName unique,
	经理名 char(10),
	地址 char(50),
	电话 char(15),
	--（b）定义参照完整性
	foreign key(部门号) references Section(部门号) 
);

go
--（2）使用SQL语言分别向两个表中插入7行记录，验证上面的各种约束条件；

--（c）定义职工的年龄不能小于18岁，并且不能超过60岁；
insert into Worker values('a001003','李永',61,'经理',5000,'a001');
insert into Worker values('a002004','黄鹂',17,'副经理',4500,'a002');

--（d）职工的姓名不能为空；
insert into Worker values('a002003',null,32,'经理',5000,'a002');

--（e）职工的工资不能为空，且不能小于800；
insert into Worker values('a002001','罗杰',19,'销售员',null,'a002');
insert into Worker values('a002002','李红',24,'销售员',700,'a002');

--（f）部门名称不能为空且不能重复，定义约束名为UK_dName；
insert into Section values('a001','市场部门','李永','北工','13750000000');
insert into Section values('a002','营销部门','李刚','北工','13750000002');
insert into Section values('a003','营销部门','李忠','北工','13750000003');
insert into Section values('a003',null,'李吧','北工','13750000004');

insert into Worker values('a001001','王明',20,'市场营销员',2000,'a001');
insert into Worker values('a001002','李村',29,'市场营销员',2000,'a001');


--查询部门表和职工表的数据
select * from Section
select * from Worker

--（3）将职工的年龄改为不能小于16岁，并且不能大于65岁；
alter table Worker
	drop constraint w_age
alter table Worker 
	add constraint w_age check(年龄>16 and 年龄<65)
--验证职工年龄不能小于16岁，并且不能大于65岁
insert into Worker values('a002005','李芳',15,'副经理',4500,'a002');
insert into Worker values('a002006','李姓',66,'副经理',4500,'a002');


--（4）定义一个表tbl_Emp_Log(eNO, eSalary, Username, ModiDate)；
--在职工表上定义修改和插入数据的触发器，将插入的职工号和工资数据填入到Emp_log表中，并记录操作的用户和插入时间；如果修改了职工的工资，也把职工号和修改后的工资数据填入到Emp_log表中，并记录操作的用户和插入时间。
--定义表
create table tbl_Emp_Log(
	id int identity primary key,		--id主键
	eNo char(20),						--职工号
	eSalary money,						--工资数据
	Username char(20),					--操作用户
	ModiDate Datetime					--操作时间
)

--定义插入数据的触发器
go
create trigger insert_Emp on Worker
after insert
as begin 
	insert into tbl_Emp_Log select 职工号, 工资, User_name(), getDate() from Inserted;
end
--drop trigger insert_Emp

--验证触发器
go
insert into Worker values('a0010011','周涛',29,'市场营销员',2000,'a001');
insert into Worker values('a0010010','霍利',28,'市场营销员',2000,'a001');

select * from tbl_Emp_Log
--drop table tbl_Emp_Log;

--定义修改工资的触发器
go
create trigger update_Emp on Worker
after update
as if update(工资)
begin 
	declare @eSeleryOld money,@eSeletyNew money
	select @eSeleryOld=工资 from Deleted
	select @eSeletyNew=工资 from Inserted
	if (@eSeleryOld<>@eSeletyNew)
		insert into tbl_Emp_Log select 职工号, 工资, User_name(), getDate() from Inserted;
end

--drop trigger update_Emp
--验证触发器
insert into Worker values('a0010021','莉莉',29,'营销员',3500,'a001');
insert into Worker values('a0010020','李丽',28,'市场营销员',4500,'a001');
update Worker set 工资=5500 where 职工号='a0010021'
update Worker set 工资=8500 where 职工号='a0010020'
select * from tbl_Emp_Log;
select * from Worker;