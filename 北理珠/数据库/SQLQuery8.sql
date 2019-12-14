--建表
Create Database DBBank
Go
Use DBBank
Create Table tbl_accounts
(account_num varchar(10) primary key,
 account_name varchar(50),
 balance decimal(10,3),
 memory varchar(200)
)
Insert Into tbl_accounts Values('A','东方软件',60000,null)
Insert Into tbl_accounts Values('B','东方软件',30000,null)
Insert Into tbl_accounts Values('C','新天贸易',100000,null)
Select * from tbl_accounts


--开始定义事务
Begin Transaction T_transfer 
Select * from tbl_accounts where account_num='A' And account_name='东方软件'
Update tbl_accounts set balance=balance-10000 where account_num='A' And account_name='东方软件'
Select * from tbl_accounts where account_num='A' And account_name='东方软件'

Select * from tbl_accounts where account_num='B' And account_name='东方软件'
Update tbl_accounts set balance=balance+10000 where account_num='B' And account_name='东方软件'
Select * from tbl_accounts where account_num='B' And account_name='东方软件'

--回滚上面的事务,事务的结束方式只能选择其中的一种,要么回滚,要么提交;
Rollback Transaction T_transfer
 
--提交当前事务,（已经回滚的事务就不能再提交了！）
Commit Transaction T_transfer
--查看事务执行后的结果
select * from tbl_accounts where account_name='东方软件'


--设置隐式事务选项为on
Set Implicit_Transactions On
--事务不需要有显式的开始标志；
Select * from tbl_accounts where account_num='A' And account_name='东方软件'
Update tbl_accounts set balance=balance-10000 where account_num='A' And account_name='东方软件'
Select * from tbl_accounts where account_num='A' And account_name='东方软件'

Select * from tbl_accounts where account_num='B' And account_name='东方软件'
Update tbl_accounts set balance=balance+10000 where account_num='B' And account_name='东方软件'
Select * from tbl_accounts where account_num='B' And account_name='东方软件'

--回滚上面的事务,事务的结束方式只能选择其中的一种,要么回滚,要么提交;
Rollback Transaction 
--提交当前事务,（已经回滚的事务就不能再提交了！）
--Commit Transaction
--查看事务执行后的结果
select * from tbl_accounts where account_name='东方软件'

--（3）创建一个具有保存点的事务，验证保存点的作用；
--开始定义事务
Begin Transaction T_transfer
Select * from tbl_accounts where account_num='A' And account_name='东方软件'
Update tbl_accounts set balance=balance-10000 where account_num='A' And account_name='东方软件'
Select * from tbl_accounts where account_num='A' And account_name='东方软件'

--设置保存点Save_transfer
Save Transaction Save_transfer

Select * from tbl_accounts where account_num='B' And account_name='东方软件'
Update tbl_accounts set balance=balance+10000 where account_num='B' And account_name='东方软件'
Select * from tbl_accounts where account_num='B' And account_name='东方软件'

--回滚到保存点
Rollback Transaction Save_transfer
--查看回滚到保存点后的结果
select * from tbl_accounts where account_name='东方软件'

--回滚整个事务,事务的结束方式只能选择其中的一种,要么回滚,要么提交;
--Rollback Transaction T_transfer 
--提交当前事务,（已经回滚的事务就不能再提交了！）
Commit Transaction T_transfer
--查看事务执行后的结果
select * from tbl_accounts where account_name='东方软件'

--（4）验证什么是自动提交事务；
--第一个事务；单一的一个更新语句，系统自动作为一个事务进行处理；
Update tbl_accounts set balance=balance-10000 where account_num='A' And account_name='东方软件'
Select * from tbl_accounts where account_num='A' And account_name='东方软件'

Select * from tbl_accounts where account_num='B' And account_name='东方软件'
--第二个事务；
Update tbl_accounts set balance=balance+10000 where account_num='B' And account_name='东方软件'
Select * from tbl_accounts where account_num='B' And account_name='东方软件'

--查看事务执行后的结果
select * from tbl_accounts where account_name='东方软件'

--（5）创建一个新的登录，打开两个SSMS，分别用不同的登录名连接到同一服务器上，打开DBBank数据库，分别按顺序运行下面的SQL语句，观察和比较相关的数据结果，回答下面的问题。
CREATE  LOGIN  [cc]  WITH  PASSWORD=N'123';
CREATE  USER   [cc]  FOR  LOGIN  [cc];
grant all privileges on tbl_accounts to cc with grant option;

Use DBBank
Select * from  tbl_accounts

Begin Transaction T_transfer1
Insert Into tbl_accounts Values('D','海大集团',70000,'第一个会话')
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
Insert Into tbl_accounts Values('one','海大集团',70000,'第一个会话')
Select * from  tbl_accounts
Save Transaction Save_t1
Select * from  tbl_accounts

Insert Into tbl_accounts Values('two','远方集团',90000,'第一个会话')
Select * from  tbl_accounts
Save Transaction Save_t2
Select * from  tbl_accounts
	
Insert Into tbl_accounts Values('three','中国远洋',100000,'第一个会话')
Select * from  tbl_accounts

Rollback Transaction Save_t2
Select * from  tbl_accounts

Rollback Transaction Save_t1
Select * from  tbl_accounts

Commit Transaction T_Insert
Select * from  tbl_accounts