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
procedure addd(u,v,w:longint); //建立邻接表
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
	readln(n,m); //n:结点数 m:边数
	for i:=1 to m do
	begin
		readln(u,v,w);
		addd(u,v,w);
	end;
	dfs(1);//从1号节点开始dfs
end.
(应该没有问题吧......)
(无向图只要在addd过程中反过来再new一遍就可以了)
