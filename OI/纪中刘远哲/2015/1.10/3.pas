type	node=record
		fa,id,st:longint;
	end;
const	maxn=1000000;
var	i,m,n,x,y,t:longint;
	h:array[1..maxn] of node;
	p:array[1..maxn] of boolean;
procedure swap(var x,y:longint);
var	t:longint;
begin
	t:=x;
	x:=y;
	y:=t;
end;
procedure add(x,y,id:longint);
begin
	if h[x].fa=0 then begin
		h[x].fa:=y;
		h[x].id:=id;
		h[y].fa:=x;
		h[y].id:=id;
		exit;
	end;
	if h[h[x].fa].fa=x then begin
		h[x].fa:=0;
		h[x].id:=0;
		h[y].fa:=x;
		h[y].id:=id;
		//root:=x;
		exit;
	end;
	swap(x,y);
	if h[h[x].fa].fa=x then begin
		h[x].fa:=0;
		h[x].id:=0;
		h[y].fa:=x;
		h[y].id:=id;
		//root:=x;
		exit;
	end else begin
		if h[x].fa=0 then swap(x,y);
		if h[x].fa=0 then writeln('error');
		h[y].fa:=x;
		h[y].id:=id;
	end;
end;
function find(x:longint):longint;
begin
	while (h[x].st=0) and (h[x].fa<>0) do begin
		x:=h[x].fa;
	end;
	if h[x].st=1 then exit(h[x].id);
	if h[x].fa=0 then exit(0);
end;
function getroot(x:longint):longint;
begin
	while (not p[x]) and (x<>0) do begin
		p[x]:=true;
		x:=h[x].fa;
	end;
	exit(x);
end;
procedure color(x,y:longint);
begin
	while x<>y do begin
		h[x].st:=1;
		x:=h[x].fa;
	end;
end;
procedure connect(x,y:longint);
var	r:longint;
begin
	fillchar(p,sizeof(p),false);
	r:=getroot(x);
	r:=getroot(y);
	color(x,r);
	color(y,r);
end;
begin
	//assign(input,'3.in');reset(input);
	//assign(output,'.out');rewrite(output);

	readln(n,m);
	for i:=1 to n-1 do begin
		readln(x,y);
		add(x,y,i);
	end;
	for i:=1 to m do begin
		read(t);
		if t=1 then begin
			read(x);
			writeln(find(x));
		end else begin
			read(x,y);
			connect(x,y);
		end;
	end;
end.
