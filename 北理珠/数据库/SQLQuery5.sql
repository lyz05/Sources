--1.����һ�����ݿ⣬���ݿ�����Ϊexp6��
create database exp6

--2.�����ݿ�������ϴ����µĵ�¼����¼���ֱ�Ϊ�����������¡����ǡ����¡���ƽ�������ȣ���Щ��¼ֻ����public��ɫ�ĳ�Ա��
CREATE  LOGIN  [����]  WITH  PASSWORD=N'123';
CREATE  LOGIN  [����]  WITH  PASSWORD=N'123';
CREATE  LOGIN  [����]  WITH  PASSWORD=N'123';
CREATE  LOGIN  [����]  WITH  PASSWORD=N'123';
CREATE  LOGIN  [��ƽ]  WITH  PASSWORD=N'123';
CREATE  LOGIN  [����]  WITH  PASSWORD=N'123';
--select USER_NAME()
--3.�����洴�������������¡����ǡ����¡���ƽ�������ȵ�¼ӳ��Ϊexp6���ݿ���û����û����͵�¼����ͬ���������ǲ������κ����ݿ��ɫ�ĳ�Ա��
use exp6
go
CREATE  USER   [����]  FOR  LOGIN  [����];
CREATE  USER   [����]  FOR  LOGIN  [����];
CREATE  USER   [����]  FOR  LOGIN  [����];
CREATE  USER   [����]  FOR  LOGIN  [����];
CREATE  USER   [��ƽ]  FOR  LOGIN  [��ƽ];
CREATE  USER   [����]  FOR  LOGIN  [����];
go
--4.��exp6���ݿ��У���������������ϵģʽ�����ֱ������Ӧ�����ݡ�
--    ְ����ְ���ţ����������䣬ְ�񣬹��ʣ����źţ�
--    ���ţ����źţ����ƣ�����������ַ���绰���룩
create table ����
(
	���ź� char(20) primary key,
	���� char(20),
	������ char(20),
	��ַ char(20),
	�绰���� char(20),
)
create table ְ��
(
	ְ���� char(20) primary key,
	���� char(20),
	���� char(20),
	ְ�� char(20),
	���� int,
	���ź� char(20) foreign key(���ź�) references ����(���ź�),
);
insert into ���� values ('007','��ϢԺ','����','´ɽ��·','123456');
insert into ְ�� values('2010081042','����','20','����ίԱ',100000,'007');
insert into ְ�� values('2010081041','����','19','��֧��',100000,'007');


-- 5.����SQL��Grant��Revoke��䣨������ͼ���ƣ����������Ȩ������ȡ���ƹ��ܣ���������Ӧ�İ�ȫ�Բ��ԣ�
--��a���û���������������selectȨ�ޣ�
grant select on ְ�� to ����
grant select on ���� to ����
select * from ְ��
delete from ְ��
--��b���û����¶���������insert��deleteȨ�ޣ�
grant insert, delete on  ְ�� to ����
grant insert, delete on  ���� to ����
insert into ְ�� values('2010081044','����','21','ѧϰίԱ',100000,'007')
select * from ְ��

--��c��ÿ��ְ��ֻ���Լ��ļ�¼��selectȨ�ޣ�
go
create view v_individual
as
select  *  
from  ְ��
where ����= suser_sname()   --suser_sname()���ص�¼�ʺ�
go
grant select on v_individual to public
select * from v_individual

--��d���û����Ƕ�ְ������selectȨ�ޣ��Թ����ֶξ��и���Ȩ�ޣ�
grant select, update(����) on ְ�� to ����
update ְ�� SET ����=150000 WHERE ����='����';
delete from ְ��;

--��e���û����¾����޸���������Ľṹ��Ȩ�ޣ�
grant alter on ְ�� to ����;
grant alter on ���� to ����; 
delete from ְ��;
alter table ���� add ���� int

--��f���û���ƽ���ж�����������Ȩ�ޣ���ѯ�����룬�޸ģ�ɾ�����ݣ��������и������û���Ȩ��Ȩ�ޣ�
grant all privileges on ְ�� to ��ƽ with grant option;
grant all privileges on ���� to ��ƽ with grant option; 
select * from ְ��,����
--��g���û��������д�ÿ������ְ����select��߹��ʣ���͹��ʣ�ƽ�����ʵ�Ȩ�ޣ������ܲ鿴ÿ���˵Ĺ��ʡ�
go
create view ���Ź��� 
as
	select ����.����, max(����) ��߹���, min(����) ��͹���, avg(����) ƽ������
	from ְ��,����
	where ְ��.���ź�=����.���ź�
	group by ְ��.���ź�,����.����
go
grant select on ���Ź��� to ����;
select * from ���Ź���

--6.�����棨a������g����ÿһ��������������û��������Ȩ�ޡ�
--��a���û���������������selectȨ�ޣ�
revoke select on ְ�� from ����
revoke select on ���� from ����
--��b���û����¶���������insert��deleteȨ�ޣ�
revoke insert,delete on ְ�� from ����
revoke insert,delete on ���� from ����
--��c��ÿ��ְ��ֻ���Լ��ļ�¼��selectȨ�ޣ�
revoke insert,delete on  v_individual  from  public
drop view v_individual
--��d���û����Ƕ�ְ������selectȨ�ޣ��Թ����ֶξ��и���Ȩ�ޣ�
revoke select,update on ְ�� from ���� cascade
--��e���û����¾����޸���������Ľṹ��Ȩ�ޣ�
revoke alter on ְ�� from ����
revoke alter on ���� from ����
--��f���û���ƽ���ж�����������Ȩ�ޣ���ѯ�����룬�޸ģ�ɾ�����ݣ��������и������û���Ȩ��Ȩ�ޣ�
revoke all privileges on ְ�� from ��ƽ cascade
revoke all privileges on ���� from ��ƽ cascade
--��g���û��������д�ÿ������ְ����select��߹��ʣ���͹��ʣ�ƽ�����ʵ�Ȩ�ޣ������ܲ鿴ÿ���˵Ĺ��ʡ�
revoke select on ���Ź��� from ����
drop view ���Ź���
