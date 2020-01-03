const	maxn=100001;maxm=400000;
type	node=record
		y,next,val:longint;
	end;
var	i,m,n,tot,tmp,ans,x,y,z:longint;
	e:array[1..maxn] of longint;
	h:array[1..maxm] of node;
	flag:array[1..maxn] of boolean;
	s:array[1..maxn] of longint;
	f:text;
	ss:string;
procedure add(x,y,z:longint);
begin
	inc(tot);
	h[tot].y:=y;
	h[tot].next:=e[x];
	h[tot].val:=z;
	e[x]:=tot;
end;
procedure dfs(dep,x:longint);
var	i:longint;
begin
	if dep=n then 
		flag[1]:=false;
	if dep>n then begin
		if tmp>ans then begin
			ans:=tmp;
			assign(f,ss);
			rewrite(f);
			writeln(f,ans);
			for i:=1 to n do write(f,s[i],' ');
			writeln(f);
			close(f);
		end;
		exit;
	end;
	i:=e[x];
	while i<>0 do begin
		if flag[h[i].y] then begin
			i:=h[i].next;
			continue;
		end;
		inc(tmp,h[i].val);
		flag[h[i].y]:=true;
		s[dep+1]:=h[i].y;
			dfs(dep+1,h[i].y);
		//s[dep+1]:=0;
		flag[h[i].y]:=false;
		dec(tmp,h[i].val);
		i:=h[i].next;
	end;
end;
begin
	assign(input,'hp5.in');reset(input);
	//assign(output,'.out');rewrite(output);

	readln(ss);
	ss:='hp'+ss+'.out';
	readln(n,m);
	for i:=1 to m do begin
		readln(x,y,z);
		add(x,y,z);
	end;
	ans:=0;tmp:=0;
	s[1]:=1;flag[1]:=true;
	dfs(1,1);
end.
