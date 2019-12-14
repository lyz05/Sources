Use DBBank
Select * from  tbl_accounts

Select * from  tbl_accounts
Select * from  tbl_accounts
Select * from  tbl_accounts

Begin Tran T_Del2
Delete from tbl_accounts where account_num='C'
Select * from  tbl_accounts
Rollback
Select * from  tbl_accounts

Use DBBank

Select * from tbl_accounts

Select * from  tbl_accounts

Select * from  tbl_accounts

Select * from  tbl_accounts  with(nolock)

Select * from  tbl_accounts

Select * from  tbl_accounts  with(nolock)

Select * from  tbl_accounts

Select * from  tbl_accounts