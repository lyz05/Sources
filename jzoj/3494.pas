const	maxn=3000+2;mo=1000000007;
type	node=record
		val,len,st:longint;
	end;
	arr=array[0..2*maxn] of longint;
var	i,n:longint;
	a:array[1..2*maxn] of node;
	q:array[1..maxn,1..4] of longint;
	id:arr;
	p:array[0..2*maxn] of boolean;
function power(x:int64;y:longint):int64;
begin
	power:=1;
	while y<>0 do begin
		if odd(y) then power:=(power*x) mod mo;
		x:=(x*x) mod mo;
		y:=y>>1;
	end;
end;
procedure qsort(var a1:arr;l,r:longint);
var	m,i,j,t:longint;
begin
	m:=a1[(l+r) div 2];
	i:=l;j:=r;
	repeat
		while a1[i]<m do inc(i);
		while a1[j]>m do dec(j);
		if i<=j then begin
			t:=a1[i];
			a1[i]:=a1[j];
			a1[j]:=t;
			inc(i);dec(j);
		end;
	until i>j;
	if l<j then qsort(a1,l,j);
	if i<r then qsort(a1,i,r);
end;
procedure change(cmd,x,y,w:longint);
var	i:longint;
	flag:boolean;
begin
	flag:=false;
	for i:=1 to id[0]-1 do begin
		if a[i].st=x then flag:=true;
		if flag then begin
			if cmd=0 then a[i].val:=(a[i].val*power(w,a[i].len)) mod mo
			else	a[i].val:=power(a[i].val,w);
		end;
		if a[i].st+a[i].len=y then exit;
	end;
end;
procedure query(x,y:longint);
var	i:longint;
	flag:boolean;
	ans:int64;
begin
	flag:=false;ans:=1;
	for i:=1 to id[0]-1 do begin
		if a[i].st=x then flag:=true;
		if flag then begin
			ans:=(ans*a[i].val) mod mo;
		end;
		if a[i].st+a[i].len=y then break;
	end;
	writeln(ans);
end;
begin
	assign(input,'segment.in');reset(input);
	assign(output,'segment.out');rewrite(output);
	readln(n);
	for i:=1 to n do begin
		read(q[i,1],q[i,2],q[i,3]);
		if q[i,1]<>2 then read(q[i,4]);
		if not p[q[i,2]] then begin
			p[q[i,2]]:=true;
			inc(id[0]);id[id[0]]:=q[i,2];
		end;
		if not p[q[i,3]] then begin
			p[q[i,3]]:=true;
			inc(id[0]);id[id[0]]:=q[i,3];
		end;
	end;
	qsort(id,1,id[0]);
	for i:=1 to id[0]-1 do begin
		a[i].val:=1;
		a[i].len:=id[i+1]-id[i];
		a[i].st:=id[i];
	end;
	for i:=1 to n do begin
		case q[i,1] of
			0,1:change(q[i,1],q[i,2],q[i,3],q[i,4]);
			2:query(q[i,2],q[i,3]);
		end;
	end; 
	close(input);close(output);
end.
