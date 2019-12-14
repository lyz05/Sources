--�������ݿ�
create database work
go
use work

--��������������ϵģʽ�����ֱ������Ӧ�����ݡ�
--Worker ְ����ְ���ţ����������䣬ְ�񣬹��ʣ����źţ�
--��1��ʹ��SQL���Զ�����������ϵģʽ�����������������Լ�������Ķ��壻
go
create table Worker(
	--��a������ְ����Ϊְ��������룻
	ְ���� varchar(10) primary key,
	--��d��ְ������������Ϊ�գ�
	���� char(10) not null,
	--��c������ְ�������䲻��С��18�꣬���Ҳ��ܳ���60�ꣻ
	���� int constraint w_age check (����>18 and ����<60),
	ְ�� char(15),
	--��e��ְ���Ĺ��ʲ���Ϊ�գ��Ҳ���С��800��
	���� money not null
	constraint w_sa check(����>800),
	���ź� char(50),
	--��b���������������
	foreign key(ְ����) references Worker(ְ����) 
)

--Section�����źţ����ƣ�����������ַ���绰���룩
create table Section (
	-- ��a�����岿�ź�Ϊ���ű������
	���ź� char(10) primary key,
	--��f���������Ʋ���Ϊ���Ҳ����ظ�������Լ����ΪUK_dName��
	���� char(10) not null
	constraint UK_dName unique,
	������ char(10),
	��ַ char(50),
	�绰 char(15),
	--��b���������������
	foreign key(���ź�) references Section(���ź�) 
);

go
--��2��ʹ��SQL���Էֱ����������в���7�м�¼����֤����ĸ���Լ��������

--��c������ְ�������䲻��С��18�꣬���Ҳ��ܳ���60�ꣻ
insert into Worker values('a001003','����',61,'����',5000,'a001');
insert into Worker values('a002004','���',17,'������',4500,'a002');

--��d��ְ������������Ϊ�գ�
insert into Worker values('a002003',null,32,'����',5000,'a002');

--��e��ְ���Ĺ��ʲ���Ϊ�գ��Ҳ���С��800��
insert into Worker values('a002001','�޽�',19,'����Ա',null,'a002');
insert into Worker values('a002002','���',24,'����Ա',700,'a002');

--��f���������Ʋ���Ϊ���Ҳ����ظ�������Լ����ΪUK_dName��
insert into Section values('a001','�г�����','����','����','13750000000');
insert into Section values('a002','Ӫ������','���','����','13750000002');
insert into Section values('a003','Ӫ������','����','����','13750000003');
insert into Section values('a003',null,'���','����','13750000004');

insert into Worker values('a001001','����',20,'�г�Ӫ��Ա',2000,'a001');
insert into Worker values('a001002','���',29,'�г�Ӫ��Ա',2000,'a001');


--��ѯ���ű��ְ���������
select * from Section
select * from Worker

--��3����ְ���������Ϊ����С��16�꣬���Ҳ��ܴ���65�ꣻ
alter table Worker
	drop constraint w_age
alter table Worker 
	add constraint w_age check(����>16 and ����<65)
--��ְ֤�����䲻��С��16�꣬���Ҳ��ܴ���65��
insert into Worker values('a002005','�',15,'������',4500,'a002');
insert into Worker values('a002006','����',66,'������',4500,'a002');


--��4������һ����tbl_Emp_Log(eNO, eSalary, Username, ModiDate)��
--��ְ�����϶����޸ĺͲ������ݵĴ��������������ְ���ź͹����������뵽Emp_log���У�����¼�������û��Ͳ���ʱ�䣻����޸���ְ���Ĺ��ʣ�Ҳ��ְ���ź��޸ĺ�Ĺ����������뵽Emp_log���У�����¼�������û��Ͳ���ʱ�䡣
--�����
create table tbl_Emp_Log(
	id int identity primary key,		--id����
	eNo char(20),						--ְ����
	eSalary money,						--��������
	Username char(20),					--�����û�
	ModiDate Datetime					--����ʱ��
)

--����������ݵĴ�����
go
create trigger insert_Emp on Worker
after insert
as begin 
	insert into tbl_Emp_Log select ְ����, ����, User_name(), getDate() from Inserted;
end
--drop trigger insert_Emp

--��֤������
go
insert into Worker values('a0010011','����',29,'�г�Ӫ��Ա',2000,'a001');
insert into Worker values('a0010010','����',28,'�г�Ӫ��Ա',2000,'a001');

select * from tbl_Emp_Log
--drop table tbl_Emp_Log;

--�����޸Ĺ��ʵĴ�����
go
create trigger update_Emp on Worker
after update
as if update(����)
begin 
	declare @eSeleryOld money,@eSeletyNew money
	select @eSeleryOld=���� from Deleted
	select @eSeletyNew=���� from Inserted
	if (@eSeleryOld<>@eSeletyNew)
		insert into tbl_Emp_Log select ְ����, ����, User_name(), getDate() from Inserted;
end

--drop trigger update_Emp
--��֤������
insert into Worker values('a0010021','����',29,'Ӫ��Ա',3500,'a001');
insert into Worker values('a0010020','����',28,'�г�Ӫ��Ա',4500,'a001');
update Worker set ����=5500 where ְ����='a0010021'
update Worker set ����=8500 where ְ����='a0010020'
select * from tbl_Emp_Log;
select * from Worker;