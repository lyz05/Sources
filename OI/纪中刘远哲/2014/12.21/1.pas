uses	math;
const	maxn=100000;
var	i,j,k,m,n,st,tot,tmp:longint;
	a:array[1..maxn,1..3] of longint;
	p:array[0..maxn,1..3] of longint;
	h:array[1..maxn] of longint;
	t:array[0..maxn] of longint;
function getfather(x:longint):longint;
begin
	if h[x]=x then getfather:=x else getfather:=getfather(h[x]);
	h[x]:=getfather;
end;
procedure link(x,y,z:longint);
var	i,j:longint;
begin
	i:=getfather(x);
	j:=getfather(y);
	h[j]:=i;
        p[j,3]:=0;
	p[z,1]:=min(a[j,2],p[z,1]);
	p[z,2]:=max(a[j,3],p[z,2]);
end;
procedure add(id,x,y:longint);
var	flag:boolean;
	i,j:longint;
begin
	h[id]:=id;
	flag:=false;
	for i:=1 to tot do begin
                if p[i,3]=0 then continue;
		if ((x<p[i,1]) and (p[i,1]<y)) or ((x<p[i,2]) and (p[i,2]<y)) then begin
			link(p[i,3],id,i);
			flag:=true;
		end;
	end;
	if not flag then begin
		inc(tot);
		p[tot,1]:=x;
		p[tot,2]:=y;
		p[tot,3]:=id;
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
		readln(a[i,1],a[i,2],a[i,3]);
		if a[i,1]=2 then begin
			if judge(t[a[i,2]],t[a[i,3]]) then writeln('YES') else writeln('NO');
		end else begin
			add(i,a[i,2],a[i,3]);
			inc(tmp);
                        t[tmp]:=i;
		end;
	end;
end.
