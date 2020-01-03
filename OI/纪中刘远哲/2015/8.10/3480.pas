uses	math;
const	maxn=200000;maxk=1000000;oo=2105376125;
var	i,m,n,ch,num:longint;
	p:array[1..maxn] of boolean;
	a:array[1..maxn] of longint;
	pos:array[1..maxk] of longint;
function add(num:longint):longint;
var	i,k,kk:longint;
begin
	fillchar(a,sizeof(a),125);
	for i:=1 to n do begin
		if p[i] then begin
			a[i]:=0;
		end else 
			if (i-1>0) and (a[i-1]<>oo) then a[i]:=a[i-1]+1;
	end;
	for i:=n downto 1 do begin
		if p[i] then begin
			a[i]:=0;
		end else 
			if (i+1<=n) and (a[i+1]<>oo) then a[i]:=min(a[i],a[i+1]+1);
	end;
	k:=-1;
	for i:=1 to n do begin
		if (a[i]>k) and (not p[i]) then begin
			kk:=i;
			k:=a[i];
		end;
	end;
	p[kk]:=true;
	pos[num]:=kk;
	exit(kk);
end;
procedure del(num:longint);
begin
	p[pos[num]]:=false;
	pos[num]:=0;
end;
begin
	assign(input,'3480.in');reset(input);	
	readln(n,m);
	for i:=1 to m do begin
		read(ch,num);
		if ch=1 then writeln(add(num)) else del(num);
	end;
end.
