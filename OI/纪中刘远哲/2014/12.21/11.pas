const	maxn=100000;
var	i,j,k,m,n,tot,x,y,z,t:longint;
	a:array[1..maxn,1..2] of longint;
	h:array[1..maxn] of longint;
function getfather(x:longint):longint;
begin
	if h[x]=x then getfather:=x else getfather:=getfather(h[x]);
	h[x]:=getfather;
end;
procedure link(x,y:longint);
var	i,j:longint;
begin
	i:=getfather(x);
	j:=getfather(y);
	h[j]:=i;
end;
procedure add(id,len:longint);
var	flag:boolean;
	i,j:longint;
begin
	h[id]:=id;
	for i:=1 to len do begin
		if ((a[i,1]<a[id,1]) and (a[id,1]<a[i,2])) or ((a[i,1]<a[id,2]) and (a[id,2]<a[i,2])) then begin
			link(i,id);
		end;
	end;
end;
function judge(x,y:longint):boolean;
var	i,j:longint;
begin
	i:=getfather(x);
	j:=getfather(y);
	if i=j then exit(true) else exit(false);
end;
begin
	assign(input,'1.in');reset(input);
	//assign(output,'.out');rewrite(output);

	readln(n);
	for i:=1 to n do begin
		readln(x,y,z);
		if x=1 then begin
			inc(t);
			a[t,1]:=y;
			a[t,2]:=z;
			add(t,t-1);
		end else begin
			if judge(y,z) then writeln('YES') else
				writeln('NO');
		end;
	end;
end.
