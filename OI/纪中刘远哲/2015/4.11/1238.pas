const	maxn=10000;maxm=100000;mo=1000000000;
type	node=record
		y,next:longint;
		p:boolean;
	end;
var	i,j,k,m,n,tot,x,y:longint;
	e,cnt,ans:array[1..maxn] of longint;
	p,pp:array[1..maxn] of boolean;
	h:array[1..maxm] of node;
	s:array[0..maxn] of longint;
	flag:boolean;
	ss:string;
procedure add(x,y:longint);
begin
	inc(tot);
	h[tot].y:=y;
	h[tot].next:=e[x];
	e[x]:=tot;
	//inc(cnt[y]);
end;
function dfs(dep,t:longint):boolean;
var	i:longint;
begin
	if pp[dep] then exit;
	pp[dep]:=true;
	dfs:=false;
	if dep=t then exit(true);
	i:=e[dep];
	while i<>0 do begin
		h[i].p:=dfs(h[i].y,t);
		if h[i].p then begin
			dfs:=true;
			p[dep]:=true;
		end;
		i:=h[i].next;
	end;
end;
procedure push(x:longint);
begin
	inc(s[0]);
	s[s[0]]:=x;
end;
procedure cut(x:longint);
var	i:longint;
begin
	i:=e[x];
	while i<>0 do begin
		//if not h[i].p then continue;
		dec(cnt[h[i].y]);
		if cnt[h[i].y]=0 then push(h[i].y);
		ans[h[i].y]:=ans[h[i].y]+ans[x];
		if ans[h[i].y]>=mo then begin
			flag:=true;
			ans[h[i].y]:=ans[h[i].y] mod mo;
		end;
		i:=h[i].next;
	end;
end;
function pop:longint;
begin
	pop:=s[s[0]];
	s[s[0]]:=0;
	dec(s[0]);
	if pop=2 then begin
		s[0]:=0;
		exit;
	end;
	cut(pop);
end;
procedure work(x:longint);
var	i:longint;
begin
	i:=e[x];
	while i<>0 do begin
		inc(cnt[h[i].y]);
		i:=h[i].next;
	end;
end;
begin
	assign(input,'1238.in');reset(input);
	//assign(output,'.out');rewrite(output);

	readln(n,m);
	for i:=1 to m do begin
		readln(x,y);
		add(x,y);
	end;
	ans[1]:=1;
	
	dfs(1,2);
	for i:=1 to n do 
		if pp[i] then work(i);
	for i:=1 to n do 
		if pp[i] and (cnt[i]=0) then push(i);
	while s[0]<>0 do pop;
	if ans[2]=0 then writeln('inf') else begin
		if flag then begin
			str(ans[2],ss);
			ss:='000000000'+ss;
			for i:=length(ss)-8 to length(ss) do write(ss[i]);
			writeln;
		end else writeln(ans[2]);
	end;
end.
