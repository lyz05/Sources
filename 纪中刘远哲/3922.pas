const   maxn=1000000;
var	i,j,k,m,n,tmp:longint;
	s,s1,s2:string;
	a,sum,max,last:array[0..maxn] of longint;
function maxx(x,y:longint):longint;
begin
	if x>y then exit(x) else exit(y);
end;
procedure input1(k:longint);
begin
	inc(a[0]);
	a[a[0]]:=k;
	sum[a[0]]:=sum[a[0]-1]+k;
	max[a[0]]:=maxx(max[a[0]-1],sum[a[0]]);
end;
procedure delete1;
begin
	a[a[0]]:=0;
	sum[a[0]]:=0;
	max[a[0]]:=0;
	dec(a[0]);
end;
procedure ll;
begin
	inc(last[0]);
	last[last[0]]:=a[a[0]];
	delete1;
end;
procedure rr;
begin
	input1(last[last[0]]);
	last[last[0]]:=0;
	dec(last[0]);
end;
procedure solve(k:longint);
begin
	writeln(max[k]);
end;
begin
	max[0]:=-maxlongint+100;
	readln(n);
	for i:=1 to n do begin
		readln(s);
		tmp:=pos(' ',s);
		if tmp<>0 then s1:=copy(s,tmp+1,length(s)-tmp);
		val(s1,k);
		case s[1] of
			'I':input1(k);
			'D':delete1;
			'L':ll;
			'R':rr;
			'Q':solve(k);
		end;
	end;
end.
