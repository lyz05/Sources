use DB3;
--��1�����һ����ͼ�����ڼ��û��Ĳ�ѯ��������������������������Ȼ���ӣ�ʹ�������ӣ����Ա���ѧ����Ϳγ̱�����м�¼���������ͼ����������
create view View1 
as 
select Course.Cno,Cname,Ccredit,Semster,Student.Sno,Sname,Ssex,Sage,Sdept from SC 
full join Course on Course.Cno = SC.Cno 
full join Student on Student.Sno = SC.Sno;
select * from View1;

--��2�����һ����ͼ��ʹ���е���������һ�ַ�ʽ��ʾ���û������磺��ѧ��������ת���ɳ�����ݳ��ָ��û�����������ͼ��
create view View2 
as 
select Sno,Sname,Ssex,year(GetDate())-Sage as �������,Sdept from Student;
select * from View2;

--��3�����һ����ͼ���ı���е����������磺��Ӣ������ת��������������
create view View3 
as
select Cno �γ̱��,Cname �γ���,Ccredit ѧ��,Semster ѧ��,Sno ѧ��,Sname ����,Ssex �Ա�,Sage ����,Sdept ѧԺ from View1;
select * from View3;

--��4�����һ����ͼ�����ڱ��еĻ��������ṩ��ȫ������ʵ�����ݵİ�ȫ�Կ��ƣ����紴��һ�����м����ϵѧ������ͼ ����������ͼ��ֻ��ʾѧ�š��������Ա�����ϵ�����У�Ȼ��Ѷ�����ͼ�Ĳ�ѯȨ������ĳЩ�û����Ϳ��Կ�����Щ�û���ѧ����Ϣ������ݷ��ʿ����ˣ�����������ͼ��
create view View4 
as
select Sno ѧ��,Sname ����,Ssex �Ա�,Sdept ����ϵ from Student where Sdept='�����ϵ';
select * from View4;

--��5�����һ����ͼ�����ڸ����µı���û��Ĳ�ѯ�����磺��ѯѧ��ѡ�޿γ̳ɼ����ڸÿγ�ƽ���ֵ�ѡ����Ϣ���г�ѧ�š��γ̺źͳɼ���
-- �����ȴ���һ�������γ̺ź͸ÿγ�ƽ���ֵ���ͼ��Ȼ���ٲ�ѯ��ѧ���ɼ����ڸÿγ�ƽ���ֵ�ѡ�μ�¼��
-- select * from SC where XKLB='ѡ��';
create view View5_1
as 
select Cno,avg(Grade) as avg from SC group by Cno;
create view View5
as
select Sno ѧ��,SC.Cno �γ̺�,Grade �ɼ� from SC,View5_1 where XKLB='ѡ��' and SC.Cno=View5_1.Cno and Grade>avg;

select * from View5_1;
select * from View5;