--����
Create Database DBBank
Go
Use DBBank
Create Table tbl_accounts
(account_num varchar(10) primary key,
 account_name varchar(50),
 balance decimal(10,3),
 memory varchar(200)
)
Insert Into tbl_accounts Values('A','�������',60000,null)
Insert Into tbl_accounts Values('B','�������',30000,null)
Insert Into tbl_accounts Values('C','����ó��',100000,null)
Select * from tbl_accounts


--��ʼ��������
Begin Transaction T_transfer 
Select * from tbl_accounts where account_num='A' And account_name='�������'
Update tbl_accounts set balance=balance-10000 where account_num='A' And account_name='�������'
Select * from tbl_accounts where account_num='A' And account_name='�������'

Select * from tbl_accounts where account_num='B' And account_name='�������'
Update tbl_accounts set balance=balance+10000 where account_num='B' And account_name='�������'
Select * from tbl_accounts where account_num='B' And account_name='�������'

--�ع����������,����Ľ�����ʽֻ��ѡ�����е�һ��,Ҫô�ع�,Ҫô�ύ;
Rollback Transaction T_transfer
 
--�ύ��ǰ����,���Ѿ��ع�������Ͳ������ύ�ˣ���
Commit Transaction T_transfer
--�鿴����ִ�к�Ľ��
select * from tbl_accounts where account_name='�������'


--������ʽ����ѡ��Ϊon
Set Implicit_Transactions On
--������Ҫ����ʽ�Ŀ�ʼ��־��
Select * from tbl_accounts where account_num='A' And account_name='�������'
Update tbl_accounts set balance=balance-10000 where account_num='A' And account_name='�������'
Select * from tbl_accounts where account_num='A' And account_name='�������'

Select * from tbl_accounts where account_num='B' And account_name='�������'
Update tbl_accounts set balance=balance+10000 where account_num='B' And account_name='�������'
Select * from tbl_accounts where account_num='B' And account_name='�������'

--�ع����������,����Ľ�����ʽֻ��ѡ�����е�һ��,Ҫô�ع�,Ҫô�ύ;
Rollback Transaction 
--�ύ��ǰ����,���Ѿ��ع�������Ͳ������ύ�ˣ���
--Commit Transaction
--�鿴����ִ�к�Ľ��
select * from tbl_accounts where account_name='�������'

--��3������һ�����б�����������֤���������ã�
--��ʼ��������
Begin Transaction T_transfer
Select * from tbl_accounts where account_num='A' And account_name='�������'
Update tbl_accounts set balance=balance-10000 where account_num='A' And account_name='�������'
Select * from tbl_accounts where account_num='A' And account_name='�������'

--���ñ����Save_transfer
Save Transaction Save_transfer

Select * from tbl_accounts where account_num='B' And account_name='�������'
Update tbl_accounts set balance=balance+10000 where account_num='B' And account_name='�������'
Select * from tbl_accounts where account_num='B' And account_name='�������'

--�ع��������
Rollback Transaction Save_transfer
--�鿴�ع���������Ľ��
select * from tbl_accounts where account_name='�������'

--�ع���������,����Ľ�����ʽֻ��ѡ�����е�һ��,Ҫô�ع�,Ҫô�ύ;
--Rollback Transaction T_transfer 
--�ύ��ǰ����,���Ѿ��ع�������Ͳ������ύ�ˣ���
Commit Transaction T_transfer
--�鿴����ִ�к�Ľ��
select * from tbl_accounts where account_name='�������'

--��4����֤ʲô���Զ��ύ����
--��һ�����񣻵�һ��һ��������䣬ϵͳ�Զ���Ϊһ��������д���
Update tbl_accounts set balance=balance-10000 where account_num='A' And account_name='�������'
Select * from tbl_accounts where account_num='A' And account_name='�������'

Select * from tbl_accounts where account_num='B' And account_name='�������'
--�ڶ�������
Update tbl_accounts set balance=balance+10000 where account_num='B' And account_name='�������'
Select * from tbl_accounts where account_num='B' And account_name='�������'

--�鿴����ִ�к�Ľ��
select * from tbl_accounts where account_name='�������'

--��5������һ���µĵ�¼��������SSMS���ֱ��ò�ͬ�ĵ�¼�����ӵ�ͬһ�������ϣ���DBBank���ݿ⣬�ֱ�˳�����������SQL��䣬�۲�ͱȽ���ص����ݽ�����ش���������⡣
CREATE  LOGIN  [cc]  WITH  PASSWORD=N'123';
CREATE  USER   [cc]  FOR  LOGIN  [cc];
grant all privileges on tbl_accounts to cc with grant option;

Use DBBank
Select * from  tbl_accounts

Begin Transaction T_transfer1
Insert Into tbl_accounts Values('D','������',70000,'��һ���Ự')
Select * from  tbl_accounts
--Commit Transaction T_transfer1
Select * from  tbl_accounts
Rollback
Select * from  tbl_accounts

Select * from  tbl_accounts with(nolock)
Select * from  tbl_accounts

Use DBBank
Delete from tbl_accounts
Select * from  tbl_accounts

Begin Transaction T_Insert
Insert Into tbl_accounts Values('one','������',70000,'��һ���Ự')
Select * from  tbl_accounts
Save Transaction Save_t1
Select * from  tbl_accounts

Insert Into tbl_accounts Values('two','Զ������',90000,'��һ���Ự')
Select * from  tbl_accounts
Save Transaction Save_t2
Select * from  tbl_accounts
	
Insert Into tbl_accounts Values('three','�й�Զ��',100000,'��һ���Ự')
Select * from  tbl_accounts

Rollback Transaction Save_t2
Select * from  tbl_accounts

Rollback Transaction Save_t1
Select * from  tbl_accounts

Commit Transaction T_Insert
Select * from  tbl_accounts