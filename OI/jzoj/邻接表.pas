program ljb;
type
	node=^link;
	link=record
		qu,g:longint;
		next:node;
	end;
var
	nd:array[1..100000]of node;
	n,m,i,u,v,w:longint;
procedure dfs(wei:longint);
var
	p:node;
begin
	writeln(wei);
	p:=nd[wei];
	while p<>nil do
	begin
		dfs(p^.g);
		p:=p^.next;
	end;
end;
procedure addd(u,v,w:longint); //�����ڽӱ�
var
	p:node;
begin
	new(p);
	p^.g:=v;
	p^.next:=nd[u];
	p^.qu:=w;
	nd[u]:=p;
end;
begin
	readln(n,m); //n:����� m:����
	for i:=1 to m do
	begin
		readln(u,v,w);
		addd(u,v,w);
	end;
	dfs(1);//��1�Žڵ㿪ʼdfs
end.
(Ӧ��û�������......)
(����ͼֻҪ��addd�����з�������newһ��Ϳ�����)
